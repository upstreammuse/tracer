DEFINES += TRACER

TEMPLATE = app
CONFIG += release warn_on
CONFIG -= qt
QMAKE_CFLAGS += --ansi --pedantic
QMAKE_LINK = gcc
INCLUDEPATH += ../include
SOURCES = nothreadc.c
contains(DEFINES, TRACER) {
   LIBS += -L../libtracer -ltracer
}
TARGET = nothreadc
