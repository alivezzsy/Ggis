#pragma once

//Feature=geometry+fieldvaluesҪ���༴���ζ�����ֶ�

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
	GeoFeature() {} // Ĭ�Ϲ��캯��
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

	// Selecte��delete
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
	//�ֶε�Ψһ��ʶ
	int nFID = 0;

	//���淶Χ�Լӿ��ȡ����
	GeoExtent extent;

	//һ��Ҫ��ֻ��һ�����ζ���
	Geometry* geom = nullptr;

	/*�ֶζ���
		ÿ��ͼ����ֻ��һ�����塣
		ͼ���е�ÿ��Ҫ��ֻ���涨���ָ�롣*/
	std::vector<GeoFieldDefn*>* fieldDefns;
	
	/*�ֶ�ֵ
		 ��voidָ�����ʽ�洢�����Դ��ֶζ����л�ȡ����*/
	std::vector<void*> fieldValues;

	//VAO��VBO��IBOs
	OpenglFeatureDescriptor* openglFeatureDescriptor = nullptr;

	bool selected = false;
	bool deleted = false;

	// Point's color, LineString's color, Polygon's fill color
	QRgb color = utils::getRandomColor();   // define QRgb unsigned int

	// Polygon's border color. So this is only used in polygon features
	QRgb borderColor = Qt::black;
};

