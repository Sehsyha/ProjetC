TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2
LIBS += -lSDL2_image
LIBS += -lSDL2_mixer
LIBS += -lSDL2_ttf

SOURCES += main.c \
    map.c \
    pacman.c \
    ghost.c \
    render.c \
    texture.c \
    update.c \
    astar.c \
    liste_chainee.c \
    couple.c

HEADERS += \
    map.h \
    pacman.h \
    ghost.h \
    render.h \
    config.h \
    texture.h \
    update.h \
    astar.h \
    liste_chainee.h \
    couple.h
