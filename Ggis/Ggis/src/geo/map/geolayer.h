#pragma once

#include"geo/geofeature/GeoFeature.h"
#include"geo/map/geoFeatureLayerProperty.h"
#include "geo/index/gridindex.h"

#include<vector>
#include<QStringList>

class GeoFeatureLayer;

enum LayerType
{
	kRasterLayer		=0,
	kFeatureLayer		=1,
	kUndefined			=2
};
//ͼ�����
class GeoLayer {
public:
	GeoLayer(){}
	virtual ~GeoLayer();
	/*�ڻ����н�������������Ϊ�麯������Ҫԭ����Ϊ��ȷ����ͨ������ָ��ɾ�����������ʱ��ȷ�ص�������������
	��������������¶�����������������������������������麯������ôͨ������ָ��ɾ�����������ʱ��
	ֻ����û��������������������������������������������ܵ�����Դй©��δ�������Ϊ��*/	

	virtual GeoLayer* copy() { return nullptr; }

	virtual LayerType getLayerType() const { return kUndefined; }
	virtual GeoExtent getExtent() const { return GeoExtent(); }
	virtual QString getName() const { return ""; }
	virtual int getLID() const { return -1; }
	virtual bool isVisible() const { return true; }

	virtual void setName(const QString& /*name*/) {}
	virtual void setLID(int /*nLID*/) {}
	virtual void setExtent(const GeoExtent& /*extent*/) {}
	virtual void setVisible(bool /*visible*/) {}

	virtual void Draw() const {}

	inline GeoFeatureLayer* toFeatureLayer() { return utils::down_cast<GeoFeatureLayer*>(this); }

};

class GeoFeatureLayer :public GeoLayer {
public:
	GeoFeatureLayer();
	GeoFeatureLayer(int nLID);
	GeoFeatureLayer(int nLID, GeometryType type);
	GeoFeatureLayer(const GeoFeatureLayer& rhs);
	virtual ~GeoFeatureLayer();

	// Deep copy
	virtual GeoLayer* copy() override;

	// Draw
	virtual void Draw() const override;

	/******************************
	**  Feature�������Ҫ��
	*****************************/
	bool isEmpty() const { return features.empty(); }
	void reserveFeatureCount(int count) { features.reserve(count); }
	int getFeatureCount() const { return features.size(); }
	GeoFeature* getFeatureByFID(int nFID) const;
	GeoFeature* getFeature(int idx) const { return features[idx]; }
	GeometryType getGeometryType() const { return properties.getGeometryType(); }

	void setGeometryType(GeometryType typeIn) { properties.setGeometryType(typeIn); }
	bool addFeature(GeoFeature* feature);

	template<typename T>
	GeoFeature* getFeatureByFieldValue(int fieldIndex, T value) {
		if (fieldIndex < fieldDefns->size()) {
			int featureCount = features.size();
			for (int i = 0; i < featureCount; ++i) {
				T valueF;
				features[i]->getField(fieldIndex, &valueF);
				if (valueF == value)
					return features[i];
			}
		}
		return nullptr;
	}

	std::vector<GeoFeature*>::iterator begin() { return features.begin(); }
	std::vector<GeoFeature*>::iterator end() { return features.end(); }

	/******************************
	**  FieldDefn�ֶζ���
	*****************************/
	std::vector<GeoFieldDefn*>* getFieldDefns() const { return fieldDefns; }
	GeoFieldDefn* getFieldDefn(int idx) const { return (*fieldDefns)[idx]; }
	GeoFieldDefn* getFieldDefn(const QString& name) const;
	int getFieldIndex(const QString& name, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
	int getFieldIndexLike(const QString& name, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
	int getNumFields() const { return fieldDefns->size(); }
	void reserveFieldCount(int count) { fieldDefns->reserve(count); }
	QStringList getFieldList() const;

	int addField(const QString& nameIn, int widthIn, GeoFieldType typeIn);
	int addField(GeoFieldDefn* fieldDefnIn);
	bool isFieldExist(GeoFieldDefn* fieldDefn);
	bool isFieldExist(const QString& fieldName, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
	bool isFieldExistLike(const QString& fieldName, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

	/******************************
	**  Propertyͼ������
	*****************************/
	int getLID() const override { return properties.id; }
	LayerType getLayerType() const override { return kFeatureLayer; }
	QString getName() const override { return properties.name; }
	GeoExtent getExtent() const override { return properties.extent; }
	bool isVisible() const override { return properties.visible; }
	QString getSpatialRef() const { return properties.spatialRef; }
	LayerStyleMode getStyleMode() const { return properties.styleMode; }

	void setLID(int nLIDIn) override { properties.id = nLIDIn; }
	void setName(const QString& nameIn) override { properties.setName(nameIn); }
	void setExtent(const GeoExtent& extentIn) override { properties.extent = extentIn; }
	void updateExtent();
	void setVisible(bool visibleIn) override { properties.visible = visibleIn; }
	void setSpatialRef(const QString& spatialRefIn) { properties.spatialRef = spatialRefIn; }
	void setStyleMode(LayerStyleMode mode) { properties.styleMode = mode; }
	/******************************
	** Spatial Index�ռ�����
	******************************/
	bool createGridIndex();
	void queryFeatures(double x, double y, double halfEdge, GeoFeature*& featureOut) const;
	void queryFeatures(const GeoExtent& extent, std::vector<GeoFeature*>& featuresOut) const;

	/*********************************
	**  Select featuresѡ��Ҫ��
	*********************************/
	std::vector<GeoFeature*>& getSelectedFeatures()
	{
		return selectedFetures;
	}
	void emplaceSelectedFeature(GeoFeature* sf);
	void emplaceSelectedFeature(int nFID);
	void emplaceSelectedFeatures(const std::vector<GeoFeature*>& sfs);
	void emplaceSelectedFeatures(const std::vector<int>& nFIDs);
	void setSelectedFeatures(const std::vector<GeoFeature*>& sfs);
	void setSelectedFeatures(const std::vector<int>& nFIDs);
	void clearSelectedFeatures();

	/*********************************
	**  Delete featuresɾ��Ҫ��
	*********************************/
	void deleteFeature(int nFID, bool softDelete = true);
	void deleteFeature(GeoFeature* feature, bool softDelete = true);
	void deleteFeatures(const std::vector<int>& nFIDs, bool softDelete = true);
	void deleteFeatures(const std::vector<GeoFeature*>& fs, bool softDelete = true);
	void deleteSelectedFeatures(bool softDelete = true);
	bool clearAllDeleteFlags();  // Clear all delete-flag
	bool clearDeleteFlags(const std::vector<GeoFeature*>& features);
	bool applyAllDeleteFlags();  // Delete features which has delete-flag

	/*********************************
	 **  Offset features (move)ƫ��Ҫ��
	*********************************/
	void offsetSelectedFeatures(double xOffset, double yOffset);
	void offsetFeatures(const std::vector<GeoFeature*>& fs, double xOffset, double yOffset);

	/*********************************
	**  Rotate features (move)��תҪ��
	*********************************/
	void rotateSelectedFeatures(double angle);
	void rotateFeatures(const std::vector<GeoFeature*>& fs, double angle);

private:
	/* The id of the next feature to be added */
	/* Automatically increase */
	int currentFID = 0;

	std::vector<GeoFeature*> features;
	std::vector<GeoFieldDefn*>* fieldDefns = nullptr;
	GeoFeatureLayerProperty properties;

	std::vector<GeoFeature*> selectedFetures;

	// Index
	// grid index
	GridIndex* gridIndex = nullptr;
};