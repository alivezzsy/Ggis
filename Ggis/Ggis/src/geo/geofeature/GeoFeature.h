#pragma once

//Feature=geometry+fieldvalues要素类即几何对象加字段

#include "geo\geofeature\geometry.h"
#include"geo\geofeature\GeoFieldType.h"
#include"utilities\utility.h"

#include<vector>
#include<Qcolor>

class GeoFeatureLayer;
class OpenglFeatureDescriptor;

class GeoFeature
{
public:
	GeoFeature() {} // 默认构造函数
	GeoFeature(GeoFeatureLayer* layerParent);
	GeoFeature(int nFID, GeoFeatureLayer* layerParent);
	GeoFeature(std::vector<GeoFieldDefn*>* fieldDefnsIn);
	GeoFeature(int nFID, std::vector<GeoFieldDefn*>* fieldDefnsIn);
	GeoFeature(const GeoFeature& rhs, std::vector<GeoFieldDefn*>* fieldDefnsIn);
	~GeoFeature();

	//geometry
	void setGeometry(Geometry* geomIn);
	Geometry* getGeometry() const { return geom; }
	GeometryType getGeometryType() const;
	void offset(double xOffset, double yOffset);
	void rotate(double angle);
	void rotate(double sinAngle, double cosAngle);
	void rotate(double centerX, double centerY, double angle);
	void rotate(double centerX, double centerY, double sinAngle, double cosAngle);

	// Boundary
	// The minimum enclosing rectangle
	void updateExtent() { extent = geom->getExtent(); }
	const GeoExtent& getExtent() const { return extent; }

	//field

	// Init all fields' value before call setField(...)
	void initNewFieldValue();

	// Set field's value
	template<typename T>
	void setField(int idx, T valueIn) {
		initNewFieldValue();
		*(T*)(fieldValues[idx]) = valueIn;
	}

	template<typename T>
	void setField(QString name, T valueIn) {
		setField(getFieldIndexByName(name), valueIn);
	}

	int getFID() const { return nFID; }
	void setFID(int nFIDIn) { nFID = nFIDIn; }

	int getNumFields() const { return (*fieldDefns).size(); }
	QString getFieldName(int idx) const;
	GeoFieldType getFieldType(int idx) const;
	GeoFieldType getFieldType(const QString& name) const;

	bool isFieldExist(const QString& fieldName, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
	bool isFieldExistLike(const QString& fieldName, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
	int getFieldIndexByName(const QString& name) const;

	// Get field's value
	template<typename T>
	bool getField(int idx, T* outValue) const {
		*outValue = *(T*)fieldValues[idx];
		return true;
	}

	template<typename T>
	bool getField(QString name, T* outValue) const {
		return getField(getFieldIndexByName(name), outValue);
	}

	// Selecte、delete
	bool isDeleted() const { return deleted; }
	bool isSelected() const { return selected; }
	void setDeleted(bool b) { deleted = b; }
	void setSelected(bool b) { selected = b; }

	// Color (including point's color, line's color, polygon's fill color
	void setColor(unsigned int colorIn, bool bUpdate = false);
	void setColor(int r, int g, int b, bool bUpdate = false);
	void getColorF(float&r, float &g, float& b);

	// Border color, only for polygon features
	void setBorderColor(int colorIn, bool bUpdate = false);
	void setBorderColor(int r, int g, int b, bool bUpdate = false);
	//void getBorderColorF(float& r, float& g, float& b);

	void setOpenglFeatureDescriptor(OpenglFeatureDescriptor* desc);

	void Draw() const;
	void HighlightDraw() const;

private:
	bool checkFieldName(const QString& name) const;
	void setColor_(float r, float g, float b);
	void setBorderColor_(float r, float g, float b);

private:
	//字段的唯一标识
	int nFID = 0;

	//缓存范围以加快获取操作
	GeoExtent extent;

	//一个要素只有一个几何对象
	Geometry* geom = nullptr;

	/*字段定义
		每个图层中只有一个定义。
		图层中的每个要素只保存定义的指针。*/
	std::vector<GeoFieldDefn*>* fieldDefns;
	
	/*字段值
		 以void指针的形式存储，可以从字段定义中获取类型*/
	std::vector<void*> fieldValues;

	//VAO、VBO、IBOs
	OpenglFeatureDescriptor* openglFeatureDescriptor = nullptr;

	bool selected = false;
	bool deleted = false;

	// Point's color, LineString's color, Polygon's fill color
	QRgb color = utils::getRandomColor();   // define QRgb unsigned int

	// Polygon's border color. So this is only used in polygon features
	QRgb borderColor = Qt::black;
};

