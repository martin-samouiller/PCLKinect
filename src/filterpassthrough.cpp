#include "filterpassthrough.h"
#include "../build/ui_filterpassthrough.h"

#include <pcl/filters/passthrough.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>

#include <QtDebug>

FilterPassThrough::FilterPassThrough(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterPassThrough)
{
    ui->setupUi(this);
    _x = 0.0f;
    _y = 0.0f;
    _z = 0.0f;
    _minx = 0.0f;
    _miny = 0.0f;
    _minz = 0.0f;

}

FilterPassThrough::~FilterPassThrough()
{
    delete ui;
}

void
FilterPassThrough::init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal)
{
    _cloudSrc = cloudSrc;
    _cloudFinal = cloudFinal;
}

void FilterPassThrough::startFilter(float minx, float miny, float minz, float x, float y, float z)
{
     pcl::copyPointCloud(*_cloudSrc, *_cloudFinal);

     // Applying passthrough filters with XYZ limits

     pcl::PassThrough<PointT> ptfilter (true);
     ptfilter.setInputCloud (_cloudFinal);
     ptfilter.setFilterFieldName ("y");
     ptfilter.setFilterLimits (miny, y);
     ptfilter.filter (*_cloudFinal);

     ptfilter.setInputCloud (_cloudFinal);
     ptfilter.setFilterFieldName ("x");
     ptfilter.setFilterLimits (minx, x);
     ptfilter.filter (*_cloudFinal);

     ptfilter.setInputCloud (_cloudFinal);
     ptfilter.setFilterFieldName ("z");
     ptfilter.setFilterLimits (minz, z);
     ptfilter.filter (*_cloudFinal);


    QString lbl_info = "";
    lbl_info.append("Size cloud src : ");  lbl_info.append(QString::number(_cloudSrc->points.size()));
    lbl_info.append("Size cloud filter : ");  lbl_info.append(QString::number(_cloudFinal->points.size()));
    ui->lbl_Infos->setText(lbl_info);
    emit signalFinishFilter();
}

void FilterPassThrough::on_slider_X_sliderMoved(int position)
{
     _x = 0.01*((float)position);
     majLabelText();
     startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::on_slider_Y_sliderMoved(int position)
{
     _y = 0.01*((float)position);
     majLabelText();
     startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::on_slider_Z_sliderMoved(int position)
{
     _z = 0.01*((float)position);
     majLabelText();
     startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::on_slider_minX_sliderMoved(int position)
{
    _minx = 0.01*((float)position);
    majLabelText();
    startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::on_slider_minY_sliderMoved(int position)
{
    _miny = 0.01*((float)position);
    majLabelText();
    startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::on_slider_minZ_sliderMoved(int position)
{
    _minz = 0.01*((float)position);
    majLabelText();
    startFilter(_minx, _miny, _minz, _x,_y, _z );
}

void FilterPassThrough::majLabelText(){

    QString labelX = "-X :";
    QString labelY = "-Y :";
    QString labelZ = "-Z :";
    labelX.append(QString::number(_minx)); labelX.append(" / "); labelX.append("X : ");  labelX.append(QString::number(_x));
    labelY.append(QString::number(_miny)); labelY.append(" / "); labelY.append("Y : ");  labelY.append(QString::number(_y));
    labelZ.append(QString::number(_minz)); labelZ.append(" / "); labelZ.append("Z : ");  labelZ.append(QString::number(_z));
    ui->lbl_X->setText(labelX);
    ui->lbl_Y->setText(labelY);
    ui->lbl_Z->setText(labelZ);
}




/*
 *
 *
 *
 * #include <pcl/io/pcd_io.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

#include <iostream>

int
main(int argc, char** argv)
{
    // Objects for storing the point clouds.
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr inlierPoints(new pcl::PointCloud<pcl::PointXYZ>);

    // Read a PCD file from disk.
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) != 0)
    {
        return -1;
    }

    // Object for storing the plane model coefficients.
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    // Create the segmentation object.
    pcl::SACSegmentation<pcl::PointXYZ> segmentation;
    segmentation.setInputCloud(cloud);
    // Configure the object to look for a plane.
    segmentation.setModelType(pcl::SACMODEL_PLANE);
    // Use RANSAC method.
    segmentation.setMethodType(pcl::SAC_RANSAC);
    // Set the maximum allowed distance to the model.
    segmentation.setDistanceThreshold(0.01);
    // Enable model coefficient refinement (optional).
    segmentation.setOptimizeCoefficients(true);

    pcl::PointIndices inlierIndices;
    segmentation.segment(inlierIndices, *coefficients);

    if (inlierIndices.indices.size() == 0)
        std::cout << "Could not find any points that fitted the plane model." << std::endl;
    else
    {
        std::cerr << "Model coefficients: " << coefficients->values[0] << " "
                  << coefficients->values[1] << " "
                  << coefficients->values[2] << " "
                  << coefficients->values[3] << std::endl;

        // Copy all inliers of the model to another cloud.
        pcl::copyPointCloud<pcl::PointXYZ>(*cloud, inlierIndices, *inlierPoints);
    }
}
*/
