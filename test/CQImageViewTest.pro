TEMPLATE = app

QT += widgets

TARGET = CQImageViewTest

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++17

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
-L../../CImageLib/lib \
-L../../CFont/lib \
-L../../CFile/lib \
-L../../CFileUtil/lib \
-L../../CMath/lib \
-L../../CConfig/lib \
-L../../CStrUtil/lib \
-L../../CUtil/lib \
-L../../COS/lib \
-L../../CRegExp/lib \
-lCQImageView -lCQUtil \
-lCImageLib -lCFont -lCFile -lCFileUtil -lCMath -lCConfig -lCStrUtil \
-lCUtil -lCOS -lCRegExp \
-lpng -ljpeg -ltre
