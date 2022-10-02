TEMPLATE = lib

QT += widgets

TARGET = CQImageView

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++17

CONFIG += staticlib

MOC_DIR = .moc

# Input
SOURCES += \
CQImageView.cpp \
CImageView.cpp \

HEADERS += \
../include/CQImageView.h \
../include/CImageView.h \

OBJECTS_DIR = ../obj
DESTDIR     = ../lib

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
../../COS/include \
