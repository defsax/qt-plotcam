#include "camera.h"

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *layout = new QVBoxLayout(this);

  cameraThread = new QThread;
  camera = new QCamera;
  viewFinder = new QCameraViewfinder;
  imageCapture = new QCameraImageCapture(camera);

  layout->addWidget(viewFinder);

  camera->moveToThread(cameraThread);
  imageCapture->moveToThread(cameraThread);

  connect(cameraThread, &QThread::started, this, &CameraWidget::startCamera);

 connect(imageCapture, SIGNAL(imageCaptured(int, const QImage&)), this, SIGNAL(imageCaptured(const QImage&)));
//  connect(imageCapture, &QCameraImageCapture::imageCaptured, this, &CameraWidget::imageCaptured);

  captureButton = new QPushButton("Capture", this);
  connect(captureButton, &QPushButton::clicked, this, &CameraWidget::captureImage);
  layout->addWidget(captureButton);

}

CameraWidget::~CameraWidget(){
  cameraThread->quit();
  cameraThread->wait();
}

void CameraWidget::startCamera(){
  camera->setViewfinder(viewFinder);

  camera->start();
}

void CameraWidget::captureImage(){
  imageCapture->capture();
}
