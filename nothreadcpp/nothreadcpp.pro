DEFINES += TRACER

TEMPLATE = app
CONFIG += release warn_on
CONFIG -= qt
INCLUDEPATH += ../include
SOURCES = nothreadcpp.cpp
contains(DEFINES, TRACER) {
   LIBS += -L../libtracer -ltracer
}
TARGET = nothreadcpp
