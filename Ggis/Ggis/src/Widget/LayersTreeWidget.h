#pragma once

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>

#include"LayersTreeWidgetItem.h"
#include"geo\map\geolayer.h"
#include"Dialog\layerAttributeTableDialog.h"
#include"Dialog\layerStyleDialog.h"
class Geolayer;
class GeoFeatureLayer;
class GeoMap;

class LayersTreeWidget : public QTreeWidget {
	Q_OBJECT
public:
	LayersTreeWidget(QWidget* parent = nullptr);
	~LayersTreeWidget();

signals:
	void sigUpdateOpengl();
	void sigSendMapToGPU(bool bUpdate);
	void sigZoomToMap();
	void sigZoomToLayer(GeoLayer* layer);
	void sigStartEditing(bool on);

public slots:
	void onUpdateLayersTree();
	void onAddNewLayer(GeoLayer* newLayer);

	void onItemChanged(QTreeWidgetItem* item, int column);
	void onRemoveLayer();
	void onRenameItem();
	void onOpenAttributeTable();
	void onShowStyleDialog();
	void onStartEditing();
	void onSaveEdits();
	void onStopEditing();
	void onZoomToMap();
	void onZoomToLayer();

public:
	void createActions();
	void createMenus();

protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void dragEnterEvent(QDragEnterEvent *event) override;
	void startDrag(Qt::DropActions supportedActions) override;
	void dragMoveEvent(QDragMoveEvent *event) override;
	void dropEvent(QDropEvent *event) override;
	void contextMenuEvent(QContextMenuEvent *event) override;
	void closeEditor(QWidget *editor, QAbstractItemDelegate::EndEditHint hint) override;

public:
	// dialog
	LayerAttributeTableDialog* attributeTableDialog = nullptr;
	LayerStyleDialog* styleDialog = nullptr;

private:
	LayersTreeWidgetItem* toLayerItem(QTreeWidgetItem* item)
	{
		return dynamic_cast<LayersTreeWidgetItem*>(item);
	}

	GeoMap*& map;
	GeoMap*  backupMap = nullptr;

	// RootItem: map's name
	QTreeWidgetItem* rootItem;

	// actions
	QAction* removeLayerAction;
	QAction* renameItemAction;
	QAction* zoomToMapAction;
	QAction* zoomToLayerAction;
	QAction* openAttributeTableAction;
	QAction* startEditingAction;
	QAction* saveEditsAction;
	QAction* stopEditingAction;
	QAction* showStyleDialog;
	QAction* addShpDataAction;
	QAction* addJsonDataAction;
//Menus
	QMenu* popMenuOnFeatureLayer;
	QMenu* popMenuOnMap;
	QMenu* menuEditFeature;
	QMenu* menuAddData;
};