#ifndef GHOST_H
#define GHOST_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

#include "map.h"
#include "pacman.h"



typedef struct Ghost Ghost;
struct Ghost{
    int sortie;
    unsigned int x;
    unsigned int y;
    unsigned int initialX;
    unsigned int initialY;
    unsigned int direction;
    unsigned int futureDirection;
    char type;
};

Ghost *searchAndCreateGhost(char ghostType);
void freeGhost(Ghost *g);
void changeDirectionGhost(Ghost *g);
#endif
