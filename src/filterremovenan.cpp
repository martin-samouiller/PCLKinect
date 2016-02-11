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

}
