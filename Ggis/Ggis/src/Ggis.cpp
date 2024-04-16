#include "Ggis.h"

#include"utilities\env.h"
#include"utilities\logger.h"
#include"utilities\fileReader.h"
#include "utilities\appEvent.h"

#include <QDebug>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QMessageBox>
#include <QMetaType>
#include <QPushButton>
#include <QStatusBar>
#include <QString>
#include <QVBoxLayout>

Ggis::Ggis(QWidget *parent)
	:QMainWindow(parent), map(Env::map),
	viewLogDialog(new ViewLogDialog())
{
	this->setFocusPolicy(Qt::StrongFocus);
	this->setWindowTitle(u8"数据渲染引擎");

	//在Qt中注册自定义数据类型，以便能够在信号与槽之间传递这些类型的对象
	qRegisterMetaType<GeoFeature>("GeoFeature&");
	qRegisterMetaType<GeoLayer>("GeoLayer");
	qRegisterMetaType<GeoFeatureLayer>("GeoFeatureLayer");
	
	//日志文件
	QString logFilePath = QDir::currentPath() + "/logs";
	QDir dir(logFilePath);
	if (!dir.exists()) {
		dir.mkdir(logFilePath);
	}

	LInfo("Program start");
	Env::map->setName("untitled");

	createMenus();
	createWidgets();
	createActions();
	setupLayout();

	connect(AppEvent::getInstance(), &AppEvent::sigAddShpData, this, &Ggis::onOpenGeoShapefile);
	connect(AppEvent::getInstance(), &AppEvent::sigAddJsonData, this, &Ggis::onOpenGeoJsonfile);
}
Ggis::~Ggis()
{
	if (map)
		delete map;
	if (statusbar)
		delete statusbar;

	LInfo("Program exit");
}

void Ggis::createWidgets()
{
	// layers tree
	layersTreeWidget = new LayersTreeWidget(this);
	//opengl
	OpenGLWidget = new openglwidget(this);
	//status bar
	this->statusBar()->setStyleSheet("QStatusBar::item{border: 0px}");
	statusbar = new StatusBar(this->statusBar());
	//tools bar
	toolbar = new ToolBar(this);
	this->addToolBar(toolbar);
}

void Ggis::createMenus()
{
	fileMenu = menuBar()->addMenu(u8"文件");
	openFileMenu = fileMenu->addMenu(u8"打开");

	logMenu = menuBar()->addMenu(u8"日志");
	 
}

void Ggis::createActions()
{
	//menu: file -> open -> Shapefile
	openShapfileAction =
		new QAction(tr("Shapefile"), this); 

	openFileMenu->addAction(openShapfileAction);

	connect(openShapfileAction, &QAction::triggered, AppEvent::getInstance(),
		&AppEvent::sigAddShpData);

	//menu: file -> open -> Json
	openJsonAction =
		new QAction(tr("Json"), this);

	openFileMenu->addAction(openJsonAction);

	connect(openJsonAction, &QAction::triggered, AppEvent::getInstance(),
		&AppEvent::sigAddJsonData);

	//menu:logs->open
	showLogDialogAction = new QAction((u8"打开日志"), this);
	logMenu->addAction(showLogDialogAction);
	connect(showLogDialogAction, &QAction::triggered, this, &Ggis::onShowLogDialog);

	//menu:logs->delete
	delLogAction = new QAction((u8"清空日志"), this);
	logMenu->addAction(delLogAction);
	connect(delLogAction, &QAction::triggered, this, &Ggis::onDelLog);
}

void Ggis::setupLayout()
{
	QWidget *centerWidget = new QWidget();
	this->setCentralWidget(centerWidget);

	QHBoxLayout *mainLayout = new QHBoxLayout(centerWidget);
	QVBoxLayout *leftLayout = new QVBoxLayout();

	leftLayout->addWidget(layersTreeWidget);
	mainLayout->addLayout(leftLayout);
	mainLayout->addWidget(OpenGLWidget);
	mainLayout->setContentsMargins(11, 11, 11, 11);
	mainLayout->setStretch(0, 0);
	mainLayout->setStretch(1, 3);
	mainLayout->setSpacing(6);
	

}
void Ggis::onOpenGeoShapefile() {
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("Open File"), "", tr("shapefile(*.shp)"), nullptr);

	if (files.isEmpty())
		return;
	AppEvent::getInstance()->onStarAddData();

	for (auto iter = files.begin(); iter != files.end(); ++iter) {
		GeoFeatureLayer *newFeatureLayer = FileReader::readShapefile(*iter, map);
		if (!newFeatureLayer) {
			QString errmsg = "Read and parse shapefile failed: " + *iter;
			QMessageBox::critical(this, "Error", errmsg, QMessageBox::Ok);
			LError(errmsg.toStdString());
			continue;
		}
		layersTreeWidget->onAddNewLayer(newFeatureLayer);
		OpenGLWidget->onSendFeatureLayerToGPU(newFeatureLayer, false);    // not update immediately
	}
	OpenGLWidget->update();
	AppEvent::getInstance()->onEndAddData();

}

void Ggis::onOpenGeoJsonfile()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("Open File"), "", tr("json files(*.json)"), nullptr);

	if (files.isEmpty()) {
		return;
	}
	AppEvent::getInstance()->onStarAddData();
	for (auto iter = files.begin(); iter != files.end(); ++iter) {
		GeoFeatureLayer *newFeatureLayer = FileReader::readGeoJsonUsingGDAL(*iter, map);
		if (!newFeatureLayer) {
			QString errmsg = "Read and parse geoJson failed: " + *iter;
			QMessageBox::critical(this, "Error", errmsg, QMessageBox::Ok);
			LError(errmsg.toStdString());
			continue;
		}
		layersTreeWidget->onAddNewLayer(newFeatureLayer);
		OpenGLWidget->onSendFeatureLayerToGPU(newFeatureLayer, false);    // not update immediately
	}
	OpenGLWidget->update();
	AppEvent::getInstance()->onEndAddData();
}

void Ggis::onShowLogDialog()
{
		viewLogDialog->setFixedSize(800, 300);
		viewLogDialog->setModal(false);
		viewLogDialog->show();
}

void Ggis::onDelLog()
{
	viewLogDialog->delLog();
}
