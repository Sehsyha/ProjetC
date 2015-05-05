#include "ghost.h"

void changeDirectionClyde(Ghost *g);

Ghost *searchAndCreateGhost(char ghostType){
    Map *map = getMapInstance();
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

void changeDirectionGhost(Ghost *g){
    switch(g->type){
        case CLYDE:
            changeDirectionClyde(g);
            break;
    }
}

void changeDirectionClyde(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    g->direction = nextDirection(g->x, g->y, pacman->x, pacman->y);
}