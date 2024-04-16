#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include"Widget\openglwidget.h"
#include"Dialog\ViewLogDialog.h"
#include"Widget\LayersTreeWidget.h"
#include"Widget\StatusBar.h"
#include"Widget\ToolsBar.h"

class Ggis :
	public QMainWindow
{	Q_OBJECT
public:
	Ggis(QWidget* parent = nullptr);
	~Ggis();

public:
	//≥ı ºªØ
	void createWidgets();
	void createMenus();
	void setupLayout();
	void createActions();

public slots:
	void onOpenGeoShapefile();
	void onOpenGeoJsonfile();
	void onShowLogDialog();
	void onDelLog();
private:
	GeoMap*& map;
	//Widget
	LayersTreeWidget* layersTreeWidget;
	openglwidget* OpenGLWidget;
	ViewLogDialog* viewLogDialog;

	//Tool bar
	ToolBar* toolbar;

	//Status Bar
	StatusBar* statusbar;

	//MenuBar
	QMenu* fileMenu;
	QMenu* openFileMenu;
	QMenu* logMenu;

	//Action
	QAction* openJsonAction;
	QAction* openShapfileAction;
	QAction* showLogDialogAction;
	QAction* delLogAction;
};

	