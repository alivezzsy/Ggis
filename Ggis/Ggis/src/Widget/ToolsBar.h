#pragma once

#include <QToolBar>
#include <QAction>
#include <QLineEdit>
#include <QLabel>

class GeoMap;

class ToolBar : public QToolBar
{
	Q_OBJECT
public:
	ToolBar(QWidget* parent = nullptr);

signals:
	void sigUpdateOpengl();

	public slots:
	void onStartEditing(bool on);

	public slots:
	void onRotate();
	void onCursorNormal();
	void onCursorEditing();
	void onCursorPalm();
	void onZoomChanged();
	void onCursorWhatIsThis();

private:
	void createWidgets();
	void createActions();
	void setupLayout();

private:
	GeoMap*& map;

	/* Widget */
	QLabel* rotate;
	QLabel* zoom;
	QLineEdit* editRotate;
	QLineEdit* editZoom;

	/* Action */
	QAction* cursorNormalAction;
	QAction* cursorEditingAction;
	QAction* cursorPalmAction;
	QAction* cursorWhatIsThisAction;
	QAction* rotateAction;
	QAction* zoomToMapAction;
};