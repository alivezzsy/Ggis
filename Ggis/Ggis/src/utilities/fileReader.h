#include"geo\map\geomap.h"

class FileReader
{
public:
	static GeoFeatureLayer* readShapefile(QString filepath, GeoMap * map);
	
	static GeoFeatureLayer* readGeoJsonUsingGDAL(QString filepath, GeoMap* map);
};