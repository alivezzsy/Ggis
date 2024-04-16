#include "StatusBar.h"
#include "utilities\appEvent.h"

#include <Qstring>

StatusBar::StatusBar(QStatusBar *statusBarIn)
	: statusBar(statusBarIn) {
	createWidgets();
	setupLayout();
	setUnit(kDegree);
	onUpdateCoord(0.0, 0.0);
	connect(AppEvent::getInstance(), &AppEvent::sigUpdateCoord,
		this, &StatusBar::onUpdateCoord);
	connect(AppEvent::getInstance(), &AppEvent::sigStarAddData,
		this, &StatusBar::onShowMsg);
	connect(AppEvent::getInstance(), &AppEvent::sigEndAddData,
		this, &StatusBar::onClearMsg);
}

StatusBar::~StatusBar() {}

void StatusBar::setUnit(CoordUint unitIn) {
	switch (unitIn) {
	case kDegree:
		labelUnit->setText(u8"��λ����");
		break;
	case kMeter:
		break;
	case kKiloMeter:
		break;
	default:
		break;
	}

	unit = unitIn;
}
// show current coordinate of mouse cursor's position
void StatusBar::onUpdateCoord(double x, double y) {
	switch (unit) {
	case kDegree: {
		QString coordText = QString(u8"������%1 ��γ��%2").arg(x, 8, 'f', 5).arg(y, 8, 'f', 5);
		labelCoord->setText(coordText);
		break;
	}
	case kMeter:
		break;
	case kKiloMeter:
		break;
	default:
		break;
	}
}

// show message for timeMs milliseconds in left area
void StatusBar::onShowMsg()
{
	statusBar->showMessage(u8"���ݼ�����...");
}

void StatusBar::onClearMsg()
{
	statusBar->clearMessage();
}

void StatusBar::createWidgets() {
	labelCoord = new QLabel();
	labelUnit = new QLabel();
}

void StatusBar::setupLayout() {
	this->statusBar->addPermanentWidget(labelCoord);
	this->statusBar->addPermanentWidget(labelUnit);
}
