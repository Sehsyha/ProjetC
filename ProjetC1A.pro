TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
LIBS += -lSDL2_image
SOURCES += main.c \
    map.c \
    pacman.c \
    ghost.c \
    render.c \
    texture.c

HEADERS += \
    map.h \
    pacman.h \
    ghost.h \
    render.h \
    config.h \
    texture.h

