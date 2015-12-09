/********************************************************************************
** Form generated from reading UI file 'cloudwindows.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDWINDOWS_H
#define UI_CLOUDWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CloudWindows
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QVTKWidget *widgetCloud;
    QLabel *label_infos;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_X;
    QRadioButton *radioButton_Y;
    QRadioButton *radioButton_Z;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_bluered;
    QRadioButton *radioButton_greenmagenta;
    QRadioButton *radioButton_whitered;
    QRadioButton *radioButton_grayred;
    QRadioButton *radioButton_rainbow;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *CloudWindows)
    {
        if (CloudWindows->objectName().isEmpty())
            CloudWindows->setObjectName(QString::fromUtf8("CloudWindows"));
        CloudWindows->resize(882, 561);
        horizontalLayout = new QHBoxLayout(CloudWindows);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(CloudWindows);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(widget_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widgetCloud = new QVTKWidget(splitter);
        widgetCloud->setObjectName(QString::fromUtf8("widgetCloud"));
        splitter->addWidget(widgetCloud);
        label_infos = new QLabel(splitter);
        label_infos->setObjectName(QString::fromUtf8("label_infos"));
        label_infos->setMaximumSize(QSize(16777215, 100));
        splitter->addWidget(label_infos);

        verticalLayout_2->addWidget(splitter);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(CloudWindows);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(200, 10000000));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(100, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_X = new QRadioButton(groupBox);
        radioButton_X->setObjectName(QString::fromUtf8("radioButton_X"));

        verticalLayout_3->addWidget(radioButton_X);

        radioButton_Y = new QRadioButton(groupBox);
        radioButton_Y->setObjectName(QString::fromUtf8("radioButton_Y"));

        verticalLayout_3->addWidget(radioButton_Y);

        radioButton_Z = new QRadioButton(groupBox);
        radioButton_Z->setObjectName(QString::fromUtf8("radioButton_Z"));

        verticalLayout_3->addWidget(radioButton_Z);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton_bluered = new QRadioButton(groupBox_2);
        radioButton_bluered->setObjectName(QString::fromUtf8("radioButton_bluered"));

        verticalLayout_4->addWidget(radioButton_bluered);

        radioButton_greenmagenta = new QRadioButton(groupBox_2);
        radioButton_greenmagenta->setObjectName(QString::fromUtf8("radioButton_greenmagenta"));

        verticalLayout_4->addWidget(radioButton_greenmagenta);

        radioButton_whitered = new QRadioButton(groupBox_2);
        radioButton_whitered->setObjectName(QString::fromUtf8("radioButton_whitered"));

        verticalLayout_4->addWidget(radioButton_whitered);

        radioButton_grayred = new QRadioButton(groupBox_2);
        radioButton_grayred->setObjectName(QString::fromUtf8("radioButton_grayred"));

        verticalLayout_4->addWidget(radioButton_grayred);

        radioButton_rainbow = new QRadioButton(groupBox_2);
        radioButton_rainbow->setObjectName(QString::fromUtf8("radioButton_rainbow"));

        verticalLayout_4->addWidget(radioButton_rainbow);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout->addWidget(widget);


        retranslateUi(CloudWindows);

        QMetaObject::connectSlotsByName(CloudWindows);
    } // setupUi

    void retranslateUi(QWidget *CloudWindows)
    {
        CloudWindows->setWindowTitle(QApplication::translate("CloudWindows", "Form", 0, QApplication::UnicodeUTF8));
        label_infos->setText(QApplication::translate("CloudWindows", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CloudWindows", "Color on axis", 0, QApplication::UnicodeUTF8));
        radioButton_X->setText(QApplication::translate("CloudWindows", "X", 0, QApplication::UnicodeUTF8));
        radioButton_Y->setText(QApplication::translate("CloudWindows", "Y", 0, QApplication::UnicodeUTF8));
        radioButton_Z->setText(QApplication::translate("CloudWindows", "Z", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CloudWindows", "Color mode", 0, QApplication::UnicodeUTF8));
        radioButton_bluered->setText(QApplication::translate("CloudWindows", "Blue to red", 0, QApplication::UnicodeUTF8));
        radioButton_greenmagenta->setText(QApplication::translate("CloudWindows", "Green to magenta", 0, QApplication::UnicodeUTF8));
        radioButton_whitered->setText(QApplication::translate("CloudWindows", "White to red", 0, QApplication::UnicodeUTF8));
        radioButton_grayred->setText(QApplication::translate("CloudWindows", "Grey /red", 0, QApplication::UnicodeUTF8));
        radioButton_rainbow->setText(QApplication::translate("CloudWindows", "Rainbow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CloudWindows: public Ui_CloudWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDWINDOWS_H
