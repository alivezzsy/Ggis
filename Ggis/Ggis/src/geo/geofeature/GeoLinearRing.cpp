#include"geometry.h"

GeoLinearRing::GeoLinearRing(const GeoLinearRing& rhs)
	: GeoLineString(rhs)
{
}

Geometry* GeoLinearRing::copy() {
	return new GeoLinearRing(*this);
}


bool GeoLinearRing::isClockwise() const
{
	int numPoints = points.size();
	if (numPoints < 3) {
		// ������Ҫ��������ܹ��ɻ�
		return false;
	}

	double sum = 0.0;
	for (int i = 0; i < numPoints; ++i) {
		const GeoRawPoint& p1 = points[i];
		const GeoRawPoint& p2 = points[(i + 1) % numPoints];  // ��һ������
		sum += (p2.x - p1.x) * (p2.y + p1.y);
	}

	return sum > 0.0;  // ������֮�ʹ���0������˳ʱ���
	return true;
}
// force to close the ring
void GeoLinearRing::closeRings()
{
	int nPoints = points.size();
	if (nPoints < 2)
		return;

	if (!utils::isEqual(getX(0), getX(nPoints - 1))
		|| !utils::isEqual(getY(0), getY(nPoints - 1)))
	{
		addPoint(getX(0), getY(0));
	}
}


/* Override */

GeometryType GeoLinearRing::getGeometryType() const
{
	return kLinearRing;
}

const char* GeoLinearRing::getGeometryName() const
{
	return "LINEARRING";
}
