/********************************************************************************
** Form generated from reading UI file 'Ggis.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGIS_H
#define UI_GGIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GgisClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GgisClass)
    {
        if (GgisClass->objectName().isEmpty())
            GgisClass->setObjectName(QStringLiteral("GgisClass"));
        GgisClass->resize(600, 400);
        menuBar = new QMenuBar(GgisClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GgisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GgisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GgisClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GgisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GgisClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GgisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GgisClass->setStatusBar(statusBar);

        retranslateUi(GgisClass);

        QMetaObject::connectSlotsByName(GgisClass);
    } // setupUi

    void retranslateUi(QMainWindow *GgisClass)
    {
        GgisClass->setWindowTitle(QApplication::translate("GgisClass", "Ggis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GgisClass: public Ui_GgisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGIS_H
