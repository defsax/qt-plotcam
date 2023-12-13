#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QPushButton>
#include <QThread>
#include <QImage>

class CameraWidget : public QWidget {
  Q_OBJECT

public:
  CameraWidget(QWidget *parent = nullptr);
  ~CameraWidget();

signals:
  void imageCaptured(const QImage &image);

private slots:
  void startCamera();
  void captureImage();

private:
  QThread *cameraThread;
  QCamera *camera;
  QCameraViewfinder *viewFinder;
  QCameraImageCapture *imageCapture;
  QPushButton *captureButton;
};

#endif // !CAMERA_H
