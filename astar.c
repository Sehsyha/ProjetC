#include "astar.h"
#include "ghost.h"
#include "pacman.h"
#include "liste_chainee.h"

/*
 * Tentative d'implatation de l'algorithme A*
 *
 */

float heuristique(int x, int y);
Liste **graphageMap(Map *m);

unsigned int nextDirection(Ghost *g){
//    Pacman *pacman = getPacmanInstance();
//    Map *map = getMapInstance();
////    float distance = heuristique(g);
////    Liste **tab = graphageMap(map);

//    Liste *ouverte = initialisation(2);
//    Liste *ferme = initialisation(2);
//    Element *current;
//    Element *parcourt;
//    int couple[] = {g->x, g->y};
//    insertion(ouverte, couple, heuristique(g->x, g->y), 0);
//    float minFscore;
//    while(!isEmpty(ouverte)){
////      current := the node in openset having the lowest f_score[] value
//        parcourt = ouverte->premier;
//        minFscore = 100000000000000;
//        while(parcourt != NULL){
//            if(parcourt->f_score < minFscore){
//                current = parcourt;
//                minFscore = parcourt->f_score;
//            }
//            parcourt = parcourt->suivant;
//        }
//        if(current->nombre[0] == pacman->x && current->nombre[1] == pacman->y){
//            return NORTH;
//        }

//        parcourt = ouverte->premier;

//        if(isEqual(parcourt, current, parcourt->nombre, current->nombre)){
//            ouverte->premier = current->suivant;

//        }else{
//            while(parcourt != NULL && !isEqual(parcourt->suivant, current, parcourt->nombre, current->nombre)){
//                parcourt = parcourt->suivant;
//            }
//            if(parcourt != NULL){
//                parcourt->suivant = current->suivant;
//            }
//        }


//        insertion(ferme, current->nombre, current->g_score, current->f_score);
//        parcourt = tab[current->nombre[1]][current->nombre[0]].premier;
//        while(parcourt != NULL){
//            printf("%d %d", parcourt->nombre[0], parcourt->nombre[1]);
//            parcourt = parcourt->suivant;
//        }
//      for each neighbor in neighbor_nodes(current)
//          if neighbor in closedset
//              continue
//          tentative_g_score := g_score[current] + dist_between(current,neighbor)

//          if neighbor not in openset or tentative_g_score < g_score[neighbor]
//              came_from[neighbor] := current
//              g_score[neighbor] := tentative_g_score
//              f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
//              if neighbor not in openset
//                  add neighbor to openset
//    }
    return STATIC;
}

float heuristique(int x, int y) {
    Pacman *p = getPacmanInstance();
    int gx,gy,px,py;
    float res = 0;
    px = p->x;
    py = p->y;
    res = sqrt(pow(x - (int)(p->x), 2) + pow(y - (int)(p->y), 2));
    return res;
}

Liste **graphageMap(Map *m) {
    int c,l,i,j;
    c = m ->col;
    l = m ->row;

    Liste rep[c][l];
    for (i = 0 ; i < c; i++) {
        for (j = 0 ; j < l ; j++) {
            Liste *incident = initialisation(1);

            if (m ->cells[i][j] == 1) {
                rep[i][j] = *incident;
            } else {
                if (i > 0 && m->cells[i-1][j] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (j < l-1 && m->cells[i][j+1] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (i < c-1 && m->cells[i+1][j] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }

                if (j > 0 && m->cells[i][j-1] == 1) {
                    insertion(incident,0, 0, 0);
                } else {
                    insertion(incident,1, 0, 0);
                }
            }

        }
    }
    return rep;
}

