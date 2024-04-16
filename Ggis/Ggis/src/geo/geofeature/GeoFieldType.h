#pragma once

#include<QString>

enum GeoFieldType {
	kFieldInt=0,
	kFieldDouble,
	kFieldText,
	kFieldUnknown
};

class GeoFieldDefn {
public:
	GeoFieldDefn() = default;
	GeoFieldDefn(QString nameIn, int widthIn, GeoFieldType typeIn)
		: width(widthIn), type(typeIn), name(nameIn) {}
	GeoFieldDefn(const GeoFieldDefn& rhs)
		: width(rhs.width), type(rhs.type), name(rhs.name) {}
	~GeoFieldDefn() = default;

	bool NameisSame(const GeoFieldDefn& rhs)
	{
		return name == rhs.name;
	}
	bool operator==(const GeoFieldDefn& rhs)
	{
		return name == rhs.name;
	}

	GeoFieldType getType() const { return type; }
	QString getName() const { return name; }
	int getWidth() const { return width; }

	void setType(GeoFieldType typeIn) { this->type = typeIn; }
	void setWidth(int widthIn) { this->width = widthIn; }
	void setName(QString nameIn) { name = nameIn; }

private:
	int width = 0;
	GeoFieldType type = kFieldUnknown;
	QString name;
};