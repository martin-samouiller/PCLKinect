/********************************************************************************
** Form generated from reading UI file 'acquisitionwindows.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACQUISITIONWINDOWS_H
#define UI_ACQUISITIONWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AcquisitionWindows
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_connection;
    QPushButton *btn_LED;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_startAcqui;
    QPushButton *btn_stopAcqui;
    QTabWidget *tabwidget;
    QWidget *tab_Live;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    QVTKWidget *qvtk_Cloud;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scroll_image;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rndBtn_captureDepth;
    QRadioButton *rndBtn_captureRGB;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rndBtn_oceanLUT;
    QRadioButton *rdnBtn_grayscaleLUT;
    QRadioButton *rdnBtn_jetLUT;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_SaveCloud;
    QWidget *tab_record;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_infos;
    QProgressBar *progressBar;

    void setupUi(QDialog *AcquisitionWindows)
    {
        if (AcquisitionWindows->objectName().isEmpty())
            AcquisitionWindows->setObjectName(QString::fromUtf8("AcquisitionWindows"));
        AcquisitionWindows->resize(1044, 643);
        verticalLayout = new QVBoxLayout(AcquisitionWindows);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(AcquisitionWindows);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_connection = new QPushButton(widget_2);
        btn_connection->setObjectName(QString::fromUtf8("btn_connection"));
        btn_connection->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(btn_connection);

        btn_LED = new QPushButton(widget_2);
        btn_LED->setObjectName(QString::fromUtf8("btn_LED"));
        btn_LED->setMaximumSize(QSize(20, 20));
        btn_LED->setCheckable(false);
        btn_LED->setFlat(false);

        horizontalLayout_2->addWidget(btn_LED);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_startAcqui = new QPushButton(widget_2);
        btn_startAcqui->setObjectName(QString::fromUtf8("btn_startAcqui"));
        btn_startAcqui->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(btn_startAcqui);

        btn_stopAcqui = new QPushButton(widget_2);
        btn_stopAcqui->setObjectName(QString::fromUtf8("btn_stopAcqui"));
        btn_stopAcqui->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(btn_stopAcqui);


        verticalLayout->addWidget(widget_2);

        tabwidget = new QTabWidget(AcquisitionWindows);
        tabwidget->setObjectName(QString::fromUtf8("tabwidget"));
        tab_Live = new QWidget();
        tab_Live->setObjectName(QString::fromUtf8("tab_Live"));
        verticalLayout_4 = new QVBoxLayout(tab_Live);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(tab_Live);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_3 = new QWidget(splitter);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter_2 = new QSplitter(widget_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        qvtk_Cloud = new QVTKWidget(splitter_2);
        qvtk_Cloud->setObjectName(QString::fromUtf8("qvtk_Cloud"));
        splitter_2->addWidget(qvtk_Cloud);
        widget_5 = new QWidget(splitter_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_6 = new QVBoxLayout(widget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        scroll_image = new QScrollArea(widget_5);
        scroll_image->setObjectName(QString::fromUtf8("scroll_image"));
        scroll_image->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 760, 318));
        scroll_image->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scroll_image);

        splitter_2->addWidget(widget_5);

        verticalLayout_2->addWidget(splitter_2);

        splitter->addWidget(widget_3);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rndBtn_captureDepth = new QRadioButton(groupBox);
        rndBtn_captureDepth->setObjectName(QString::fromUtf8("rndBtn_captureDepth"));

        verticalLayout_3->addWidget(rndBtn_captureDepth);

        rndBtn_captureRGB = new QRadioButton(groupBox);
        rndBtn_captureRGB->setObjectName(QString::fromUtf8("rndBtn_captureRGB"));

        verticalLayout_3->addWidget(rndBtn_captureRGB);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        rndBtn_oceanLUT = new QRadioButton(groupBox_2);
        rndBtn_oceanLUT->setObjectName(QString::fromUtf8("rndBtn_oceanLUT"));

        verticalLayout_5->addWidget(rndBtn_oceanLUT);

        rdnBtn_grayscaleLUT = new QRadioButton(groupBox_2);
        rdnBtn_grayscaleLUT->setObjectName(QString::fromUtf8("rdnBtn_grayscaleLUT"));

        verticalLayout_5->addWidget(rdnBtn_grayscaleLUT);

        rdnBtn_jetLUT = new QRadioButton(groupBox_2);
        rdnBtn_jetLUT->setObjectName(QString::fromUtf8("rdnBtn_jetLUT"));

        verticalLayout_5->addWidget(rdnBtn_jetLUT);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_3->addWidget(groupBox_2);

        pushButton_SaveCloud = new QPushButton(groupBox);
        pushButton_SaveCloud->setObjectName(QString::fromUtf8("pushButton_SaveCloud"));

        verticalLayout_3->addWidget(pushButton_SaveCloud);

        splitter->addWidget(groupBox);

        verticalLayout_4->addWidget(splitter);

        tabwidget->addTab(tab_Live, QString());
        tab_record = new QWidget();
        tab_record->setObjectName(QString::fromUtf8("tab_record"));
        tabwidget->addTab(tab_record, QString());

        verticalLayout->addWidget(tabwidget);

        widget = new QWidget(AcquisitionWindows);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_infos = new QLabel(widget);
        lbl_infos->setObjectName(QString::fromUtf8("lbl_infos"));

        horizontalLayout->addWidget(lbl_infos);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);


        verticalLayout->addWidget(widget);


        retranslateUi(AcquisitionWindows);
        QObject::connect(btn_startAcqui, SIGNAL(clicked()), AcquisitionWindows, SLOT(DemarerAcqui()));
        QObject::connect(btn_connection, SIGNAL(clicked()), AcquisitionWindows, SLOT(ConnectDevice()));
        QObject::connect(btn_stopAcqui, SIGNAL(clicked()), AcquisitionWindows, SLOT(StopperAcqui()));

        tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AcquisitionWindows);
    } // setupUi

    void retranslateUi(QDialog *AcquisitionWindows)
    {
        AcquisitionWindows->setWindowTitle(QApplication::translate("AcquisitionWindows", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_connection->setText(QApplication::translate("AcquisitionWindows", "Connection", 0, QApplication::UnicodeUTF8));
        btn_LED->setText(QString());
        btn_startAcqui->setText(QApplication::translate("AcquisitionWindows", "Start Acquisition", 0, QApplication::UnicodeUTF8));
        btn_stopAcqui->setText(QApplication::translate("AcquisitionWindows", "Stop Acquisition", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AcquisitionWindows", "Capture 2D", 0, QApplication::UnicodeUTF8));
        rndBtn_captureDepth->setText(QApplication::translate("AcquisitionWindows", "Depth", 0, QApplication::UnicodeUTF8));
        rndBtn_captureRGB->setText(QApplication::translate("AcquisitionWindows", "RGB", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AcquisitionWindows", "LUT", 0, QApplication::UnicodeUTF8));
        rndBtn_oceanLUT->setText(QApplication::translate("AcquisitionWindows", "Ocean", 0, QApplication::UnicodeUTF8));
        rdnBtn_grayscaleLUT->setText(QApplication::translate("AcquisitionWindows", "Grayscale", 0, QApplication::UnicodeUTF8));
        rdnBtn_jetLUT->setText(QApplication::translate("AcquisitionWindows", "Jet", 0, QApplication::UnicodeUTF8));
        pushButton_SaveCloud->setText(QApplication::translate("AcquisitionWindows", "Save Cloud", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(tab_Live), QApplication::translate("AcquisitionWindows", "Live", 0, QApplication::UnicodeUTF8));
        tabwidget->setTabText(tabwidget->indexOf(tab_record), QApplication::translate("AcquisitionWindows", "Save", 0, QApplication::UnicodeUTF8));
        lbl_infos->setText(QApplication::translate("AcquisitionWindows", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AcquisitionWindows: public Ui_AcquisitionWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACQUISITIONWINDOWS_H
