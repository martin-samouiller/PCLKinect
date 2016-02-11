#include "registration.h"
#include "../build/ui_registration.h"
#include <QtDebug>
#include <QMessageBox>



Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);


    // Setup the cloud pointer
    viewerCloudFinish.reset (new pcl::visualization::PCLVisualizer ("Registration", false));
    ui->qvtk_CloudFinalRegistration->SetRenderWindow (viewerCloudFinish->getRenderWindow());
    viewerCloudFinish->setupInteractor (ui->qvtk_CloudFinalRegistration->GetInteractor(), ui->qvtk_CloudFinalRegistration->GetRenderWindow());
    viewerCloudFinish->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
    viewerCloudFinish->getRenderWindow()->Render();
    viewerCloudFinish->setBackgroundColor (0.1, 0.1, 0.1);
    viewerCloudFinish->initCameraParameters ();
    viewerCloudFinish->resetCamera();
    ui->qvtk_CloudFinalRegistration->update();

    _icpCompute = new icpthread();
    connect(_icpCompute , SIGNAL(icpFinish()), this, SLOT(eventSlotFinishICP()));
}

Registration::~Registration()
{
    delete ui;
}





void Registration::init(QStringList _listCloud, DictionaryCloudPtr _listCloudPtr, DictionaryCloudName _listCloudsName)
{
    //Maj des items à partir des données des nuages de points
    ui->comboBox_Source->addItems(_listCloud);
    ui->comboBox_Target->addItems(_listCloud);
    m_listCloudsPtr = _listCloudPtr;
    m_listCloudsName = _listCloudsName;


    on_comboBox_Source_currentIndexChanged(ui->comboBox_Source->itemText(ui->comboBox_Source->currentIndex()));
    on_comboBox_Target_currentIndexChanged(ui->comboBox_Target->itemText(ui->comboBox_Target->currentIndex()));

}

void Registration::on_comboBox_Source_currentIndexChanged(const QString &arg1)
{
    qDebug() << "value map : " << QString::fromStdString(m_listCloudsName[arg1.toStdString()]) ;

    _cloudSource.reset (new PointCloudT);

    if(m_listCloudsPtr.empty()){
        qDebug() << "Enmpty list : return on_comboBox_Source_currentIndexChanged";
        return ;
    }

    PointCloudC::Ptr cloud = m_listCloudsPtr[arg1.toStdString()];

    try{
        pcl::copyPointCloud(*cloud, *_cloudSource);
    }catch (PCLException ex){
        QMessageBox::warning(this, tr("Texture"),  tr("Impossible de copier le nuage de points") , QMessageBox::Ok);
    }

    if(_cloudSource != NULL){
        qDebug() << "cloud != null , update point cloud  ";
        qDebug() << "Size : " << QString::number(_cloudSource->points.size());
    }
}

void Registration::on_comboBox_Target_currentIndexChanged(const QString &arg1)
{
    qDebug() << "value map : " << QString::fromStdString(m_listCloudsName[arg1.toStdString()]) ;

    _cloudTarget.reset (new PointCloudT);
    if(m_listCloudsPtr.empty()){
        qDebug() << "Enmpty list : return on_comboBox_Target_currentIndexChanged";
        return ;
    }

    PointCloudC::Ptr cloud = m_listCloudsPtr[arg1.toStdString()];

    try{
        pcl::copyPointCloud(*cloud, *_cloudTarget);
    }catch (PCLException ex){
        QMessageBox::warning(this, tr("Texture"),  tr("Impossible de copier le nuage de points") , QMessageBox::Ok);
    }



    if(_cloudTarget != NULL){
        qDebug() << "cloud != null , update point cloud  ";
        qDebug() << "Size : " << QString::number(_cloudTarget->points.size());
    }
}


//On lance le calcul de correspondance
void Registration::on_pushButton_clicked()
{
    if(_eTypeRegistration == FEATURE_BASED){
        QMessageBox::warning(this, tr("Texture"),  tr("Not Implemented exception") , QMessageBox::Ok);
    }

    else if(_eTypeRegistration == ICP)
    {
        _icpCompute->init(_cloudSource, _cloudTarget);
        _icpCompute->run();
    }
    else
    {
         QMessageBox::warning(this, tr("Texture"),  tr("Choisir une technique de registration") , QMessageBox::Ok);
    }
}

void Registration::on_btn_SaveCloudFinal_clicked()
{

}

void Registration::on_comboBox_TypeRegist_currentIndexChanged(const QString &arg1)
{
     qDebug() << "Registration : " << arg1;

     if(arg1.compare("Feature-based") == 0)
         _eTypeRegistration = FEATURE_BASED;
     if(arg1.compare("ICP") == 0)
         _eTypeRegistration = ICP ;

}

void Registration::eventSlotFinishICP()
{
    _cloudFinish.reset(new PointCloudT);
    _icpCompute->getFinishCloud(_cloudFinish);


    viewerCloudFinish->updatePointCloud (_cloudFinish   , "cloud");
    ui->qvtk_CloudFinalRegistration->update();

}
