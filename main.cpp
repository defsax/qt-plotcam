#include <QApplication>
#include <QMainWindow>
#include "./src/apps/camera/camera.cpp"

int main(int argc, char *argv[]){
  QApplication app(argc, argv);
  QMainWindow mainWindow;
  
  CameraWidget cameraWidget;
  cameraWidget.show();

  mainWindow.setWindowTitle("plotcam app!");
  mainWindow.resize(400,300);
  mainWindow.show();

  return app.exec();
}
