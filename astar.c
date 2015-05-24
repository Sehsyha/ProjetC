#include "astar.h"
#include "ghost.h"
#include "pacman.h"

float heuristique(Ghost *g,Pacman *p);

unsigned int nextDirection(Ghost *g,Pacman *p){
    Map *map = getMapInstance();
    float distance = heuristique(*g,*p);

    return direction;
}

float heuristique(Ghost *g,Pacman *p) {
    int gx,gy,px,py;
    float res;
    gx = g->x;
    gy = g->y;
    px = p->x;
    py = p->y;
    res = (py-px)/(gy-gx);

    return res;
}
