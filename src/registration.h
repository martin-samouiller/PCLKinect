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
// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtk3DWidget.h>


#include "icpthread.h"

using namespace pcl;
using namespace std;


namespace Ui {
class Registration;
}


enum E_REGISTRATION
{
    ICP,
    FEATURE_BASED,
};


class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    void
    init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName);
    ~Registration();

private slots:
    void on_comboBox_Source_currentIndexChanged(const QString &arg1);

    void on_comboBox_Target_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_btn_SaveCloudFinal_clicked();

    void on_comboBox_TypeRegist_currentIndexChanged(const QString &arg1);

    void eventSlotFinishICP();

private:
    Ui::Registration *ui;
    DictionaryCloudPtr m_listCloudsPtr;
    DictionaryCloudName m_listCloudsName;
    PointCloudT::Ptr _cloudSource;
    PointCloudT::Ptr _cloudTarget;
    PointCloudT::Ptr _cloudFinish;

    E_REGISTRATION _eTypeRegistration;
    icpthread * _icpCompute;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerCloudFinish;
};

#endif // REGISTRATION_H
