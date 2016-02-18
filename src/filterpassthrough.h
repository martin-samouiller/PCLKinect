#ifndef FILTERPASSTHROUGH_H
#define FILTERPASSTHROUGH_H

#include <QWidget>
#include "defineType.h"

namespace Ui {
class FilterPassThrough;
}

class FilterPassThrough : public QWidget
{
    Q_OBJECT

public:
    explicit FilterPassThrough(QWidget *parent = 0);
    ~FilterPassThrough();
     void init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal);
     void startFilter(float minx, float miny, float minz, float x, float y, float z);
     void majLabelText();

private slots:
     void on_slider_X_sliderMoved(int position);

     void on_slider_Y_sliderMoved(int position);

     void on_slider_Z_sliderMoved(int position);

     void on_slider_minX_sliderMoved(int position);

     void on_slider_minY_sliderMoved(int position);

     void on_slider_minZ_sliderMoved(int position);

signals:
     void signalFinishFilter();

private:
    Ui::FilterPassThrough *ui;
    PointCloudT::Ptr _cloudSrc;
    PointCloudT::Ptr _cloudFinal;
    float _x;
    float _y;
    float _z;
    float _minx;
    float _miny;
    float _minz;
};

#endif // FILTERPASSTHROUGH_H
