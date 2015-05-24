TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
LIBS += -lSDL2_image
LIBS += -lSDL2_mixer

SOURCES += main.c \
    map.c \
    pacman.c \
    ghost.c \
    render.c \
    texture.c \
    update.c \
    astar.c

HEADERS += \
    map.h \
    pacman.h \
    ghost.h \
    render.h \
    config.h \
    texture.h \
    update.h \
    astar.h

