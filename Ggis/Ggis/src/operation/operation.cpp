#include "operation.h"
#include "utilities\utility.h"
#include "utilities\appEvent.h"

#include <cmath>

Operation::~Operation() {

}

//Delete
OperationDelete::OperationDelete() {
	connect(this, &OperationDelete::sigDeleteFeatures,
		AppEvent::getInstance(), &AppEvent::onDeleteFeatures);
}

void OperationDelete::operate() {
	for (auto& f : features) {
		f.first->deleteFeatures(f.second, true);    // soft delete
	}
	emit sigDeleteFeatures(true);
}

void OperationDelete::undo() {
	for (auto& f : features) {
		f.first->clearDeleteFlags(f.second);
	}
	emit sigDeleteFeatures(true);
}

//Move
void OperationMove::operate() {
	for (auto& f1 : features) {
		for (auto& f2 : f1.second) {
			f2->offset(xOffset, yOffset);
		}
		f1.first->updateExtent();
		f1.first->createGridIndex();
	}
}

void OperationMove::undo() {
	for (auto& f1 : features) {
		for (auto& f2 : f1.second) {
			f2->offset(-xOffset, -yOffset);
		}
		f1.first->updateExtent();
		f1.first->createGridIndex();
	}
}

//Rotate
OperationRotate::OperationRotate() {
	connect(this, &OperationRotate::sigSendFeatureToGPU,
		AppEvent::getInstance(), &AppEvent::onSendFeatureToGPU);
}


void OperationRotate::operate() {
	double sinAngle = sin(angle * PI / 180.0);
	double cosAngle = cos(angle * PI / 180.0);
	for (auto& f1 : features) {
		for (auto& f2 : f1.second) {
			// rotate
			GeoRawPoint& central = centrals[f2];
			GeoRawPoint tmp = f2->getExtent().center();
			f2->rotate(central.x, central.y, sinAngle, cosAngle);
			// resend data to GPU
			emit sigSendFeatureToGPU(f2);
		}
		f1.first->updateExtent();
		f1.first->createGridIndex();
	}
}

void OperationRotate::undo() {
	double sinAngle = sin(angle * PI / -180.0);
	double cosAngle = cos(angle * PI / -180.0);
	for (auto& f1 : features) {
		for (auto& f2 : f1.second) {
			// rotate
			GeoRawPoint& central = centrals[f2];
			f2->rotate(central.x, central.y, sinAngle, cosAngle);
			// resend data to GPU
			emit sigSendFeatureToGPU(f2);
		}
	}
}