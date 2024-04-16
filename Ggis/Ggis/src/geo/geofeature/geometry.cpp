#include "geometry.h"



Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}
void Geometry::rotate(double centerX, double centerY, double angle) {
	rotate(centerX, centerY, sin(angle * PI / 180.0), cos(angle * PI / 180.0));
}

void Geometry::rotate(double sinAngle, double cosAngle) {
	GeoExtent extent = getExtent();
	rotate(extent.centerX(), extent.centerY(), sinAngle, cosAngle);
}

void Geometry::rotate(double angle) {
	GeoExtent extent = getExtent();
	rotate(extent.centerX(), extent.centerY(), angle);
}