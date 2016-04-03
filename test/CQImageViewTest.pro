TEMPLATE = app

QT += widgets

TARGET = CQImageViewTest

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++11

MOC_DIR = .moc

#CONFIG += debug

# Input
SOURCES += \
CQImageViewTest.cpp \

HEADERS += \
CQImageViewTest.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj

INCLUDEPATH += \
. \
../include \
../../CQUtil/include \
../../CImageLib/include \
../../CFont/include \
../../CFile/include \
../../CMath/include \
../../CStrUtil/include \
../../CUtil/include \

unix:LIBS += \
-L../lib \
-L../../CQUtil/lib \
-L../../CUtil/lib \
-L../../CImageLib/lib \
-L../../CFont/lib \
-L../../CFile/lib \
-L../../CConfig/lib \
-L../../COS/lib \
-L../../CStrUtil/lib \
-L../../CRegExp/lib \
-lCQImageView -lCQUtil -lCUtil \
-lCImageLib -lCFont -lCFile -lCConfig -lCStrUtil -lCOS \
-lCRegExp \
-lpng -ljpeg -ltre
