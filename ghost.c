#include "ghost.h"

void changeDirectionClyde(Map *map, Ghost *g);

Ghost *searchAndCreateGhost(Map *map, char ghostType){
    Ghost *g = 0;
    unsigned int i = 0, j = 0;
    int found = 0;
    while(i < map->row && !found){
        j = 0;
        while(j < map->col && !found){
            if(map->cells[i][j] == ghostType){
                found = 1;
            }
            j++;
        }
        i++;
    }
    j--;
    i--;
    if(found){
        g = malloc(sizeof(Ghost));
        g->x = j * TILE_SIZE;
        g->y = i * TILE_SIZE;
        g->direction = STATIC;
        g->futureDirection = STATIC;
        g->type = ghostType;
    }
    return g;
}

void freeGhost(Ghost *g){
    free(g);
}

void changeDirectionGhost(Map *map, Ghost *g){
    switch(g->type){
        case CLYDE:
            changeDirectionClyde(map, g);
            break;
    }
}

void changeDirectionClyde(Map *map, Ghost *g){
    g->direction = EAST;
}
