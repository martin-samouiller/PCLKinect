#include "acquisitionwindows.h"
#include "ASMConvert.h"
#include "../build/ui_acquisitionwindows.h"

#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>




#include <opencv2/contrib/contrib.hpp>

AcquisitionWindows::AcquisitionWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AcquisitionWindows)
{
    ui->setupUi(this);

    // Setup the cloud pointer
    cloud.reset (new PointCloudT);
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    ui->qvtk_Cloud->SetRenderWindow (viewer->getRenderWindow());
    viewer->setupInteractor (ui->qvtk_Cloud->GetInteractor(), ui->qvtk_Cloud->GetRenderWindow());
    viewer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewer->getRenderWindow()->Render();
    viewer->setBackgroundColor (0.1, 0.1, 0.1);
    viewer->addCoordinateSystem (1.0);
    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera ();
    ui->qvtk_Cloud->update ();

    m_iSDeviceConnect = false;
    ui->btn_LED->setStyleSheet("background-color: red;");


    /*acquisition OPENCV : depth et rgb*/

    qTimer = new QTimer();
    qTimer->setInterval(500);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(displayFrame()));


    lbl_stream = new QLabelImage();
    //Signal émit par la class qlabel_image pour la lecture en dynamique de la position des pixels
    connect(lbl_stream, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos_stream()));
    connect(lbl_stream, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_pressed()));
    connect(lbl_stream, SIGNAL(Mouse_ClickLeft()), this, SLOT(MouseClickLeft()));
    connect(lbl_stream, SIGNAL(Mouse_ReleasePos()), this, SLOT(Mouse_release_pos()));
    lbl_stream->setMouseTracking(true);
    //Signal émit par la class qlabel_image pour la lecture en dynamique de la position des pixels
    ui->scroll_image->setWidget(lbl_stream);

    m_numberCapture = 0; //nombre d'images capturées

    on_rdnBtn_grayscaleLUT_clicked();
    ui->rdnBtn_grayscaleLUT->setChecked(true);


}

AcquisitionWindows::~AcquisitionWindows()
{
    delete ui;
}



void
AcquisitionWindows::cloud_cb_ (const PointCloudT::ConstPtr &cloud)
{
    //On rempli les points dans notre liste
    //listPoint.push_back(cloud);
    if (device->isRunning()){
        viewer->updatePointCloud (cloud, "cloud");
        ui->qvtk_Cloud->update ();

        cloudSave = cloud;
    }
}

//permet de lancer l'acquisition des nuages de points
int
AcquisitionWindows::DemarerAcqui(){

    boost::function<void (const PointCloudT::ConstPtr&)> f = boost::bind(&AcquisitionWindows::cloud_cb_, this, _1);

    if(m_iSDeviceConnect == true){
        qDebug() << "OpenNIGrabber start";

        // Start Button
        // Register Calback member function

        device->registerCallback(f);
        device->start();

        ui->btn_startAcqui->setEnabled(false);
        ui->btn_stopAcqui->setEnabled(true);


    }
    ui->lbl_infos->setText("opening device(s)" );
    ui->lbl_infos->setText("Device opening ..." );
    capture.open( CV_CAP_OPENNI );

    std::cout << "done." << std::endl;

    if( !capture.isOpened() )
    {
        QMessageBox::warning(this, tr("Acquisition"),  tr("Can not open a capture object.") , QMessageBox::Ok);
        return -1;
    }

    qTimer->start();

    return 0;
}


//stoppe l'acquisition des nuages de points
void
AcquisitionWindows::StopperAcqui(){

    // Stop Button
        // Stop Streaming
    if(m_iSDeviceConnect == true){
        device->stop ();
        ui->btn_startAcqui->setEnabled(true);
        ui->btn_stopAcqui->setEnabled(false);

    }

}

