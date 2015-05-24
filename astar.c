#include "astar.h"
#include "ghost.h"
#include "pacman.h"
#include "liste_chainee.h"

float heuristique(int x, int y);
Liste **graphageMap(Map *m);

unsigned int nextDirection(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    Map *map = getMapInstance();
//    float distance = heuristique(g);
    Liste **tab = graphageMap(map);

    Liste *ouverte = initialisation(2);
    Liste *ferme = initialisation(2);
    Element *current;
    Element *parcourt;
    int couple[] = {g->x, g->y};
    insertion(ouverte, couple, heuristique(g->x, g->y), 0);
    float minFscore;
    while(!isEmpty(ouverte)){
//      current := the node in openset having the lowest f_score[] value
        parcourt = ouverte->premier;
        minFscore = 100000000000000;
        while(parcourt != NULL){
            if(parcourt->f_score < minFscore){
                current = parcourt;
                minFscore = parcourt->f_score;
            }
            parcourt = parcourt->suivant;
        }
        if(current->nombre[0] == pacman->x && current->nombre[1] == pacman->y){
            return NORTH;
        }

//      remove current from openset
//      add current to closedset
//      for each neighbor in neighbor_nodes(current)
//          if neighbor in closedset
//              continue
//          tentative_g_score := g_score[current] + dist_between(current,neighbor)

//      if neighbor not in openset or tentative_g_score < g_score[neighbor]
//          came_from[neighbor] := current
//          g_score[neighbor] := tentative_g_score
//          f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
//          if neighbor not in openset
//              add neighbor to openset
    }

    return STATIC;
}

float heuristique(int x, int y) {
    Pacman *p = getPacmanInstance();
    int gx,gy,px,py;
    float res = 0;
    px = p->x;
    py = p->y;
    res = ( py - px ) / ( y - x );
    return res;
}

Liste **graphageMap(Map *m) {
    int c,l,i,j;
    c = m ->col;
    l = m ->row;

    Liste rep[c][l];
    for (i = 1 ; i < c; i++) {
        for (j = 1 ; j < l ; j++) {
            Liste *incident = initialisation(1);

            if (m ->cells[i][j] == 1) {
                rep[i][j] = *incident;
            } else {
                if (m->cells[i-1][j] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (m->cells[i][j+1] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (m->cells[i+1][j] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (m->cells[i][j-1] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }
            }

        }
    }
    return rep;
}

