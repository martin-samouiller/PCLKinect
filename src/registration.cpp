#include "registration.h"
#include "../build/ui_registration.h"
#include <QtDebug>





Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}



void Registration::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Registration : " << arg1;
}



void Registration::init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName)
{
    //Maj des items à partir des données des nuages de points
    ui->comboBox_Source->addItems(_listCloud);
    ui->comboBox_Target->addItems(_listCloud);
    m_listCloudsPtr = _listCloudPtr;
    m_listCloudsName = _listCloudsName;


    on_comboBox_Source_currentIndexChanged(ui->comboBox_Source->itemText(ui->comboBox_Source->currentIndex()));
    on_comboBox_Target_currentIndexChanged(ui->comboBox_Target->itemText(ui->comboBox_Target->currentIndex()));

}

void Registration::on_comboBox_Source_currentIndexChanged(const QString &arg1)
{

}

void Registration::on_comboBox_Target_currentIndexChanged(const QString &arg1)
{

}
