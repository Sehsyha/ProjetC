#ifndef ASTAR_H
#define ASTAR_H
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "liste_chainee.h"

/*
 * Tentative d'implatation de l'algorithme A*
 *
 */


typedef struct point {
    int x,y;
} point;

typedef struct noeud{
    float cout_g, cout_h, cout_f;
    int c,l; // 'adresse' du parent (qui sera toujours dans la map fermée)
} noeud;

unsigned int nextDirection(Ghost *g);

#endif
