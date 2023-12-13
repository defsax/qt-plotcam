TEMPLATE = app
TARGET = plotcam-app

QT += core gui multimedia multimediawidgets 

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets 

INCLUDE_PATH += .

HEADERS += camera.h
SOURCES += main.cpp camera.cpp
