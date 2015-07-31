DEFINES += TRACER

TEMPLATE = app
CONFIG += release thread warn_on
CONFIG -= qt
INCLUDEPATH += ../include
SOURCES = threadcpp.cpp
contains(DEFINES, TRACER) {
   LIBS += -L../libtracer -ltracer-mt
}
TARGET = threadcpp
