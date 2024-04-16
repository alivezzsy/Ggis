#pragma once

#include<vector>

#include "geo/geo_base.hpp"
#include "utilities/utility.h"

class GeoPoint;//点
class GeoPolygon;//多边形
class GeoLineString;//线串
class GeoLinearRing;//线环
class GeoMultiPoint;//多点集合
class GeoMultiPolygon;//多边形集合
class GeoMultiLineString;//多线串集合

enum GeometryType {
	kPoint					= 0,
	kPolygon				= 1,
	kLineString				= 2,
	kLinearRing				= 3,
	kMultiPoint				= 4,
	kMultiPolygon			= 5,
	kMultiLineString		= 6,
	kGeometryCollection		= 7,
	kGeometryTypeUnknown	= 8
};

class Geometry {
public:
	Geometry();
	virtual ~Geometry();

	virtual Geometry* copy() = 0;    // deep copy

	virtual GeometryType getGeometryType() const = 0;
	virtual const char* getGeometryName() const = 0;
	virtual int getNumPoints() const = 0;
	virtual GeoExtent getExtent() const = 0;
	virtual bool isEmpty() const = 0;
	virtual void swapXY() = 0;
	virtual void offset(double xOffset, double yOffset) = 0;
	virtual void rotate(double centerX, double centerY, double sinAngle, double cosAngle) = 0;

	void rotate(double centerX, double centerY, double angle);
	void rotate(double sinAngle, double cosAngle);
	void rotate(double angle);

	/* cast to children class */
	inline GeoPoint* toPoint() { return utils::down_cast<GeoPoint*>(this); }
	inline GeoLineString* toLineString() { return utils::down_cast<GeoLineString*>(this); }
	inline GeoLinearRing* toLinearRing() { return utils::down_cast<GeoLinearRing*>(this); }
	inline GeoPolygon* toPolygon() { return utils::down_cast<GeoPolygon*>(this); }
	inline GeoMultiPoint* toMultiPoint() { return utils::down_cast<GeoMultiPoint*>(this); }
	inline GeoMultiLineString* toMultiLineString() { return utils::down_cast<GeoMultiLineString*>(this); }
	inline GeoMultiPolygon* toMultiPolygon() { return utils::down_cast<GeoMultiPolygon*>(this); }
};

class GeoPoint :public Geometry {
public:
	GeoPoint();
	GeoPoint(double xx, double yy);
	GeoPoint(const GeoPoint& rhs) = default;
	GeoPoint& operator=(const GeoPoint& rhs) = delete;
	~GeoPoint() {}

	GeoRawPoint getXY() const { return{ x, y }; }
	double getX() const { return x; }
	double getY() const { return y; }

	void setXY(double xx, double yy) { x = xx; y = yy; }
	void setX(double xx) { x = xx; }
	void setY(double yy) { y = yy; }

	bool operator==(const GeoPoint& rhs)
	{
		return utils::isEqual(x, rhs.x) && utils::isEqual(y, rhs.y);
	}

	/* override */
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
	virtual int getNumPoints() const override;
	virtual GeoExtent getExtent() const override;
	virtual bool isEmpty() const override;
	virtual void swapXY() override;
	virtual void offset(double xOffset, double yOffset) override;
	virtual void rotate(double /*centerX*/, double /*centerY*/,
		double /*sinAngle*/, double /*cosAngle*/) override {}

private:
	double x;
	double y;
};

class GeoLineString :public Geometry {
public:
	GeoLineString() = default;
	GeoLineString(const GeoLineString& rhs);
	GeoLineString& operator=(const GeoLineString&) = delete;
	virtual ~GeoLineString() = default;

	//迭代器
	std::vector<GeoRawPoint>::iterator begin()
	{
		return points.begin();
	}
	std::vector<GeoRawPoint>::iterator end()
	{
		return points.end();
	}

	GeoRawPoint& operator[](int idx)
	{
		return points[idx];
	}
	const GeoRawPoint& operator[](int idx) const
	{
		return points[idx];
	}
	GeoRawPoint getXY(int idx) const { return{ points[idx].x, points[idx].y }; }
	double getX(int idx) const { return points[idx].x; }
	double getY(int idx) const { return points[idx].y; }
	void  getPoint(int idx, GeoPoint* point) const;
	void  getRawPoint(int idx, GeoRawPoint* rawPoint) const;
	// get the address of the first point's x-coord
	double* getRawData();

	// set point's coordinate
	void setPoint(int idx, double xx, double yy);
	void setPoint(int idx, GeoPoint* point);

	void removePoint(int idx);

	void addPoint(const GeoRawPoint& rawPoint);
	void addPoint(double xx, double yy);

	// reserve memory to store points
	void reserveNumPoints(int count);

	// adjust memory to fit the number of points
	void adjustToFit() { points.shrink_to_fit(); }
	
	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
	virtual GeoExtent getExtent() const override;
	virtual int getNumPoints() const override;
	virtual bool isEmpty() const override;
	virtual void swapXY() override;
	virtual void offset(double xOffset, double yOffset) override;
	virtual void rotate(double centerX, double centerY, double sinAngle, double cosAngle) override;

protected:
	std::vector<GeoRawPoint>points;
};

