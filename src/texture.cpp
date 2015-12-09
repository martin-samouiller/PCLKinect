#include "texture.h"
#include "../build/ui_texture.h"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

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
    // Object for storing the normals.
    normals = pcl::PointCloud<pcl::Normal>::Ptr(new pcl::PointCloud<pcl::Normal>);
    // Object for storing both the points and the normals.
    cloudNormals = pcl::PointCloud<pcl::PointNormal>::Ptr (new pcl::PointCloud<pcl::PointNormal>);

     pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);

    // Normal estimation.
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normalEstimation;
    normalEstimation.setInputCloud(cloudText);
    normalEstimation.setRadiusSearch(0.03);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZ>);
    normalEstimation.setSearchMethod(kdtree);
    normalEstimation.compute(*normals);

    // The triangulation object requires the points and normals to be stored in the same structure.
    pcl::concatenateFields(*cloudText, *normals, *cloudNormals);
    // Tree object for searches in this new object.
    pcl::search::KdTree<pcl::PointNormal>::Ptr kdtree2(new pcl::search::KdTree<pcl::PointNormal>);
    kdtree2->setInputCloud(cloudNormals);

    // Triangulation object.
    pcl::GreedyProjectionTriangulation<pcl::PointNormal> triangulation;
    // Output object, containing the mesh.

    // Maximum distance between connected points (maximum edge length).
    triangulation.setSearchRadius(0.025);
    // Maximum acceptable distance for a point to be considered,
    // relative to the distance of the nearest point.
    triangulation.setMu(2.5);
    // How many neighbors are searched for.
    triangulation.setMaximumNearestNeighbors(100);
    // Points will not be connected to the current point
    // if their normals deviate more than the specified angle.
    triangulation.setMaximumSurfaceAngle(M_PI / 4); // 45 degrees.
    // If false, the direction of normals will not be taken into account
    // when computing the angle between them.
    triangulation.setNormalConsistency(false);
    // Minimum and maximum angle there can be in a triangle.
    // The first is not guaranteed, the second is.
    triangulation.setMinimumAngle(M_PI / 18); // 10 degrees.
    triangulation.setMaximumAngle(2 * M_PI / 3); // 120 degrees.

    // Triangulate the cloud.
    triangulation.setInputCloud(cloudNormals);
    triangulation.setSearchMethod(kdtree2);
    triangulation.reconstruct(triangles);
}



void Texture::on_btn_saveTexture_clicked()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Mesh (*.vtk)");
    if(fichier != NULL && fichier != "")
         pcl::io::saveVTKFile(fichier.toStdString(), triangles);
    // Save to disk.

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
    if(cloud != NULL){
        qDebug() << "cloud != null , update point cloud  ";
        qDebug() << "Size : " << QString::number(cloud->points.size());
        try{
            viewerCloud->updatePointCloud (cloud, "cloud");
            ui->qvtkcloud->update();
        }catch (PCLException ex){
             QMessageBox::warning(this, tr("Texture"),  tr("Impossible de charger le nuage de points") , QMessageBox::Ok);
        }


    }
}


