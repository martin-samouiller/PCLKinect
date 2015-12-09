/********************************************************************************
** Form generated from reading UI file 'texture.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTURE_H
#define UI_TEXTURE_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Texture
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVTKWidget *qvtkcloud;
    QVTKWidget *qvtkTexture;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *btn_texture;
    QPushButton *btn_saveTexture;

    void setupUi(QWidget *Texture)
    {
        if (Texture->objectName().isEmpty())
            Texture->setObjectName(QString::fromUtf8("Texture"));
        Texture->resize(831, 548);
        verticalLayout = new QVBoxLayout(Texture);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Texture);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        qvtkcloud = new QVTKWidget(widget);
        qvtkcloud->setObjectName(QString::fromUtf8("qvtkcloud"));

        horizontalLayout->addWidget(qvtkcloud);

        qvtkTexture = new QVTKWidget(widget);
        qvtkTexture->setObjectName(QString::fromUtf8("qvtkTexture"));

        horizontalLayout->addWidget(qvtkTexture);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Texture);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        btn_texture = new QPushButton(widget_2);
        btn_texture->setObjectName(QString::fromUtf8("btn_texture"));

        horizontalLayout_3->addWidget(btn_texture);

        btn_saveTexture = new QPushButton(widget_2);
        btn_saveTexture->setObjectName(QString::fromUtf8("btn_saveTexture"));

        horizontalLayout_3->addWidget(btn_saveTexture);


        verticalLayout->addWidget(widget_2);


        retranslateUi(Texture);

        QMetaObject::connectSlotsByName(Texture);
    } // setupUi

    void retranslateUi(QWidget *Texture)
    {
        Texture->setWindowTitle(QApplication::translate("Texture", "Texture", 0, QApplication::UnicodeUTF8));
        btn_texture->setText(QApplication::translate("Texture", "Texture", 0, QApplication::UnicodeUTF8));
        btn_saveTexture->setText(QApplication::translate("Texture", "Save texture", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Texture: public Ui_Texture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTURE_H
