#ifndef CLOUDWINDOWS_H
#define CLOUDWINDOWS_H

#include <QWidget>
#include <QMainWindow>
#include <QThread>
#include <QList>



#include <iostream>
#include <boost/tuple/tuple.hpp>


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

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

typedef pcl::PointXYZRGB PointC;
typedef pcl::PointCloud<PointC> PointCloudC;


namespace Ui {
class CloudWindows;
}

class CloudWindows : public QWidget
{
    Q_OBJECT

public:
    explicit CloudWindows(QWidget *parent = 0);
    ~CloudWindows();

    void
    init (PointCloudC::Ptr cloud, std::string nameCloud);
    void
    colorCloudDistances (PointCloudC::Ptr cloud_);
    void
    updateCloudViewer();

private slots:
    void axisChosen ();

    void lookUpTableChosen ();

private:
    Ui::CloudWindows *ui;
    PointCloudT::Ptr _cloud;
    PointCloudC::Ptr _cloudColor;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerCloud;
    int filtering_axis_ = 0; //Choix de l'axe ou on va colorier le nuage de point
    int color_mode_ = 0; //Choix du mode de colorisation du nuage de point
    int nbr_windows = 0; //nbr de window de cloud ouverte
    bool colorCloud = false;

};

#endif // CLOUDWINDOWS_H
