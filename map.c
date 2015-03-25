#include "map.h"
#include <stdlib.h>
#include <stdio.h>


Map *loadMap(){
    int row = 5;
    int col = 5;
    int i = 0;

    Map *map = NULL;

    map = malloc(sizeof(Map));
    if(map == NULL){
        printf("Erreur lors de l'allocation de la carte\n");
        exit(EXIT_FAILURE);
    }
    map->row = row;
    map->col = col;
    map->lines = malloc(row * sizeof(int*));
    for(i = 0 ; i < row ; i++){
        map->lines[i] = malloc(col * sizeof(int));
        if(map->lines[i] == NULL){
            printf("Erreur lors de l'allocation de la carte\n");
            exit(EXIT_FAILURE);
        }
    }

    return map;
}

void freeMap(Map *map){
    int i = 0;
    for(i = 0 ; i < map->row ; i++){
        free(map->lines[i]);
    }
    free(map->lines);
    free(map);
}
