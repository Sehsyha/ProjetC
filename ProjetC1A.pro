TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
SOURCES += main.c \
    map.c \
    pacman.c

HEADERS += \
    map.h \
    pacman.h

