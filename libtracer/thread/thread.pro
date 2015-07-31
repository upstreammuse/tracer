TEMPLATE = lib
CONFIG += release staticlib thread warn_on
CONFIG -= qt
QMAKE_CFLAGS += --ansi --pedantic
DEFINES += TRACER
INCLUDEPATH += ../../include
SOURCES = thread.c
TARGET = ../tracer-mt
