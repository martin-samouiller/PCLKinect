#ifndef FILTERREMOVENAN_H
#define FILTERREMOVENAN_H

#include <QWidget>
#include "defineType.h"

namespace Ui {
class FilterRemoveNaN;
}

class FilterRemoveNaN : public QWidget
{
    Q_OBJECT

public:
    explicit FilterRemoveNaN(QWidget *parent = 0);
    ~FilterRemoveNaN();

    void
    init(PointCloudT::Ptr cloudSrc , PointCloudT::Ptr  cloudFinal);


private slots:
    void
    on_pushButton_clicked();

private:
    Ui::FilterRemoveNaN *ui;
    PointCloudT::Ptr _cloudSrc;
    PointCloudT::Ptr _cloudFinal;
};

#endif // FILTERREMOVENAN_H
