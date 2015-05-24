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
    unsigned int x;
    unsigned int y;
    unsigned int direction;
    unsigned int futureDirection;
    char type;
};

Ghost *searchAndCreateGhost(char ghostType);
void freeGhost(Ghost *g);
void changeDirectionGhost(Ghost *g);
#endif
