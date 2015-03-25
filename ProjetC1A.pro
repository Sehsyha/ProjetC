TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL
SOURCES += main.c \
    map.c

HEADERS += \
    map.h

