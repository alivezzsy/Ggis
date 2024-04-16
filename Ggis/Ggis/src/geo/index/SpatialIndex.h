#pragma once
#include "geo\geo_base.hpp"
#include"geo\geofeature\GeoFeature.h"

#include<vector>

class SpatialIndex {
public:
	SpatialIndex(){}
	virtual ~SpatialIndex() {};

	//µ„≤È—Ø
	virtual void queryFeature(double x,double y,double halfEdge,GeoFeature*& featureResult) = 0;

	//∫–≤È—Ø
	virtual void queryFeatures(const GeoExtent& extent, std::vector<GeoFeature*>& featuresResult) = 0;
};