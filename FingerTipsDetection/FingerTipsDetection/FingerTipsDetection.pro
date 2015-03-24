#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T15:28:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = FingerTipsDetection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH +=D:\OpenCV\build\include\

win32:CONFIG(debug, debug|release): {
LIBS += -LD:\opencv\build\x86\vc12\lib \
-lopencv_core2411d \
-lopencv_imgproc2411d \
-lopencv_highgui2411d \
-lopencv_ml2411 \
-lopencv_video2411d \
-lopencv_features2d2411d \
-lopencv_calib3d2411d \
-lopencv_objdetect2411d \
-lopencv_contrib2411d \
-lopencv_legacy2411d \
-lopencv_flann2411d}
 else:win32:CONFIG(release, debug|release): {
LIBS += -LD:\opencv\build\x86\vc12\lib \
-lopencv_core2411 \
-lopencv_imgproc2411 \
-lopencv_highgui2411 \
-lopencv_ml2411 \
-lopencv_video2411 \
-lopencv_features2d2411 \
-lopencv_calib3d2411 \
-lopencv_objdetect2411 \
-lopencv_contrib2411 \
-lopencv_legacy2411 \
-lopencv_flann2411

}
