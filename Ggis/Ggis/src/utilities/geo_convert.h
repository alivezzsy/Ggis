#include<gdal\ogrsf_frmts.h>

#include"geo\geofeature\geometry.h"
#include"geo\geofeature\GeoFieldType.h"

class GeoMap;
class GeoFeatureLayer;
class GeoFeature;
class GeoGeometry;
class GeoPoint;
class GeoPolygon;
class GeoLineString;
class GeoMultiPoint;
class GeoMultiPolygon;
class GeoMultiLineString;

// Geometry Type
GeometryType convertOGRwkbGeometryType(OGRwkbGeometryType type);
GeoFieldType convertOGRFieldType(OGRFieldType type);

// GDALDataset -> GeoMap
bool convertGDALDataset(GDALDataset* poDsIn, GeoMap* geoMapOut);

// OGRLayer -> GeoFeatureLayer
bool convertOGRLayer(OGRLayer* poLayer, GeoFeatureLayer* geoLayerOut);

// OGRFeature -> GeoFeature
bool convertOGRFeature(OGRFeature* poFeatureIn, GeoFeature* geoFeatureOut);

// OGRGeometry ->GeoGeometry
bool convertOGRPoint(OGRPoint* poPointIn, GeoPoint* geoPointOut);
bool convertOGRLineString(OGRLineString* poLineStringIn, GeoLineString* geoLineStringOut);
bool convertOGRPolygon(OGRPolygon* poPolygonIn, GeoPolygon* geoPolygonOut);
bool convertOGRMultiPoint(OGRMultiPoint* poMultiPointIn, GeoMultiPoint* geoMultiPointOut);
bool convertOGRMultiPolygon(OGRMultiPolygon* poMultipolygonIn, GeoMultiPolygon* geoMultiPolygonOut);
bool convertOGRMultiLineString(OGRMultiLineString* poMultiLineStringIn, GeoMultiLineString* geoMultiLineStringOut);
