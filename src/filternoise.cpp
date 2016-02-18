#include "filternoise.h"
#include "../build/ui_filternoise.h"

#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

/*
 * Le nombre de voisins analyser pour chaque élément est fixé à 50 , et l'écart type à 1.
 * Ce que cela signifie  est que tous les points qui ont une distance supérieure à 1 écart-type de la distance moyenne à l' élément de requête sera marqué comme aberrantes et enlevé.
 * La sortie est calculée et stockée dans cloud_filtered
 * */

///Classe permettant de supprimer le bruit dans un nuage de point

FilterNoise::FilterNoise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterNoise)
{
    ui->setupUi(this);
}

FilterNoise::~FilterNoise()
{
    delete ui;
}

void
FilterNoise::init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal)
{
    _cloudSrc = cloudSrc;
    _cloudFinal = cloudFinal;
}


void
FilterNoise::startTraitement()
{
    pcl::copyPointCloud(*_cloudSrc, *_cloudFinal);
    _meanK = ui->spinBox_MeanK->value();
    stddevMul = ui->dSpinBox_StdMulThresh->value();

    // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (_cloudSrc);
  sor.setMeanK (_meanK);
  sor.setStddevMulThresh (stddevMul);
  sor.filter (*_cloudFinal);



  emit signalFinishFilter();

}

void FilterNoise::on_btn_start_clicked()
{
    startTraitement();
}
