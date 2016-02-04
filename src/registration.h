#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

#include "defineType.h"


// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/vtk_io.h>

#include <QVTKWidget.h>

using namespace pcl;
using namespace std;


namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    void
    init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName);
    ~Registration();

private slots:
    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_Source_currentIndexChanged(const QString &arg1);

    void on_comboBox_Target_currentIndexChanged(const QString &arg1);

private:
    Ui::Registration *ui;
    DictionaryCloudPtr m_listCloudsPtr;
    DictionaryCloudName m_listCloudsName;
};

#endif // REGISTRATION_H
