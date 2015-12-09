#include "pclacquisition.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PCLAcquisition w;
    w.show();

    return a.exec();
}
