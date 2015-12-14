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



}

Texture::~Texture()
{
    delete ui;
}




void Texture::on_btn_texture_clicked()
{
   boost::thread t(&Texture::cloudReconstructionMesh,this, this);
   t.join();

  //t.start_thread();
}



void Texture::on_btn_saveTexture_clicked()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Mesh (*.vtk)");
    if(fichier != NULL && fichier != "")
         pcl::io::saveVTKFile(fichier.toStdString(), _triangles);

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

void Texture::cloudReconstructionMesh(Texture *parent)
{

   // parent->ui->progressBar->setValue(0.1);
    // Load input file into a PointCloud<T> with an appropriate type
    //* the data should be available in cloud

    // Normal estimation*
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
    pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud (cloudText);
    n.setInputCloud (cloudText);
    n.setSearchMethod (tree);
    n.setKSearch (20);
    n.compute (*normals);
    //* normals should not contain the point normals + surface curvatures

    // Concatenate the XYZ and normal fields*
    pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
    pcl::concatenateFields (*cloudText, *normals, *cloud_with_normals);
    //* cloud_with_normals = cloud + normals

    // Create search tree*
    pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
    tree2->setInputCloud (cloud_with_normals);

    // Initialize objects
    pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;

    // Set the maximum distance between connected points (maximum edge length)
    gp3.setSearchRadius (parent->ui->doubleSpinBox_RadiuSearch->value());

    // Set typical values for the parameters
    gp3.setMu (2.5);
    gp3.setMaximumNearestNeighbors (parent->ui->spinBox_MaxNearest->value());
    gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
    gp3.setMinimumAngle(M_PI/18); // 10 degrees
    gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
    gp3.setNormalConsistency(false);

    // Get result
    gp3.setInputCloud (cloud_with_normals);
    gp3.setSearchMethod (tree2);
    gp3.reconstruct (_triangles);

    // Additional vertex information
    std::vector<int> parts = gp3.getPartIDs();
    std::vector<int> states = gp3.getPointStates();

    parent->getQVTKWidgetTexture()->update();
    parent->getVisualizerTexture()->addPolygonMesh(_triangles);

}

boost::shared_ptr<pcl::visualization::PCLVisualizer> Texture::getVisualizerTexture()
{
    return viewerTexture;
}

QVTKWidget* Texture::getQVTKWidgetTexture(){
    return ui->qvtkTexture;
}