class GeoLinearRing :public GeoLineString {
public:
	GeoLinearRing() = default;
	GeoLinearRing(const GeoLinearRing&);
	GeoLinearRing& operator=(const GeoLinearRing&) = delete;
	virtual ~GeoLinearRing() = default;

public:
	bool isClockwise() const;//线环是顺时针
	void closeRings();
	inline GeoLineString* toLineString() { return this; }

	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;	
};

//1 exterior ring + some interior rings
class GeoPolygon :public Geometry {
public:
	GeoPolygon() = default;
	GeoPolygon(const GeoPolygon& rhs);
	GeoPolygon& operator=(const GeoPolygon& rhs) = delete;
	virtual ~GeoPolygon();

	void reserveInteriorRingsCount(int size);
	int getInteriorRingsCount() const { return rings.size() - 1; }
	GeoLinearRing* getExteriorRing() const;			//外环
	GeoLinearRing* getInteriorRing(int idx) const;	//内环

													// get the pointer(address) of the first point's x-coord
	void getRawData(double** rawData) const;

	void setExteriorRing(GeoLinearRing* ring);
	void addInteriorRing(GeoLinearRing* ring);
	void removeInteriorRing(int idx);

	void adjustToFit() { rings.shrink_to_fit(); }//调整内存以适应多边形的大小

	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
	virtual GeoExtent getExtent() const override;
	virtual int getNumPoints() const override;
	virtual bool isEmpty() const override;
	virtual void swapXY() override;
	virtual void offset(double xOffset, double yOffset) override;
	virtual void rotate(double centerX, double centerY, double sinAngle, double cosAngle) override;

private:
	// rings[0]: exterior ring
	// rings[n]: interior ring(n >= 0)
	std::vector<GeoLinearRing*> rings;
};

class GeoGeometryCollection :public Geometry {
public:
	GeoGeometryCollection() = default;
	GeoGeometryCollection(const GeoGeometryCollection& rhs);
	GeoGeometryCollection& operator=(const GeoGeometryCollection&) = delete;
	virtual ~GeoGeometryCollection();

	std::vector<Geometry*>::iterator begin()
	{
		return geoms.begin();
	}
	std::vector<Geometry*>::iterator end()
	{
		return geoms.end();
	}

	Geometry* getGeometry(int idx) const { return geoms[idx]; }
	int getNumGeometries() const { return geoms.size(); }

	void addGeometry(Geometry* geom);
	void removeGeometry(int idx);

	void reserveNumGeoms(int idx) { geoms.reserve(idx); }
	void adjustToFit() { geoms.shrink_to_fit(); }

	/* override */
public:
	virtual Geometry* copy() override = 0;
	virtual GeometryType getGeometryType() const override = 0;
	virtual const char* getGeometryName() const override = 0;
	virtual GeoExtent getExtent() const override;
	virtual int getNumPoints() const override;
	virtual bool isEmpty() const override;
	virtual void swapXY() override;
	virtual void offset(double xOffset, double yOffset) override;
	virtual void rotate(double centerX, double centerY, double sinAngle, double cosAngle) override;

protected:
	std::vector<Geometry*> geoms;
};

class GeoMultiPoint : public GeoGeometryCollection {
public:
	GeoMultiPoint() = default;
	GeoMultiPoint(const GeoMultiPoint&);
	GeoMultiPoint& operator=(const GeoMultiPoint&) = delete;
	~GeoMultiPoint() = default;

	GeoPoint* getPoint(int idx) const { return geoms[idx]->toPoint(); }
	void addPoint(GeoPoint* point) { addGeometry(point); }

	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
};

class GeoMultiLineString : public GeoGeometryCollection {
public:
	GeoMultiLineString() = default;
	GeoMultiLineString(const GeoMultiLineString& rhs);
	GeoMultiLineString& operator=(const GeoMultiLineString&) = delete;
	virtual ~GeoMultiLineString() = default;

public:
	GeoLineString* getLineString(int idx) const
	{
		return geoms[idx]->toLineString();
	}
	void addLineString(GeoLineString* lineString)
	{
		addGeometry(lineString);
	}

	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
};

class GeoMultiPolygon : public GeoGeometryCollection {
public:
	GeoMultiPolygon() = default;
	GeoMultiPolygon(const GeoMultiPolygon& rhs);
	GeoMultiPolygon& operator=(const GeoMultiPolygon&) = delete;
	~GeoMultiPolygon() = default;

public:
	GeoPolygon* getPolygon(int idx) const { return geoms[idx]->toPolygon(); }
	int getNumLinearRings() const;
	void addPolygon(GeoPolygon* polygon) { addGeometry(polygon); }

	/* override */
public:
	virtual Geometry* copy() override;
	virtual GeometryType getGeometryType() const override;
	virtual const char* getGeometryName() const override;
};