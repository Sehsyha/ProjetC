#include "astar.h"
#include "ghost.h"
#include "pacman.h"
#include "liste_chainee.h"

float heuristique(Ghost *g);
Liste **graphageMap(Map *m);

unsigned int nextDirection(Ghost *g){
    Map *map = getMapInstance();
    float distance = heuristique(g);
    Liste **tab = graphageMap(map);

    Liste *ouverte = initialisation(2);
    Liste *ferme = initialisation(2);



    return NORTH;
}

float heuristique(Ghost *g) {
    Pacman *p = getPacmanInstance();
    int gx,gy,px,py;
    float res = 0;
    gx = g->x;
    gy = g->y;
    px = p->x;
    py = p->y;
    res = ( py - px ) / ( gy - gx );
    return res;
}

Liste **graphageMap(Map *m) {
    int c,l,i,j;
    c = m ->col;
    l = m ->row;

    Liste rep[c][l];
    for (i = 1;i < c - 1; i++) {
        for (j = 1; j < l - 1; j++) {
            Liste *incident = initialisation(1);

            if (m ->cells[i][j] == 1) {
                rep[i][j] = *incident;
            } else {
                if (m->cells[i-1][j] == 1) {
                    insertion(incident,0);
                } else {
                    insertion(incident,1);
                }

                if (m->cells[i][j+1] == 1) {
                    insertion(incident,0);
                } else {
                    insertion(incident,1);
                }

                if (m->cells[i+1][j] == 1) {
                    insertion(incident,0);
                } else {
                    insertion(incident,1);
                }

                if (m->cells[i][j-1] == 1) {
                    insertion(incident,0);
                } else {
                    insertion(incident,1);
                }
            }

        }
    }
    return rep;
}
