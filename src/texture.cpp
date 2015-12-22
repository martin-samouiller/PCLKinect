#include "texture.h"
#include "../build/ui_texture.h"
#include "boost/thread.hpp"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

#include<pcl/point_types_conversion.h>

Texture::Texture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Texture)
{
    ui->setupUi(this);


    // Setup the cloud pointer
    cloudText.reset (new PointCloudT);
    viewerCloud.reset (new pcl::visualization::PCLVisualizer ("Cloud", false));
    ui->qvtkcloud->SetRenderWindow (viewerCloud->getRenderWindow());
    viewerCloud->setupInteractor (ui->qvtkcloud->GetInteractor(), ui->qvtkcloud->GetRenderWindow());
    viewerCloud->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloud->getRenderWindow()->Render();
    viewerCloud->setBackgroundColor (0.1, 0.1, 0.1);
    viewerCloud->addCoordinateSystem (1.0);
    viewerCloud->initCameraParameters ();
    viewerCloud->resetCamera();
    viewerCloud->addPointCloud(cloudText, "cloud");
    ui->qvtkcloud->update();

    // Setup the cloud pointer
    viewerTexture.reset (new pcl::visualization::PCLVisualizer ("Texture", false));
    ui->qvtkTexture->SetRenderWindow (viewerTexture->getRenderWindow());
    viewerTexture->setupInteractor (ui->qvtkTexture->GetInteractor(), ui->qvtkTexture->GetRenderWindow());
    viewerTexture->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerTexture->getRenderWindow()->Render();
    viewerTexture->setBackgroundColor (0.1, 0.1, 0.1);
    viewerTexture->initCameraParameters ();
    viewerTexture->resetCamera();
    ui->qvtkTexture->update();


    connect(&_ThreadTexture, SIGNAL(valueChangedMesh()), this, SLOT(eventSlotValueTriangle()));

    //Mise a jour sinon les paramètres sont = 0 et le meshing plante
    _ThreadTexture.setRadiusSearch(ui->doubleSpinBox_RadiuSearch->value());
    _ThreadTexture.setMaxNearest(ui->spinBox_MaxNearest->value());



}

Texture::~Texture()
{
    delete ui;
}




void Texture::on_btn_texture_clicked()
{
    //Cloud a utiliser pour faire le mesh
    _ThreadTexture.setCloud(cloudText);
    _ThreadTexture.start();
}



void Texture::on_btn_saveTexture_clicked()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Mesh (*.vtk)");
    if(fichier != NULL && fichier != "")
         pcl::io::saveVTKFile(fichier.toStdString(), _trianglesSave);

}


void Texture::init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName)
{
    //Maj des items à partir des données des nuages de points
    ui->comboBox->addItems(_listCloud);
    m_listCloudsPtr = _listCloudPtr;
    m_listCloudsName = _listCloudsName;


    on_comboBox_currentIndexChanged(ui->comboBox->itemText(ui->comboBox->currentIndex()));

}



void Texture::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug() << "value map : " << QString::fromStdString(m_listCloudsName[arg1.toStdString()]) ;

    if(m_listCloudsPtr.empty()){
        qDebug() << "return ";
        return ;
    }

    PointCloudC::Ptr cloud = m_listCloudsPtr[arg1.toStdString()];
    pcl::copyPointCloud(*cloud, *cloudText);
    if(cloudText != NULL){
        qDebug() << "cloud != null , update point cloud  ";
        qDebug() << "Size : " << QString::number(cloudText->points.size());
        try{
            viewerCloud->updatePointCloud (cloudText, "cloud");
            ui->qvtkcloud->update();
        }catch (PCLException ex){
             QMessageBox::warning(this, tr("Texture"),  tr("Impossible de charger le nuage de points") , QMessageBox::Ok);
        }
    }
}


boost::shared_ptr<pcl::visualization::PCLVisualizer> Texture::getVisualizerTexture()
{
    return viewerTexture;
}

QVTKWidget* Texture::getQVTKWidgetTexture(){
    return ui->qvtkTexture;
}

void Texture::on_doubleSpinBox_RadiuSearch_valueChanged(double arg1)
{
    qDebug() << "radius : " << arg1;
    _ThreadTexture.setRadiusSearch(arg1);
}

void Texture::on_spinBox_MaxNearest_valueChanged(int arg1)
{
     qDebug() << "Max nearest : " << arg1;
    _ThreadTexture.setMaxNearest(arg1);
}

void Texture::eventSlotValueTriangle(){
    qDebug() << "Event Slot : triangle reçu";
    _trianglesSave = *_ThreadTexture.getTriangles();
    viewerTexture->addPolygonMesh(_trianglesSave);
    ui->qvtkTexture->update();
}

