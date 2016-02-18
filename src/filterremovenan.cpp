#include "filterremovenan.h"
#include "../build/ui_filterremovenan.h"

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>

FilterRemoveNaN::FilterRemoveNaN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterRemoveNaN)
{
    ui->setupUi(this);
}


void
FilterRemoveNaN::init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal)
{
    _cloudSrc = cloudSrc;
    _cloudFinal = cloudFinal;
}

FilterRemoveNaN::~FilterRemoveNaN()
{
    delete ui;
}

void FilterRemoveNaN::on_pushButton_clicked()
{
  //remove NAN points from the cloud
  std::vector<int> indices;
  pcl::removeNaNFromPointCloud(*_cloudSrc, *_cloudFinal, indices);
  ui->lbl_SizeSrc->setText(QString::number(_cloudSrc->points.size()));
  ui->lbl_SizeFinal->setText(QString::number(_cloudFinal->points.size()));
  float diff = _cloudSrc->points.size() - _cloudFinal->points.size();
  ui->lbl_NanRemove->setText(QString::number(diff));

  emit signalFinishFilter();
}


void FilterRemoveNaN::on_btn_subSample_clicked()
{
    float size_sub = ui->dSpinBox_subsample->value();

    //create passtrhough filter
    pcl::VoxelGrid<PointT> voxel_grid;

    voxel_grid.setInputCloud(_cloudSrc);

    //set cell/voxel size to x.x meters in each dimension
    voxel_grid.setLeafSize(size_sub, size_sub,size_sub);
    voxel_grid.filter(*_cloudFinal);

    emit signalFinishFilter();
}
