#include "ToolsBar.h"
#include "utilities\appEvent.h"
#include "utilities\env.h"
#include "geo\map\geomap.h"

#include <QRegExpValidator>
#include <QMenu>

ToolBar::ToolBar(QWidget* parent)
	: QToolBar(parent), map(Env::map)
{
	this->setFixedHeight(35);

	createWidgets();
	createActions();
	setupLayout();
	
	QAction* Toolaction = this->toggleViewAction();
	Toolaction->setText(u8"工具栏显/隐");

	connect(AppEvent::getInstance(), &AppEvent::sigStartEditing,
		this, &ToolBar::onStartEditing);
	connect(this, &ToolBar::sigUpdateOpengl,
		AppEvent::getInstance(), &AppEvent::onUpdateOpengl);
	connect(AppEvent::getInstance(), &AppEvent::sigZoomChanged,
		this, &ToolBar::onZoomChanged);
}

void ToolBar::createWidgets() {
	rotate = new QLabel(this);
	rotate->setText(u8"旋转：");
	
	zoom = new QLabel(this);
	zoom->setText(u8"地图缩放比例：");
	editRotate = new QLineEdit(this);
	editRotate->setFixedWidth(60);
	editRotate->setAlignment(Qt::AlignRight);
	// [-360.00, 360.00]
	QRegExp re("^-?(360|[1-2]?\\d?\\d|[1-3]?[0-5]?\\d(\\.\\d{1,2})?)$");
	editRotate->setValidator(new QRegExpValidator(re, editRotate));
	editRotate->setDisabled(true);
	editRotate->setToolTip(u8"旋转角度");
	connect(editRotate, &QLineEdit::returnPressed, this, &ToolBar::onRotate);

	editZoom = new QLineEdit(this);
	editZoom->setFixedWidth(60);
	editZoom->setAlignment(Qt::AlignRight);
	editZoom->setToolTip(u8"地图缩放比例");
	editZoom->setText(QString::number(Env::zoom, 'f', 3)+u8"：1");
	editZoom->setReadOnly(true);
}

void ToolBar::createActions() {
	// cursor type
	// palm
	cursorPalmAction = new QAction(this);
	cursorPalmAction->setText("palm");
	cursorPalmAction->setIcon(QIcon("res/icons/palm.ico"));
	cursorPalmAction->setCheckable(true);
	cursorPalmAction->setDisabled(true);
	connect(cursorPalmAction, &QAction::triggered, this, &ToolBar::onCursorPalm);
	// normal
	cursorNormalAction = new QAction(this);
	cursorNormalAction->setText("normal");
	cursorNormalAction->setCheckable(true);
	cursorNormalAction->setChecked(true);
	cursorNormalAction->setIcon(QIcon("res/icons/normal-arrow.ico"));
	connect(cursorNormalAction, &QAction::triggered, this, &ToolBar::onCursorNormal);
	// editing
	cursorEditingAction = new QAction(this);
	cursorEditingAction->setText("edit");
	cursorEditingAction->setCheckable(true);
	cursorEditingAction->setChecked(false);
	cursorEditingAction->setDisabled(true);
	cursorEditingAction->setIcon(QIcon("res/icons/editing-arrow.ico"));
	connect(cursorEditingAction, &QAction::triggered, this, &ToolBar::onCursorEditing);
	// what is this
	cursorWhatIsThisAction = new QAction(this);
	cursorWhatIsThisAction->setText("WhatIsThis");
	cursorWhatIsThisAction->setIcon(QIcon("res/icons/what-is-this.ico"));
	cursorWhatIsThisAction->setCheckable(true);
	connect(cursorWhatIsThisAction, &QAction::triggered, this, &ToolBar::onCursorWhatIsThis);

	// rotate
	rotateAction = new QAction(this);
	rotateAction->setText("rotate");
	rotateAction->setIcon(QIcon("res/icons/rotate.ico"));
	rotateAction->setDisabled(true);
	connect(rotateAction, &QAction::triggered, this, &ToolBar::onRotate);

	zoomToMapAction = new QAction(this);
	zoomToMapAction->setText("zoomToMap");
	zoomToMapAction->setToolTip(u8"缩放至全图");
	connect(zoomToMapAction, &QAction::triggered, AppEvent::getInstance(),&AppEvent::onZoomToMap);

}

