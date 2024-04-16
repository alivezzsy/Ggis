#pragma once

#include <QCollator>
#include <QColorDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLocale>
#include <QPushButton>
#include <QStackedLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <vector>

#include "geo\map\geolayer.h"

class LayerStyleDialog : public QDialog
{
	Q_OBJECT
public:
	LayerStyleDialog(GeoFeatureLayer* layerIn, QWidget *parent);
	~LayerStyleDialog();

signals:
	void sigUpdateOpengl();

public slots:
	void onClassify();
	void onBtnOkClicked();
	void onBtnApplyClicked();

public:
	void createColorRampItems();
	void processSingleStyle();
	void processCategorizedStyle();

private:
	void setupLayout();

	// create different pages for differnt style-type
	void createPageSingleStyle();
	void createPageCategorizedStyle();

	// color ramp
	void addColorRamp(const QColor& startColor, const QColor& endColor);
	void addRandomColorRamp();
	template<typename T>
	void insertClassifyItem(QTableWidget* tableWidget, int row, int nFID, const QColor& color, T value)
	{
		//column 0
		QWidget* widget = new QWidget(categorizedStyleWidget);
		QHBoxLayout* layout = new QHBoxLayout(widget);
		layout->setSpacing(0);
		layout->setMargin(5);
		QCheckBox* checkBox = new QCheckBox(widget);
		checkBox->setCheckState(Qt::Checked);
		layout->addWidget(checkBox);
		ColorBlockWidget* colorWidget = new ColorBlockWidget(widget);
		colorWidget->setFID(nFID);
		colorWidget->setColor(color);
		layout->addWidget(colorWidget);
		tableWidget->setCellWidget(row, 0, widget);

		//column 1
		// column 2
		QTableWidgetItem* item1 = new QTableWidgetItem();
		QTableWidgetItem* item2 = new QTableWidgetItem();


		setTextValue(item1, value);
		setTextValue(item2, value);
		tableWidget->setItem(row, 1, item1);
		tableWidget->setItem(row, 2, item2);
	}
	template<typename T>
	void setTextValue(QTableWidgetItem* item, const T& value) {
		// 默认情况下，将值转换为字符串并设置文本
		item->setText(QString::number(value));
	}
	// QString类型的特化版本
	template<>
	void setTextValue<QString>(QTableWidgetItem* item, const QString& value) {
		// 直接设置文本为QString值
		item->setText(value);
	}
	
	// classify, and put data in classifyResultWidget
	//1. random color
	template<typename T>
	void classifyRandomColor(int fieldIndex)
	{
		int featuresCount = layer->getFeatureCount();

		// put date to classifyResultWidget
		for (int i = 0; i < featuresCount; ++i) {
			GeoFeature* feature = layer->getFeature(i);
			T value;
			feature->getField(fieldIndex, &value);
			QColor color(rand() % 256, rand() % 256, rand() % 256);
		insertClassifyItem(classifyResultWidget, i, feature->getFID(), color, value);
		}
	}

	template<typename T>
	void sortPairs(std::vector<std::pair<GeoFeature*, T>>& pairs) {
		// 默认使用默认的比较函数进行排序
		std::sort(pairs.begin(), pairs.end(),
			[](const std::pair<GeoFeature*, T>& in1, const std::pair<GeoFeature*, T>& in2) {
			return in1.second < in2.second;
		});
	}

	// 模板特化版本，针对 QString 类型的参数使用 QCollator 进行排序
	template<>
	void sortPairs<QString>(std::vector<std::pair<GeoFeature*, QString>>& pairs) {
		QLocale loc(QLocale::Chinese, QLocale::China);
		QCollator qcol(loc);
		std::sort(pairs.begin(), pairs.end(),
			[&qcol](const std::pair<GeoFeature*, QString>& in1, const std::pair<GeoFeature*, QString>& in2) {
			return qcol.compare(in1.second, in2.second) < 0;
		});
	}

	template<typename T>
	void classify(int fieldIndex, const QColor& startColor, const QColor& endColor)
	{
		int featuresCount = layer->getFeatureCount();
		std::vector<std::pair<GeoFeature*, T>> pairs;
		pairs.reserve(featuresCount);

		 //Get all values of the specified field
		for (int iFeature = 0; iFeature < featuresCount; ++iFeature) {
			GeoFeature* feature = layer->getFeature(iFeature);
			T fieldValue;
			feature->getField(fieldIndex, &fieldValue);
			pairs.emplace_back(feature, fieldValue);
		}
		sortPairs(pairs);
		// R, G, B increment
		double deltaR = (endColor.red() - startColor.red()) / featuresCount;
		double deltaG = (endColor.green() - startColor.green()) / featuresCount;
		double deltaB = (endColor.blue() - startColor.blue()) / featuresCount;

		for (int i = 0; i < featuresCount; ++i) {
			GeoFeature* feature = pairs[i].first;
			T value = pairs[i].second;
			QColor color(
				startColor.red() + int(deltaR * i),
				startColor.green() + int(deltaG * i),
				startColor.blue() + int(deltaB * i)
			);
			insertClassifyItem(classifyResultWidget, i, feature->getFID(), color, value);
		}
	}

private:
	GeoFeatureLayer* layer = nullptr;

	std::vector<std::pair<QColor, QColor>> colorPairs;

	QComboBox* modeComboBox = nullptr;
	QVBoxLayout* mainLayout = nullptr;
	QStackedLayout* stackedLayout = nullptr;

	//	QPushButton* btnLoadSLD;
	QPushButton* btnOk;
	QPushButton* btnCancel;
	QPushButton* btnApply;

	// Single style
	QWidget* singleStyleWidget;
	QColorDialog* colorSelectDialog;

	// Classify style
	QWidget* categorizedStyleWidget;
	QComboBox* classifyFieldComboBox;
	QComboBox* colorRampComboBox;
	QPushButton* btnClassify;
	QTableWidget* classifyResultWidget;

};