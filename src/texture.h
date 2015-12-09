#ifndef TEXTURE_H
#define TEXTURE_H

#include <QWidget>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/console/parse.h>
#include <pcl/common/time.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/vtk_io.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtk3DWidget.h>

using namespace pcl;
using namespace std;

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

typedef pcl::PointXYZRGB PointC;
typedef pcl::PointCloud<PointC> PointCloudC;
typedef std::map< std::string, boost::shared_ptr<PointCloudC> > DictionaryCloudPtr;
typedef std::map< std::string, std::string > DictionaryCloudName;

namespace Ui {
class Texture;
}

class Texture : public QWidget
{
    Q_OBJECT

public:
    explicit Texture(QWidget *parent = 0);
    ~Texture();
    void init(QStringList _listCloud , DictionaryCloudPtr _listCloudPtr , DictionaryCloudName _listCloudsName); //Initialise l'outil de mesh avec un nuage de point

private slots:
    void on_btn_texture_clicked();
    void on_btn_saveTexture_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerCloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerTexture;
    PointCloudT::Ptr cloudText;

private:
    Ui::Texture *ui;
    // Object for storing the normals.
    pcl::PointCloud<pcl::Normal>::Ptr normals;
    // Object for storing both the points and the normals.
    pcl::PointCloud<pcl::PointNormal>::Ptr cloudNormals;
    pcl::PolygonMesh triangles;

    DictionaryCloudPtr m_listCloudsPtr;
    DictionaryCloudName m_listCloudsName;

};

#endif // TEXTURE_H
