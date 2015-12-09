#include "pclacquisition.h"
#include "../build/ui_pclacquisition.h"
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include "texture.h"
#include "acquisitionwindows.h"
#include "cloudwindows.h"

#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QListView>




using namespace pcl;
using namespace std;

PCLAcquisition::PCLAcquisition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCLAcquisition)
{
    ui->setupUi(this);

    m_iSDeviceConnect = false;

    // Create model
    model = new QStringListModel(this);
    ui->listView_Clouds->setModel(model);
    connect(ui->listView_Clouds->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(on_listClouds_current_change(QModelIndex, QModelIndex)));
    m_lastPathCloud = "";
}

PCLAcquisition::~PCLAcquisition()
{
    delete ui;
}


///Enregistre le nuage de point dans le fichier demandé
void
PCLAcquisition::on_actionSave_triggered()
{
   /* try {
        QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Could (*.pcd)");
        if(cloudSave != NULL && fichier != NULL && fichier != "")
             pcl::io::savePCDFileASCII(fichier.toStdString(), *cloudSave);
    }
    catch (exception e){
       qDebug() << e.what();
    }*/

}



void
PCLAcquisition::on_actionOpen_triggered()
{

    PointCloudC::Ptr cloudLoad(new PointCloudC);
    QString fichier = QFileDialog::getOpenFileName(this, "Load File", m_lastPathCloud, "Could (*.pcd)");
    m_lastPathCloud = fichier;

    //Fill list "cloud.pcd , /home/martin/Documents/cloud.pcd" : permet de retrouver ou se trouve le point
    boost::filesystem::path my_path( fichier.toStdString());
    std::string name = my_path.filename().string();
    listClouds[name] = fichier.toStdString();

    m_strlistCloud << QString::fromStdString(name);
    // Populate our model
    model->setStringList(m_strlistCloud);
    // Glue model and view together



    if (pcl::io::loadPCDFile<pcl::PointXYZRGB> (fichier.toStdString(), *cloudLoad) == -1) //* load the file
     {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return;
     }

    //Rempli les données name, path, dans la fenêtre qui contient les nuages de points
    CloudWindows *cloudWind = new CloudWindows();
    ui->mdiArea_cloud->addSubWindow(cloudWind);
    cloudWind->init(cloudLoad, name); //Chaque fenêtre a son propre nom
    cloudWind->setWindowTitle(QString::fromStdString(name));
    cloudWind->setWindowFilePath(QString::fromStdString(my_path.filename().string()));
    cloudWind->show();


    return;

}



void PCLAcquisition::on_actionStart_triggered()
{
    AcquisitionWindows *ui_acquisition = new AcquisitionWindows();
    ui_acquisition->show();
}

/*

//Mise à jour des nuages des points et des viwer en fonction de la LUT et de l'axe paramètré
void
PCLAcquisition::updateCloudViewer(){

    if(widgetCloudCurrent != NULL && viewerCloudCurrent != NULL ){
               colorCloudDistances (cloudCurrent);
               viewerCloudCurrent->updatePointCloud (cloudCurrent, "cloud");
               widgetCloudCurrent->update();
    }

}
*/


void PCLAcquisition::on_actionTexture_triggered()
{
    Texture *uiTexture = new Texture();
    uiTexture->init(m_strlistCloud);
    uiTexture->show();
}

void PCLAcquisition::on_actionFiltrer_triggered()
{

}

void PCLAcquisition::on_actionICP_triggered()
{

}

void PCLAcquisition::on_listClouds_current_change(QModelIndex cur, QModelIndex pre)
{
    if(pre.row() != -1) {
            // do stuff
    }

}
