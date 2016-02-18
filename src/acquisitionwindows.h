#ifndef ACQUISITIONWINDOWS_H
#define ACQUISITIONWINDOWS_H

#include <QDialog>
#include <QMainWindow>
#include <QThread>
#include <QList>
#include <iostream>



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


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "qlabelimage.h"

#include "defineType.h"

using namespace pcl;
using namespace std;


namespace Ui {
class AcquisitionWindows;
}

class AcquisitionWindows : public QDialog
{
    Q_OBJECT

public:
    explicit AcquisitionWindows(QWidget *parent = 0);
    ~AcquisitionWindows();

    void
    cloud_cb_ (const pcl::PointCloud<PointT>::ConstPtr &cloud);

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    PointCloudT::Ptr cloud;
    PointCloudT::ConstPtr cloudSave ;
    PointCloudC::Ptr cloudTexture;
     //Register Callback

public slots:
    int
    DemarerAcqui();

    void
    StopperAcqui();

    void
    ConnectDevice();

private slots:
    void
    Mouse_current_pos_stream();
    void
    Mouse_current_pos_capture();
    void
    Mouse_pressed();
    void
    MouseClickLeft();
    void
    Mouse_release_pos();
    void
    displayFrame();

    void on_rdnBtn_jetLUT_clicked();

    void on_rdnBtn_grayscaleLUT_clicked();

    void on_rndBtn_oceanLUT_clicked();

    void on_pushButton_SaveCloud_clicked();

private:
    Ui::AcquisitionWindows *ui;
    Grabber* device = NULL; // OpenNI grabber that takes data from the device.
    bool m_iSDeviceConnect ;

    cv::VideoCapture capture;
    QTimer *qTimer;
    QLabelImage *lbl_stream;
    cv::Mat imageStream;
    cv::Mat imageCapture;
    cv::Mat depthMap;
    bool m_colorGray;
    bool m_colorOcean;
    bool m_colorJet;
    int m_numberCapture;


};


#endif // ACQUISITIONWINDOWS_H