void
AcquisitionWindows::ConnectDevice(){
    try {
        device = new pcl::OpenNIGrabber();
        ui->lbl_infos->setText("Frame Per Second : " + QString::number(device->getFramesPerSecond()));
       // std::cout << "Frame Per Second : " << device->getFramesPerSecond() << endl;
        m_iSDeviceConnect = true;
        ui->btn_LED->setStyleSheet("background-color: green;");

    }
    catch (IOException e){

       QMessageBox::warning(this, tr("Acquisition"),  tr("Impossible de se connecter :\n") +   e.what(), QMessageBox::Ok);

       m_iSDeviceConnect = false;
    }

}


void
AcquisitionWindows::displayFrame() {

    capture.grab();
    capture.retrieve( depthMap, CV_CAP_OPENNI_DEPTH_MAP );

    //Conversion en 8bits pour l'affichage
    const float scaleFactor = 0.05f;
    cv::Mat show;
    depthMap.convertTo( show, CV_8UC1, scaleFactor );

    if(m_colorJet == true){
        //Conversion en couleur si l'otpion est activé
        cv::Mat rgb;
        cv::applyColorMap(show, rgb, cv::COLORMAP_JET);
        lbl_stream->setPixmap(ASM::cvMatToQPixmap(rgb));

    }else if (m_colorOcean == true)
    {

        cv::Mat rgb;
        cv::applyColorMap(show, rgb, cv::COLORMAP_OCEAN);
        lbl_stream->setPixmap(ASM::cvMatToQPixmap(rgb));
    }
    else
    {
        lbl_stream->setPixmap(ASM::cvMatToQPixmap(show));
    }


    imageStream = depthMap.clone();
}


//Lecture des pixels du streaming
void
AcquisitionWindows::Mouse_current_pos_capture()
{

    /*ui->lblText_capture->setText(QString("X = %1, Y= %2").arg(lbl_capture->x).arg(lbl_capture->y));

    unsigned short ndgCapture = 0;
    int coord_x = lbl_capture->x;
    int coord_y = lbl_capture->y;

    if(!imageCapture.empty()){
        if(coord_x < imageCapture.cols && coord_y < imageCapture.rows){
            ndgCapture = imageCapture.at<unsigned short>(coord_y , coord_x);
            ui->lblText_capturePix->setText(QString("NDG = %1").arg(ndgCapture));
        }
    }*/
}

//Lecture des pixels du streaming
void
AcquisitionWindows::Mouse_current_pos_stream()
{
    /*ui->lblText_stream->setText(QString("X = %1, Y= %2").arg(lbl_stream->x).arg(lbl_stream->y));

    unsigned short ndgStream = 0;
    int coord_x = lbl_stream->x;
    int coord_y = lbl_stream->y;

    if(!imageStream.empty()){

        if(coord_x < imageStream.cols && coord_y < imageStream.rows){
            ndgStream = imageStream.at<unsigned short>(coord_y , coord_x);
            ui->lblText_streamPix->setText(QString("NDG = %1").arg(ndgStream));
        }

    }*/
}

void
AcquisitionWindows::Mouse_pressed()
{

}

void
AcquisitionWindows::MouseClickLeft()
{

}

void
AcquisitionWindows::Mouse_release_pos()
{
}




void AcquisitionWindows::on_rdnBtn_jetLUT_clicked()
{
     m_colorGray = false;
     m_colorOcean = false;
     m_colorJet = true;
}

void AcquisitionWindows::on_rdnBtn_grayscaleLUT_clicked()
{
    m_colorGray = true;
    m_colorOcean = false;
    m_colorJet = false;
}

void AcquisitionWindows::on_rndBtn_oceanLUT_clicked()
{
    m_colorGray = false;
    m_colorOcean = true;
    m_colorJet = false;
}

void AcquisitionWindows::on_pushButton_SaveCloud_clicked()
{
    try {
        QString fichier = QFileDialog::getSaveFileName(this, "Savec File", QString(), "Could (*.pcd)");
        if(cloudSave != NULL && fichier != NULL && fichier != "")
             pcl::io::savePCDFileASCII(fichier.toStdString(), *cloudSave);

    }
    catch (exception e){
        QMessageBox::warning(this, tr("Acquisition"), e.what(), QMessageBox::Ok);

    }
}
