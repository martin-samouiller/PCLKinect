#ifndef FILTERNOISE_H
#define FILTERNOISE_H

#include <QWidget>
#include "defineType.h"

namespace Ui {
class FilterNoise;
}

class FilterNoise : public QWidget
{
    Q_OBJECT

public:
    explicit FilterNoise(QWidget *parent = 0);
    ~FilterNoise();
    void init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal);
    void startTraitement();

private slots:
    void on_btn_start_clicked();

signals:
    void signalFinishFilter();

private:
    Ui::FilterNoise *ui;
    PointCloudT::Ptr _cloudSrc;
    PointCloudT::Ptr _cloudFinal;
    int _meanK;
    float stddevMul ;

};

#endif // FILTERNOISE_H
