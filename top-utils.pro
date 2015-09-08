#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T11:47:02
#
#-------------------------------------------------

QT += core qml

ROOT_DIR = ../..

CONFIG(debug, debug|release): DESTDIR = $${ROOT_DIR}/Output/debug
CONFIG(release, debug|release): DESTDIR = $${ROOT_DIR}/Output/release

TARGET = top_utils
TEMPLATE = lib

CONFIG += staticlib

HEADERS += \
    jsonhelper.h

SOURCES += \
    jsonhelper.cpp