void ToolBar::setupLayout() {
	addSeparator();
	addAction(cursorNormalAction);
	addAction(cursorWhatIsThisAction);
	addAction(cursorPalmAction);
	addAction(cursorEditingAction);
	addSeparator();
	addWidget(rotate);
	addWidget(editRotate);
	addAction(rotateAction);
	addSeparator();
	addWidget(zoom);
	addWidget(editZoom);
	addAction(zoomToMapAction);
}

void ToolBar::onZoomChanged()
{
	editZoom->setText(QString::number(Env::zoom,'f', 3) + u8"：1");
}

void ToolBar::onStartEditing(bool on) {
	if (on) {
		Env::cursorType = Env::CursorType::Editing;
		// Editing
		cursorEditingAction->setEnabled(true);
		cursorEditingAction->setChecked(true);
		// Normal
		cursorNormalAction->setEnabled(false);
		cursorNormalAction->setChecked(false);
		// Palm
		cursorPalmAction->setEnabled(true);
		cursorPalmAction->setChecked(false);
		// What Is This
		//cursorWhatIsThisAction->setChecked(false);
		// rotate
		editRotate->setEnabled(true);
		rotateAction->setEnabled(true);
	}
	else {
		cursorNormalAction->setEnabled(true);
		cursorEditingAction->setEnabled(false);
		cursorPalmAction->setEnabled(false);
		editRotate->setEnabled(false);
		rotateAction->setEnabled(false);
		if (cursorEditingAction->isChecked()) {
			Env::cursorType = Env::CursorType::Normal;
			cursorEditingAction->setChecked(false);
			cursorNormalAction->setChecked(true);
		}
	}
}

void ToolBar::onCursorNormal() {
	if (!cursorNormalAction->isChecked()) {
		if (Env::cursorType == Env::CursorType::Normal) {
			cursorNormalAction->setChecked(true);
		}
	}
	else {
		Env::cursorType = Env::CursorType::Normal;
		cursorPalmAction->setChecked(false);
		cursorEditingAction->setChecked(false);
		cursorWhatIsThisAction->setChecked(false);
	}
}

void ToolBar::onCursorEditing() {
	if (!cursorEditingAction->isChecked()) {
		if (Env::cursorType == Env::CursorType::Editing) {
			cursorEditingAction->setChecked(true);
		}
	}
	else {
		Env::cursorType = Env::CursorType::Editing;
		cursorNormalAction->setChecked(false);
		cursorPalmAction->setChecked(false);
		cursorWhatIsThisAction->setChecked(false);
	}
}

void ToolBar::onCursorPalm() {
	if (!cursorPalmAction->isChecked()) {
		if (Env::cursorType == Env::CursorType::Palm) {
			cursorPalmAction->setChecked(true);
		}
	}
	else {
		Env::cursorType = Env::CursorType::Palm;
		cursorNormalAction->setChecked(false);
		cursorEditingAction->setChecked(false);
		cursorWhatIsThisAction->setChecked(false);
	}
}

void ToolBar::onCursorWhatIsThis() {
	if (!cursorWhatIsThisAction->isChecked()) {
		if (Env::cursorType == Env::CursorType::WhatIsThis) {
			cursorWhatIsThisAction->setChecked(true);
		}
	}
	else {
		Env::cursorType = Env::CursorType::WhatIsThis;
		cursorNormalAction->setChecked(false);
		cursorPalmAction->setChecked(false);
		cursorEditingAction->setChecked(false);
	}
}


void ToolBar::onRotate() {
	if (editRotate->text().isEmpty())
		return;
	double angle = editRotate->text().toDouble();
	std::map<GeoFeatureLayer*, std::vector<GeoFeature*>> selectedFeatures;
	map->getAllSelectedFeatures(selectedFeatures);
	Env::opList.addRotateOperation(selectedFeatures, angle)->operate();
	emit sigUpdateOpengl();
}