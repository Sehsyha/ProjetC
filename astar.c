#include "astar.h"

int isEmptySet(int set[][], int row, int col);

unsigned int nextDirection(int srcX, int srcY, int dstX, int dstY){
    Map *map = getMapInstance();
    unsigned int i, j;
    int direction = STATIC;

    //TODO Verification des paramètres
    int closedset[map->row][map->col];
    for(i = 0 ; i  < map->row ; i++){
        for(j = 0 ; j < map->col ; j++){
            if(map->cells[i][j] == WALL){
                closedset[i][j] = 1;
            }
        }
    }

    int openset[map->row][map->col];
    openset[srcX][srcY] = 1;
    while(isEmptySet(openset, map->row, map->col)){

    }
    return direction;
}


int isEmptySet(int set[][], int row, int col){
    int i, j, retour = 1;
    for(i = 0 ; i < row ; i++){
        for(j = 0 ; j < col ; j++){
            if(set[i][j]){
                retour = 0;
                break;
            }
        }
    }
    return retour;
}
