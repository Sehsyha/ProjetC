#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include <SDL2/SDL.h>

typedef struct Ghost Ghost;
struct Ghost{
    unsigned int x;
    unsigned int y;
    unsigned int direction;
    unsigned int futureDirection;
    char type;
};

Ghost *searchAndCreateGhost(Map *map, char ghostType);
void freeGhost(Ghost *g);
void changeDirectionGhost(Map *map, Ghost *g);
#endif
