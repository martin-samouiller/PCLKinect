#include "filters.h"
#include "../build/ui_filters.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QtDebug>
#include <QWidget>

#include <pcl/io/openni_grabber.h>
#include <pcl/io/pcd_io.h>
#include <pcl/exceptions.h>

#include "filterremovenan.h"
#include "filterpassthrough.h"
#include "filternoise.h"


Filters::Filters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Filters)
{
    ui->setupUi(this);

    QStringList _listFilters;

    _listFilters << QString("PASS THROUGH");
    _listFilters << QString("REMOVE NAN");
    _listFilters << QString("REMOVE NOISE");

    ui->comboBox_FiltersType->addItems(_listFilters);

    _cloudFinal.reset (new PointCloudT);


    viewerCloudResult.reset (new pcl::visualization::PCLVisualizer ("CloudFilter", false));
    ui->qvtk_ViewerCloud->SetRenderWindow (viewerCloudResult->getRenderWindow());
    viewerCloudResult->setupInteractor (ui->qvtk_ViewerCloud->GetInteractor(), ui->qvtk_ViewerCloud->GetRenderWindow());
    viewerCloudResult->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloudResult->getRenderWindow()->Render();
    viewerCloudResult->setBackgroundColor (0.1, 0.1, 0.1);
    viewerCloudResult->initCameraParameters ();
    viewerCloudResult->addPointCloud (_cloudFinal, "scene_cloud");
    viewerCloudResult->resetCamera();
    ui->qvtk_ViewerCloud->update();

}

Filters::~Filters()
{
    delete ui;
}


void
Filters::init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName)
{
    //Maj des items à partir des données des nuages de points
    ui->comboBox_Clouds->addItems(_listCloud);
    m_listCloudsPtr = _listCloudPtr;
    m_listCloudsName = _listCloudsName;

    on_comboBox_Clouds_currentIndexChanged(ui->comboBox_Clouds->itemText(ui->comboBox_Clouds->currentIndex()));
    on_comboBox_FiltersType_currentIndexChanged(ui->comboBox_FiltersType->itemText(ui->comboBox_FiltersType->currentIndex()));
}

void
Filters::on_comboBox_FiltersType_currentIndexChanged(const QString &arg1)
{

    if(arg1.compare("PASS THROUGH") == 0)
        _eTypeFiltrage = PASS_THROUGH;
    if(arg1.compare("REMOVE NAN") == 0)
        _eTypeFiltrage = REMOVE_NAN ;
    if(arg1.compare("REMOVE NOISE") == 0)
        _eTypeFiltrage = REMOVE_NOISE ;

    if(_eTypeFiltrage == PASS_THROUGH)
    {
        QWidget *wi = ui->scrollArea_FiltersType->widget();
        delete wi;

        FilterPassThrough * filterPassThrough = new FilterPassThrough();
        filterPassThrough->init(_cloudSource, _cloudFinal);
        ui->scrollArea_FiltersType->setWidget(filterPassThrough);
        filterPassThrough->show();
        connect(filterPassThrough, SIGNAL(signalFinishFilter()), this, SLOT(slotFinishFilter()));


    }
    else if(_eTypeFiltrage == REMOVE_NAN)
    {
        FilterRemoveNaN * filterNan = new FilterRemoveNaN();
        filterNan->init(_cloudSource, _cloudFinal);
        ui->scrollArea_FiltersType->setWidget(filterNan);
        filterNan->show();
        connect(filterNan, SIGNAL(signalFinishFilter()), this, SLOT(slotFinishFilter()));
    }
    else if(_eTypeFiltrage == REMOVE_NOISE)
    {
        QWidget *wi = ui->scrollArea_FiltersType->widget();
        delete wi;

        FilterNoise * filternoise = new FilterNoise();
        filternoise->init(_cloudSource, _cloudFinal);
        ui->scrollArea_FiltersType->setWidget(filternoise);
        filternoise->show();
        connect(filternoise, SIGNAL(signalFinishFilter()), this, SLOT(slotFinishFilter()));

    }
    else
    {
         QMessageBox::warning(this, tr("Texture"),  tr("Choisir une technique de registration") , QMessageBox::Ok);
    }

}

void
Filters::on_btn_saveCloud_clicked()
{
    try {
        QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Could (*.pcd)");
        if(_cloudFinal != NULL && fichier != NULL && fichier != "")
             pcl::io::savePCDFileASCII(fichier.toStdString(), *_cloudFinal);

    }
    catch (pcl::PCLException e)
    {
        QMessageBox::warning(this, tr("Acquisition"), e.what(), QMessageBox::Ok);
    }
}


void
Filters::on_comboBox_Clouds_currentIndexChanged(const QString &arg1)
{
    qDebug() << "value map : " << QString::fromStdString(m_listCloudsName[arg1.toStdString()]) ;

    _cloudSource.reset (new PointCloudT);

    if(m_listCloudsPtr.empty()){
        qDebug() << "Enmpty list : return on_comboBox_Source_currentIndexChanged";
        return ;
    }

    PointCloudC::Ptr cloud = m_listCloudsPtr[arg1.toStdString()];

    try{
        pcl::copyPointCloud(*cloud, *_cloudSource);
    }catch (pcl::PCLException e){
        QMessageBox::warning(this, tr("Texture"),  tr("Impossible de copier le nuage de points") , QMessageBox::Ok);
    }

    if(_cloudSource != NULL){
        qDebug() << "cloud != null , update point cloud  ";
        qDebug() << "Size : " << QString::number(_cloudSource->points.size());
    }
}



void
Filters::slotFinishFilter()
{
    qDebug() << "\n Size : " << QString::number(_cloudFinal->points.size());

    viewerCloudResult->updatePointCloud (_cloudFinal, "scene_cloud");
    //viewerCloudResult->spinOnce();
    //viewerCloudResult->removePointCloud("scene_cloud");

    ui->qvtk_ViewerCloud->update ();

}
