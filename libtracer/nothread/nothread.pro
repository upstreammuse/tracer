TEMPLATE = lib
CONFIG += release staticlib warn_on
CONFIG -= qt
QMAKE_CFLAGS += --ansi --pedantic
DEFINES += TRACER
INCLUDEPATH += ../../include
SOURCES = nothread.c
TARGET = ../tracer
