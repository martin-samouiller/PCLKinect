#include "icpthread.h"

#include <pcl/io/pcd_io.h>
#include <pcl/registration/icp.h>
#include <pcl/register_point_struct.h>
#include <pcl/registration/registration.h>


using namespace registration;

icpthread::icpthread()
{





}

void icpthread::run(){

     Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity ();

    // Objects for storing the point clouds.
    pcl::PointCloud<pcl::PointXYZ>::Ptr finalCloud(new pcl::PointCloud<pcl::PointXYZ>);

    // Read two PCD files from disk.
    if (_cloudSource != NULL)
    {
        return ;
    }
    if (_cloudTarget != NULL)
    {
        return ;
    }

    // ICP object.
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> registration;
    registration.setInputSource(_cloudSource);
    registration.setInputTarget(_cloudTarget);

    registration.align(*finalCloud);
    if (registration.hasConverged())
    {
        _message = QString();
        _message.append("ICP converged. \n");
        _message.append("The score is ");
        _message.append(QString::number(registration.getFitnessScore() ));
        _message.append(" \n Transformation matrix: ") ;

        transformation_matrix = registration.getFinalTransformation ().cast<double>();

        _message.append(print4x4Matrix(transformation_matrix));
    }
    else {
       _message = QString();
       _message.append("ICP did not converge. \n" );
    }


}

QString
icpthread::print4x4Matrix (const Eigen::Matrix4d & matrix)
{
  QString msg = QString();
  msg.append ("Rotation matrix :\n");
  msg.append (QString("    | %6.3f %6.3f %6.3f | \n").arg(matrix (0, 0), matrix (0, 1), matrix (0, 2)));
  msg.append (QString("R = | %6.3f %6.3f %6.3f | \n").arg( matrix (1, 0), matrix (1, 1), matrix (1, 2)));
  msg.append (QString("    | %6.3f %6.3f %6.3f | \n").arg(matrix (2, 0), matrix (2, 1), matrix (2, 2)));
  msg.append ("Translation vector :\n");
  msg.append (QString("t = < %6.3f, %6.3f, %6.3f >\n\n").arg(matrix (0, 3), matrix (1, 3), matrix (2, 3)));

  return msg;
}


