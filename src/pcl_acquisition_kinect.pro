#-------------------------------------------------
#
# Project created by QtCreator 2015-01-30T14:08:11
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pcl_acquisition_kinect
TEMPLATE = app


SOURCES += main.cpp\
        pclacquisition.cpp \
    recalagepoint.cpp \
    texture.cpp \
    acquisitionwindows.cpp \
    qlabelimage.cpp \
    cloudwindows.cpp

HEADERS  += pclacquisition.h \
    recalagepoint.h \
    texture.h \
    acquisitionwindows.h \
    ASMConvert.h \
    qlabelimage.h \
    cloudwindows.h

FORMS    += pclacquisition.ui \
    texture.ui \
    acquisitionwindows.ui \
    cloudwindows.ui

INCLUDEPATH += /usr/include/pcl-1.7 /usr/local/include/vtk-5.8
LIBS += /usr/lib


DISTFILES += \
    CMakeLists.txt

OTHER_FILES += \
    CMakeLists.txt
