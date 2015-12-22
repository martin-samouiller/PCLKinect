#ifndef TEXTURETHREAD_H
#define TEXTURETHREAD_H

#include <QThread>


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

#include <QVTKWidget.h>

using namespace pcl;
using namespace std;

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

typedef pcl::PointXYZRGB PointC;
typedef pcl::PointCloud<PointC> PointCloudC;


class TextureThread : public QThread
{
    Q_OBJECT
public:
    TextureThread();
    void
    run();
    void
    setMaxNearest(int maxNearest)          {_maxNearest = maxNearest ; }
    void
    setRadiusSearch(double radiusSearch)   {_radiuSearch = radiusSearch ;}
    void
    setCloud(PointCloudT::Ptr cloudText)   {_cloudText = cloudText ;}
    pcl::PolygonMesh *
    getTriangles()                         { return &_triangles ;}

signals:
    void valueChangedMesh() ;

private:
    // Object for storing the normals.
    pcl::PointCloud<pcl::Normal>::Ptr _normals;
    // Object for storing both the points and the normals.
    pcl::PointCloud<pcl::PointNormal>::Ptr _cloudNormals;
    pcl::PolygonMesh _triangles;
    PointCloudT::Ptr _cloudText;
    int  _maxNearest = 0;
    double _radiuSearch = 0.0;

};

#endif // TEXTURETHREAD_H
