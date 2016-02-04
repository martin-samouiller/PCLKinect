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

#include <QVTKWidget.h>

#include "texturethread.h"

#include "defineType.h"

using namespace pcl;
using namespace std;


namespace Ui {
class Texture;
}

class Texture : public QWidget
{
    Q_OBJECT

public:
    explicit Texture(QWidget *parent = 0);
    ~Texture();
    void
    init(QStringList _listCloud , DictionaryCloudPtr _listCloudPtr , DictionaryCloudName _listCloudsName); //Initialise l'outil de mesh avec un nuage de point

private slots:
    void
    on_btn_texture_clicked();

    void
    on_btn_saveTexture_clicked();

    void
    on_comboBox_currentIndexChanged(const QString &arg1);

    boost::shared_ptr<pcl::visualization::PCLVisualizer>
    getVisualizerTexture();

    QVTKWidget*
    getQVTKWidgetTexture();

    void
    on_doubleSpinBox_RadiuSearch_valueChanged(double arg1);

    void
    on_spinBox_MaxNearest_valueChanged(int arg1);

    void
    eventSlotValueTriangle();

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerCloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerTexture;
    PointCloudT::Ptr cloudText;
   // void cloudReconstructionMesh(Texture *parent);

private:
    Ui::Texture *ui;
    pcl::PolygonMesh _trianglesSave;
    TextureThread _ThreadTexture;
    DictionaryCloudPtr m_listCloudsPtr;
    DictionaryCloudName m_listCloudsName;

};

#endif // TEXTURE_H

