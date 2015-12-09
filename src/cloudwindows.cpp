#include "cloudwindows.h"
#include "../build/ui_cloudwindows.h"

#include <QDebug>

CloudWindows::CloudWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloudWindows)
{
    ui->setupUi(this);
    nbr_windows++;


    // Connect X,Y,Z radio buttons and their functions
    connect (ui->radioButton_X, SIGNAL(clicked ()), this, SLOT(axisChosen ()));
    connect (ui->radioButton_Y, SIGNAL(clicked ()), this, SLOT(axisChosen ()));
    connect (ui->radioButton_Z, SIGNAL(clicked ()), this, SLOT(axisChosen ()));

    connect (ui->radioButton_bluered, SIGNAL(clicked ()), this, SLOT(lookUpTableChosen()));
    connect (ui->radioButton_greenmagenta, SIGNAL(clicked ()), this, SLOT(lookUpTableChosen()));
    connect (ui->radioButton_whitered, SIGNAL(clicked ()), this, SLOT(lookUpTableChosen()));
    connect (ui->radioButton_grayred, SIGNAL(clicked ()), this, SLOT(lookUpTableChosen()));
    connect (ui->radioButton_rainbow, SIGNAL(clicked ()), this, SLOT(lookUpTableChosen()));

    ui->radioButton_X->setChecked(true);
    ui->radioButton_bluered->setChecked(true);
}

CloudWindows::~CloudWindows()
{
    nbr_windows--;

    if(_cloud != NULL)
        _cloud.reset();

    if(_cloudColor != NULL)
        _cloudColor.reset();

    delete ui;
}

/*Initialise le widget avec un nuage de point n&b*/
/*void CloudWindows::init(PointCloudT::Ptr cloud){

    _cloud = cloud;
    colorCloud = false;

    viewerCloud.reset (new pcl::visualization::PCLVisualizer ("viewer", false));

    ui->widgetCloud->SetRenderWindow (viewerCloud->getRenderWindow());
    viewerCloud->setupInteractor (ui->widgetCloud->GetInteractor(), ui->widgetCloud->GetRenderWindow());
    viewerCloud->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloud->getRenderWindow()->Render();
    viewerCloud->setBackgroundColor (0.1, 0.1, 0.1);
    viewerCloud->addCoordinateSystem (1.0);
    viewerCloud->addPointCloud(_cloud, "cloud");
    viewerCloud->resetCamera ();

    if(cloud != NULL){
        viewerCloud->updatePointCloud (_cloud, "cloud");
        ui->widgetCloud->update();

    }

    ui->widgetCloud->show();

    return;

}*/

/*Initialise le widget avec un nuage de point couleur*/
void CloudWindows::init(PointCloudC::Ptr cloud, std::string nameCloud){

    _cloudColor = cloud;
    colorCloud = true;

    viewerCloud.reset (new pcl::visualization::PCLVisualizer ("viewer", false));

    ui->widgetCloud->SetRenderWindow (viewerCloud->getRenderWindow());
    viewerCloud->setupInteractor (ui->widgetCloud->GetInteractor(), ui->widgetCloud->GetRenderWindow());
    viewerCloud->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloud->getRenderWindow()->Render();
    viewerCloud->setBackgroundColor (0.1, 0.1, 0.1);
    //viewerCloud->setBackgroundColor (1, 1, 1);
    viewerCloud->addCoordinateSystem (1.0);
    viewerCloud->addPointCloud(_cloudColor, "cloud");
    viewerCloud->resetCamera ();
    ui->widgetCloud->setWindowTitle(QString::fromStdString(nameCloud));
    if(cloud != NULL){
        viewerCloud->updatePointCloud (_cloudColor, "cloud");
        ui->widgetCloud->update();

    }

    pcl::PCLHeader header = _cloudColor->header;
    ui->label_infos->setText("Cloud size : " + QString::number(_cloudColor->points.size()) + "  Frame  id : " +  QString(header.frame_id.c_str()) + " Sequence : " +  QString::number(header.seq) + " Stamp : " +  QString::number(header.stamp));

    ui->widgetCloud->show();



    return;

}

void
CloudWindows::axisChosen ()
{
  // Only 1 of the button can be checked at the time (mutual exclusivity) in a group of radio buttons
  if (ui->radioButton_X->isChecked ())
  {
    PCL_INFO("x filtering chosen\n");
    filtering_axis_ = 0;
  }
  else if (ui->radioButton_Y->isChecked ())
  {
    PCL_INFO("y filtering chosen\n");
    filtering_axis_ = 1;
  }
  else
  {
    PCL_INFO("z filtering chosen\n");
    filtering_axis_ = 2;
  }

  updateCloudViewer();
}


