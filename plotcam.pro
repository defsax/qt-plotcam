TEMPLATE = app
TARGET = plotcam-app

QT += core gui multimedia multimediawidgets 

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets 

INCLUDE_PATH += .

HEADERS += ./src/apps/camera/camera.h

SOURCES += main.cpp \
  ./src/apps/camera/camera.cpp
