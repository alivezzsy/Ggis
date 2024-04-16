#pragma once

#include "geo/geo_base.hpp"

#include <QString>


class GeoMapProperty {
public:
	GeoMapProperty() = default;
	~GeoMapProperty() = default;

public:
	QString name = "untitled";
	GeoExtent extent;
};