#ifndef DEFINETYPE_H
#define DEFINETYPE_H


// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <iostream>
#include <map>

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

typedef pcl::PointXYZRGB PointC;
typedef pcl::PointCloud<PointC> PointCloudC;


typedef std::map< std::string, boost::shared_ptr<PointCloudC> > DictionaryCloudPtr;
typedef std::map< std::string, std::string > DictionaryCloudName;




#endif // DEFINETYPE_H
