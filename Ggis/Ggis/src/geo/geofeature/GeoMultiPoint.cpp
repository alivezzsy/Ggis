#include "geometry.h"

GeoMultiPoint::GeoMultiPoint(const GeoMultiPoint& rhs)
	: GeoGeometryCollection(rhs)
{
}

Geometry* GeoMultiPoint::copy() {
	return new GeoMultiPoint(*this);
}

GeometryType GeoMultiPoint::getGeometryType() const
{
	return kMultiPoint;
}

const char* GeoMultiPoint::getGeometryName() const
{
	return "MULTIPOINT";
}

