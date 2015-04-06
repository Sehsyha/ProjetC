#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Map *loadMap(char *path){
    //Déclaration des variables
    unsigned int row = 0;
    unsigned int col = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    Map *map = NULL;
    FILE *file = NULL;
    char line[MAX_SIZE];
    printf("Loading %s file\n", path);

    file = fopen(path, "r");
    if(file == NULL){
        printf("File not found : %s\n", path);
        exit(EXIT_FAILURE);
    }
    fgets(line, MAX_SIZE, file);
    row = atoi(line);
    if(row < 1){
        printf("Row must be > 1 : %d\n", row);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    if(row > MAX_SIZE){
        printf("Rows too big : %d\n", row);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fgets(line, MAX_SIZE, file);
    col = atoi(line);
    if(row < 1){
        printf("Columns must be > 1 : %d\n", col);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    if(col > MAX_SIZE){
        printf("Columns too big : %d\n", col);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    map = malloc(sizeof(Map));
    if(map == NULL){
        printf("Error during map allocation\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    map->row = row;
    map->col = col;
    map->cells = malloc(row * sizeof(int*));
    for(i = 0 ; i < map->row ; i++){
        map->cells[i] = malloc(map->col * sizeof(int));
        if(map->cells[i] == NULL){
            printf("Error during map allocation\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        fgets(line, MAX_SIZE, file);
        if(strlen(line) - 1 > map->col || strlen(line) - 1 < map->col){
            printf("Error, number of columns does not correspond : %d != %d\n", strlen(line) - 1, map->col);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        j = 0;
        while(j < strlen(line) - 1){
            map->cells[i][j] = line[j];
            j++;
        }
        if(j != map->col){
            printf("Not as many columns as defined : %d != %d\n", map->col, j);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
    printf("Load success !\n");
    return map;
}

void printMap(Map *map){
    unsigned int i = 0, j = 0;
    for(i = 0 ; i < map->row ; i++){
        for(j = 0 ; j  < map->col ; j++){
            printf("%c", map->cells[i][j]);
        }
        printf("\n");
    }
}

void freeMap(Map *map){
    unsigned int i = 0;
    for(i = 0 ; i < map->row ; i++){
        free(map->cells[i]);
    }
    free(map->cells);
    free(map);
}
