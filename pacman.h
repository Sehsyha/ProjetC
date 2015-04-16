#ifndef PACMAN_H
#define PACMAN

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

#define START_LIFE 3
#define NORMAL 0
#define EATER 1

#define SPEED 4

typedef struct Pacman Pacman;
struct Pacman
{
    unsigned int x;
    unsigned int y;
    unsigned int point;
    unsigned int life;
    unsigned int state;
    unsigned int direction;
    unsigned int futureDirection;
};

Pacman *searchAndCreatePacman(Map *map);
void freePacman(Pacman *pacman);
void setDirection(Map *map, Pacman *pacman, unsigned int direction);
#endif
