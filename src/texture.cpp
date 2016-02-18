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
    majParameters();

    ui->dspinBox_MaxAngle->setMaximum(2*M_PI);
    ui->dspinBox_MaximunSurf->setMaximum(2*M_PI);
    ui->dspinBox_MinAngle->setMaximum(2*M_PI);

}

Texture::~Texture()
{
    delete ui;
}




void Texture::on_btn_texture_clicked()
{
    ui->btn_LED->setStyleSheet("background-color: red;");
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




void Texture::eventSlotValueTriangle(){

    viewerTexture->removePolygonMesh("mesh triangle" );
    qDebug() << "Event Slot : triangle reçu";
    _trianglesSave = *_ThreadTexture.getTriangles();
    viewerTexture->addPolygonMesh(_trianglesSave, "mesh triangle" );
    ui->qvtkTexture->update();
    ui->btn_LED->setStyleSheet("background-color: green;");
}


void Texture::on_spinBox_KSearch_valueChanged(int arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_dspinBox_Mu_valueChanged(double arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_dspinBox_MaximunSurf_valueChanged(double arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_dspinBox_MinAngle_valueChanged(double arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_dspinBox_MaxAngle_valueChanged(double arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_doubleSpinBox_RadiuSearch_valueChanged(double arg1)
{
    majParameters();
    majInfosAngles();
}

void Texture::on_spinBox_MaxNearest_valueChanged(int arg1)
{
     majParameters();
     majInfosAngles();
}

void Texture::majParameters(){
   // qDebug() << "radius : " << arg1;
   // qDebug() << "Max nearest : " << arg1;
    _ThreadTexture.setRadiusSearch(ui->doubleSpinBox_RadiuSearch->value());
    _ThreadTexture.setMaxNearest(ui->spinBox_MaxNearest->value());
    _ThreadTexture.setKSearch(ui->spinBox_KSearch->value());
    _ThreadTexture.setMaxAngle(ui->dspinBox_MaxAngle->value());
    _ThreadTexture.setMinAngle(ui->dspinBox_MinAngle->value());
    _ThreadTexture.setMu(ui->dspinBox_Mu->value());
    _ThreadTexture.setMaxSurfaceAngle(ui->dspinBox_MaximunSurf->value());
}

void Texture::majInfosAngles(){

    QString msgAngle = "";
    msgAngle.append("Max angle : "); msgAngle.append(QString::number((ui->dspinBox_MaxAngle->value()*180.0) / M_PI)); msgAngle.append("° \n");
    msgAngle.append("Min angle : "); msgAngle.append(QString::number((ui->dspinBox_MinAngle->value()*180.0) / M_PI)); msgAngle.append("° \n");
    msgAngle.append("Max Surface angle : "); msgAngle.append(QString::number((ui->dspinBox_MaximunSurf->value()*180.0) / M_PI)); msgAngle.append("° \n");
    ui->lbl_Infos->setText(msgAngle);

}