void
CloudWindows::lookUpTableChosen ()
{
  // Only 1 of the button can be checked at the time (mutual exclusivity) in a group of radio buttons
  if (ui->radioButton_bluered->isChecked ())
  {
    PCL_INFO("Blue -> Red LUT chosen\n");
    color_mode_ = 0;
  }
  else if (ui->radioButton_greenmagenta->isChecked ())
  {
    PCL_INFO("Green -> Magenta LUT chosen\n");
    color_mode_ = 1;
  }
  else if (ui->radioButton_whitered->isChecked ())
  {
    PCL_INFO("White -> Red LUT chosen\n");
    color_mode_ = 2;
  }
  else if (ui->radioButton_grayred->isChecked ())
  {
    PCL_INFO("Grey / Red LUT chosen\n");
    color_mode_ = 3;
  }
  else
  {
    PCL_INFO("Rainbow LUT chosen\n");
    color_mode_ = 4;
  }

  updateCloudViewer();
}

void
CloudWindows::colorCloudDistances (PointCloudC::Ptr cloud_)
{
  // Find the minimum and maximum values along the selected axis
  double min, max;
  // Set an initial value
  switch (filtering_axis_)
  {
    case 0:  // x
      min = cloud_->points[0].x;
      max = cloud_->points[0].x;
      break;
    case 1:  // y
      min = cloud_->points[0].y;
      max = cloud_->points[0].y;
      break;
    default:  // z
      min = cloud_->points[0].z;
      max = cloud_->points[0].z;
      break;
  }

  // Search for the minimum/maximum
  for (PointCloudC::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    switch (filtering_axis_)
    {
      case 0:  // x
        if (min > cloud_it->x)
          min = cloud_it->x;

        if (max < cloud_it->x)
          max = cloud_it->x;
        break;
      case 1:  // y
        if (min > cloud_it->y)
          min = cloud_it->y;

        if (max < cloud_it->y)
          max = cloud_it->y;
        break;
      default:  // z
        if (min > cloud_it->z)
          min = cloud_it->z;

        if (max < cloud_it->z)
          max = cloud_it->z;
        break;
    }
  }

  // Compute LUT scaling to fit the full histogram spectrum
  double lut_scale = 255.0 / (max - min);  // max is 255, min is 0

  if (min == max)  // In case the cloud is flat on the chosen direction (x,y or z)
    lut_scale = 1.0;  // Avoid rounding error in boost

  qDebug() << "lut scale" << lut_scale;
  qDebug() << "Min " << min;
  qDebug() << "Max " << max;

  for (PointCloudC::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    int value = 0;
    switch (filtering_axis_)
    {
      case 0:  // x
        //value = boost::math::iround ( (cloud_it->x - min) * lut_scale);  // Round the number to the closest integer
        value = (cloud_it->x - min) * lut_scale;
        break;
      case 1:  // y
        //value = boost::math::iround ( (cloud_it->y - min) * lut_scale);
         value = (cloud_it->y - min) * lut_scale;
        break;
      default:  // z
        //value = boost::math::iround ( (cloud_it->z - min) * lut_scale);
         value = (cloud_it->z - min) * lut_scale;
        break;
    }

    // Apply color to the cloud
    switch (color_mode_)
    {
      case 0:
        // Blue (= min) -> Red (= max)
        cloud_it->r = value;
        cloud_it->g = 0;
        cloud_it->b = 255 - value;
        break;
      case 1:
        // Green (= min) -> Magenta (= max)
        cloud_it->r = value;
        cloud_it->g = 255 - value;
        cloud_it->b = value;
        break;
      case 2:
        // White (= min) -> Red (= max)
        cloud_it->r = 255;
        cloud_it->g = 255 - value;
        cloud_it->b = 255 - value;
        break;
      case 3:
        // Grey (< 128) / Red (> 128)
        if (value > 128)
        {
          cloud_it->r = 255;
          cloud_it->g = 0;
          cloud_it->b = 0;
        }
        else
        {
          cloud_it->r = 128;
          cloud_it->g = 128;
          cloud_it->b = 128;
        }
        break;
      default:
        // Blue -> Green -> Red (~ rainbow)
        cloud_it->r = value > 128 ? (value - 128) * 2 : 0;  // r[128] = 0, r[255] = 255
        cloud_it->g = value < 128 ? 2 * value : 255 - ( (value - 128) * 2);  // g[0] = 0, g[128] = 255, g[255] = 0
        cloud_it->b = value < 128 ? 255 - (2 * value) : 0;  // b[0] = 255, b[128] = 0
    }
  }



}

//Mise à jour des nuages des points et des viwer en fonction de la LUT et de l'axe paramètré
void
CloudWindows::updateCloudViewer(){

   colorCloudDistances (_cloudColor);
   viewerCloud->updatePointCloud (_cloudColor, "cloud");
   ui->widgetCloud->update();

}

/*

// Try with color information...
        try
        {
            io::loadPCDFile<PointXYZRGBA>(filename.c_str(), *cloudptr);
        }
        catch (PCLException e1)
        {
            try
            {
                // ...and if it fails, fall back to just depth.
                io::loadPCDFile<PointXYZ>(filename.c_str(), *fallbackCloud);
            }
            catch (PCLException e2)
            {
                return -1;
            }

            noColor = true;
        }

        cout << "Loaded " << filename << "." << endl;
        if (noColor)
            cout << "This cloud has no RGBA color information present." << endl;
        else cout << "This cloud has RGBA color information present." << endl;



 * */
