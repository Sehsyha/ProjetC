TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
LIBS += -lSDL2_image
SOURCES += main.c \
    map.c \
    pacman.c

HEADERS += \
    map.h \
    pacman.h

