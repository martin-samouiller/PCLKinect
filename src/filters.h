#ifndef FILTERS_H
#define FILTERS_H

#include <QWidget>

#include <QVTKWidget.h>
// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtk3DWidget.h>

#include "defineType.h"

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/vtk_io.h>

namespace Ui {
class Filters;
}

enum E_FILTRAGE
{
    PASS_THROUGH,
    REMOVE_NAN,
    REMOVE_NOISE,

};


class Filters : public QWidget
{
    Q_OBJECT

public:
    explicit Filters(QWidget *parent = 0);
    ~Filters();

    void
    init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName);

private slots:
    void
    on_comboBox_FiltersType_currentIndexChanged(const QString &arg1);
    void
    on_btn_saveCloud_clicked();
    void
    on_comboBox_Clouds_currentIndexChanged(const QString &arg1);
    void
    slotFinishFilter();

private:
    Ui::Filters *ui;
    DictionaryCloudPtr m_listCloudsPtr;
    DictionaryCloudName m_listCloudsName;
    PointCloudT::Ptr _cloudSource;
    PointCloudT::Ptr _cloudFinal;
    E_FILTRAGE _eTypeFiltrage;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerCloudResult;
};

#endif // FILTERS_H
