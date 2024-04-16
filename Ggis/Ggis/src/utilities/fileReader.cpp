#include"fileReader.h"

#include"utilities/logger.h"
#include"utilities/geo_convert.h"

#include<gdal\gdal_frmts.h>
#include<gdal\gdal_priv.h>
#include<gdal\gdal.h>

GeoFeatureLayer* FileReader::readShapefile(QString filepath, GeoMap* map)
{
	QByteArray bytes = filepath.toLocal8Bit();
	const char* path = bytes.data();
	GDALAllRegister();
	GDALDataset* poDS = nullptr;
	CPLSetConfigOption("GDAL_FILENAME_IS_UTF8", "NO");
	CPLSetConfigOption("SHAPE_ENCODING", "");
	poDS = (GDALDataset*)GDALOpenEx(path, GDAL_OF_VECTOR, nullptr, nullptr, nullptr);
	if (!poDS) {
		LError("Open shapefile:{0} error", path);
		return nullptr;
	}

	if (!convertGDALDataset(poDS, map)) {
		LError("Read shapefile:{0} error", path);
		GDALClose(poDS);
		return nullptr;
	}

	GDALClose(poDS);
	return (*(map->end() - 1))->toFeatureLayer();
}

GeoFeatureLayer * FileReader::readGeoJsonUsingGDAL(QString filepath, GeoMap * map)
{
	QByteArray bytes = filepath.toLocal8Bit();
	const char* path = bytes.data();
	GDALAllRegister();
	CPLSetConfigOption("GDAL_FILENAME_IS_UTF8", "NO");
	CPLSetConfigOption("SHAPE_ENCODING", "");
	GDALDataset* poDS = nullptr;
	poDS = (GDALDataset*)GDALOpenEx(path, GDAL_OF_VECTOR, nullptr, nullptr, nullptr);
	if (!poDS) {
		LError("Open geojson:{0} error", path);
		return nullptr;
	}

	// Convert GDALDataset to GeoMap
	if (!convertGDALDataset(poDS, map)) {
		LError("Read geojson:{0} error", path);
		GDALClose(poDS);
		return nullptr;
	}

	GDALClose(poDS);

	return (*(map->end() - 1))->toFeatureLayer();
}
