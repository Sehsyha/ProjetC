#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

typedef struct Ghost Ghost;
struct Ghost{
    unsigned int x;
    unsigned int y;
    unsigned int direction;
};

Ghost *searchAndCreate(Map *map, int ghostType);
void freeGhost(Ghost *g);
#endif
