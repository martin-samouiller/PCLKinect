#ifndef PCLACQUISITION_H
#define PCLACQUISITION_H

#include <QMainWindow>
#include <QThread>
#include <QList>
#include <QStringListModel>
// Original code by Geoffrey Biggs, taken from the PCL tutorial in
// http://pointclouds.org/documentation/tutorials/pcl_visualizer.php

// Simple OpenNI viewer that also allows to write the current scene to a .pcd
// when pressing SPACE.

#include <map>
#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/container/map/map_fwd.hpp>
#include <boost/fusion/include/map_fwd.hpp>

#include <boost/algorithm/string.hpp>

#include <QVTKWidget.h>
// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
//#include <pcl/visualization/pcl_visualizer.h>
//#include <pcl/visualization/image_viewer.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/console/parse.h>
#include <pcl/common/time.h>

//#include <pcl/io/openni_camera/openni_image.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/pcd_io.h>


// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtk3DWidget.h>

using namespace pcl;
using namespace std;

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

typedef pcl::PointXYZRGB PointC;
typedef pcl::PointCloud<PointC> PointCloudC;

namespace Ui {
class PCLAcquisition;
}

class PCLAcquisition : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCLAcquisition(QWidget *parent = 0);
    ~PCLAcquisition();

    void
    cloud_cb_ (const pcl::PointCloud<PointT>::ConstPtr &cloud);


protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

private slots:
    void
    on_actionSave_triggered();
    void
    on_actionStart_triggered();
    void
    on_actionOpen_triggered();
    void
    on_actionTexture_triggered();
    void
    on_actionFiltrer_triggered();
    void
    on_actionICP_triggered();
    void
    on_listClouds_current_change(QModelIndex cur, QModelIndex pre);

private:
    Ui::PCLAcquisition *ui;
    Grabber* device = NULL; // OpenNI grabber that takes data from the device.
    bool m_iSDeviceConnect ;

    std::map<std::string, std::string> listClouds;
    // Create model
    QStringListModel *model;
    // Make data
    QStringList m_strlistCloud;
    QString m_lastPathCloud; // dernier point de cloud ouvert
    //boost::tuple<std::string, > listClouds ;



};



#endif // PCLACQUISITION_H
