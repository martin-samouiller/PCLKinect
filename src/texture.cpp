#include "texture.h"
#include "../build/ui_texture.h"

#include <QFileDialog>
#include <QDebug>

Texture::Texture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Texture)
{
    ui->setupUi(this);


    // Setup the cloud pointer
    /*cloudText.reset (new PointCloudNB);
    viewerCloud.reset (new pcl::visualization::PCLVisualizer ("Cloud", false));
    ui->qvtkcloud->SetRenderWindow (viewerCloud->getRenderWindow());
    viewerCloud->setupInteractor (ui->qvtkcloud->GetInteractor(), ui->qvtkcloud->GetRenderWindow());
    viewerCloud->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloud->getRenderWindow()->Render();
    viewerCloud->setBackgroundColor (0.1, 0.1, 0.1);
    viewerCloud->initCameraParameters ();
    ui->qvtkcloud->update();*/

    // Setup the cloud pointer
   /* viewerTexture.reset (new pcl::visualization::PCLVisualizer ("Texture", false));
    ui->qvtkTexture->SetRenderWindow (viewerTexture->getRenderWindow());
    viewerTexture->setupInteractor (ui->qvtkTexture->GetInteractor(), ui->qvtkTexture->GetRenderWindow());
    viewerTexture->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerTexture->getRenderWindow()->Render();
    viewerTexture->setBackgroundColor (0.1, 0.1, 0.1);
    viewerTexture->initCameraParameters ();
    ui->qvtkTexture->update();*/

}

Texture::~Texture()
{
    delete ui;
}


/*
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
*/

/*
void Texture::on_btn_saveTexture_clicked()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Mesh (*.vtk)");
    if(fichier != NULL && fichier != "")
         pcl::io::saveVTKFile(fichier.toStdString(), triangles);
    // Save to disk.

}
*/

void Texture::init(QStringList _listCloud)
{
    //Maj des items à partir des données des nuages de points
    ui->comboBox->addItems(_listCloud);
}
