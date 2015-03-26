TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
SOURCES += main.c \
    map.c

HEADERS += \
    map.h

