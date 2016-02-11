cmake_minimum_required (VERSION 2.6 FATAL_ERROR)

project      (pcl_acquisition_kinect)
find_package (Qt4 REQUIRED)
find_package (VTK REQUIRED)
find_package (PCL 1.7.1 REQUIRED)
find_package (OpenCV REQUIRED)

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})

include_directories ( ${OpenCV_INCLUDE_DIRS} )
link_directories    (${OpenCV_INCLUDE_DIRS})
add_definitions     (${OpenCV_INCLUDE_DIRS})

set  (project_SOURCES main.cpp pclacquisition.cpp texture.cpp acquisitionwindows.cpp qlabelimage.cpp cloudwindows.cpp texturethread.cpp icpthread.cpp registration.cpp filters.cpp filterremovenan.cpp)
set  (project_HEADERS pclacquisition.h texture.h acquisitionwindows.h qlabelimage.h ASMConvert.h cloudwindows.h texturethread.h icpthread.h registration.h filters.h filterremovenan.h)
set  (project_FORMS   pclacquisition.ui texture.ui acquisitionwindows.ui cloudwindows.ui registration.ui filters.ui filterremovenan.ui)
set  (VTK_LIBRARIES   vtkRendering vtkGraphics vtkHybrid QVTK)

QT4_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT4_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})

INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (pcl_acquisition_kinect ${project_SOURCES}
                                ${project_FORMS_HEADERS}
                                ${project_HEADERS_MOC})

TARGET_LINK_LIBRARIES (pcl_acquisition_kinect ${QT_LIBRARIES} ${PCL_LIBRARIES} ${VTK_LIBRARIES} ${OpenCV_LIBS})
