DEFINES += TRACER

TEMPLATE = app
CONFIG += release thread warn_on
CONFIG -= qt
QMAKE_CFLAGS += --ansi --pedantic
QMAKE_LINK = gcc
INCLUDEPATH += ../include
SOURCES = threadc.c
contains(DEFINES, TRACER) {
   LIBS += -L../libtracer -ltracer-mt
}
TARGET = threadc
