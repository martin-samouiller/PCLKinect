/********************************************************************************
** Form generated from reading UI file 'pclacquisition.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLACQUISITION_H
#define UI_PCLACQUISITION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCLAcquisition
{
public:
    QAction *actionSave;
    QAction *actionConnection;
    QAction *actionDeconnection;
    QAction *actionStart_grabber;
    QAction *actionLoad;
    QAction *actionOpen;
    QAction *actionStart;
    QAction *actionRGB;
    QAction *actionTexture;
    QAction *actionFiltrer;
    QAction *actionICP;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QListView *listView_Clouds;
    QMdiArea *mdiArea_cloud;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuTraitement;
    QMenu *menuAcquisition;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PCLAcquisition)
    {
        if (PCLAcquisition->objectName().isEmpty())
            PCLAcquisition->setObjectName(QString::fromUtf8("PCLAcquisition"));
        PCLAcquisition->resize(1231, 674);
        actionSave = new QAction(PCLAcquisition);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionConnection = new QAction(PCLAcquisition);
        actionConnection->setObjectName(QString::fromUtf8("actionConnection"));
        actionDeconnection = new QAction(PCLAcquisition);
        actionDeconnection->setObjectName(QString::fromUtf8("actionDeconnection"));
        actionStart_grabber = new QAction(PCLAcquisition);
        actionStart_grabber->setObjectName(QString::fromUtf8("actionStart_grabber"));
        actionLoad = new QAction(PCLAcquisition);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionOpen = new QAction(PCLAcquisition);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionStart = new QAction(PCLAcquisition);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionRGB = new QAction(PCLAcquisition);
        actionRGB->setObjectName(QString::fromUtf8("actionRGB"));
        actionTexture = new QAction(PCLAcquisition);
        actionTexture->setObjectName(QString::fromUtf8("actionTexture"));
        actionFiltrer = new QAction(PCLAcquisition);
        actionFiltrer->setObjectName(QString::fromUtf8("actionFiltrer"));
        actionICP = new QAction(PCLAcquisition);
        actionICP->setObjectName(QString::fromUtf8("actionICP"));
        centralWidget = new QWidget(PCLAcquisition);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listView_Clouds = new QListView(widget_2);
        listView_Clouds->setObjectName(QString::fromUtf8("listView_Clouds"));

        verticalLayout_2->addWidget(listView_Clouds);

        splitter->addWidget(widget_2);
        mdiArea_cloud = new QMdiArea(splitter);
        mdiArea_cloud->setObjectName(QString::fromUtf8("mdiArea_cloud"));
        splitter->addWidget(mdiArea_cloud);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        splitter->addWidget(widget);

        horizontalLayout->addWidget(splitter);

        PCLAcquisition->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCLAcquisition);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1231, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuTraitement = new QMenu(menuBar);
        menuTraitement->setObjectName(QString::fromUtf8("menuTraitement"));
        menuAcquisition = new QMenu(menuBar);
        menuAcquisition->setObjectName(QString::fromUtf8("menuAcquisition"));
        PCLAcquisition->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PCLAcquisition);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PCLAcquisition->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PCLAcquisition);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PCLAcquisition->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuTraitement->menuAction());
        menuBar->addAction(menuAcquisition->menuAction());
        menuFichier->addAction(actionSave);
        menuFichier->addSeparator();
        menuFichier->addAction(actionOpen);
        menuTraitement->addAction(actionTexture);
        menuTraitement->addAction(actionFiltrer);
        menuTraitement->addAction(actionICP);
        menuAcquisition->addAction(actionStart);

        retranslateUi(PCLAcquisition);

        QMetaObject::connectSlotsByName(PCLAcquisition);
    } // setupUi

    void retranslateUi(QMainWindow *PCLAcquisition)
    {
        PCLAcquisition->setWindowTitle(QApplication::translate("PCLAcquisition", "PCLAcquisition", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("PCLAcquisition", "Save", 0, QApplication::UnicodeUTF8));
        actionConnection->setText(QApplication::translate("PCLAcquisition", "Connection", 0, QApplication::UnicodeUTF8));
        actionDeconnection->setText(QApplication::translate("PCLAcquisition", "Deconnection", 0, QApplication::UnicodeUTF8));
        actionStart_grabber->setText(QApplication::translate("PCLAcquisition", "Start grabber", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("PCLAcquisition", "Load", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("PCLAcquisition", "Open", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("PCLAcquisition", "Start", 0, QApplication::UnicodeUTF8));
        actionRGB->setText(QApplication::translate("PCLAcquisition", "RGB", 0, QApplication::UnicodeUTF8));
        actionTexture->setText(QApplication::translate("PCLAcquisition", "Mesh", 0, QApplication::UnicodeUTF8));
        actionFiltrer->setText(QApplication::translate("PCLAcquisition", "Filtrer", 0, QApplication::UnicodeUTF8));
        actionICP->setText(QApplication::translate("PCLAcquisition", "ICP", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("PCLAcquisition", "File", 0, QApplication::UnicodeUTF8));
        menuTraitement->setTitle(QApplication::translate("PCLAcquisition", "Processing", 0, QApplication::UnicodeUTF8));
        menuAcquisition->setTitle(QApplication::translate("PCLAcquisition", "Acquisition", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLAcquisition: public Ui_PCLAcquisition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLACQUISITION_H
