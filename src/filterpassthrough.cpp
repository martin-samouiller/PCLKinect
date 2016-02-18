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
