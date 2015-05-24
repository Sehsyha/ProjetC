#include "map.h"

Map *map = NULL;

Map *getMapInstance(){
    if(map == NULL){
        printf("Map must be loaded\n");
        exit(EXIT_FAILURE);
    }
    return map;
}

/*
 *
 * Function used to load a map with a file
 *
 */
void loadMap(char *path){
    //Initialisations
    unsigned int row = 0;
    unsigned int col = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    FILE *file = NULL;
    char line[MAX_SIZE];
    printf("Loading %s file\n", path);

    //Open the file
    file = fopen(path, "r");
    if(file == NULL){
        printf("File not found : %s\n", path);
        exit(EXIT_FAILURE);
    }

    //Get the number of rows
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

    //Get the number of columns
    fgets(line, MAX_SIZE, file);
    col = atoi(line);
    if(col < 1){
        printf("Columns must be > 1 : %d\n", col);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    if(col > MAX_SIZE){
        printf("Columns too big : %d\n", col);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    //Alloc the two-dimension array
    map = malloc(sizeof(Map));
    if(map == NULL){
        printf("Error during map allocation\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    map->row = row;
    map->col = col;

    //Create all the cells of the map
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
            printf("Error, number of columns does not correspond : %d != %d\n", (int)strlen(line) - 1, map->col);
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
}

/*
 *
 * Function used to print the map in a text way
 *
 */
void printMap(Map *map){
    unsigned int i = 0, j = 0;
    for(i = 0 ; i < map->row ; i++){
        for(j = 0 ; j  < map->col ; j++){
            printf("%c", map->cells[i][j]);
        }
        printf("\n");
    }
}

/*
 *
 * Function used to test the collision of an object, depending on the position and its speed and direction
 * Return 0 if the object can't pass
 * Return the type of the object touched either
 *
 */
char testCollision(unsigned int newX, unsigned int newY){
    Map *map = getMapInstance();
    char result = '1';
    int xMap = round(newX / TILE_SIZE);
    int yMap = round(newY / TILE_SIZE);
    switch(map->cells[yMap][xMap]){
        default:
            result = map->cells[yMap][xMap];
            break;
    }
    return result;
}

int *testCoude(unsigned int newX, unsigned int newY, int* rep) {
    Map *map = getMapInstance();
    int xMap = round(newX / TILE_SIZE);
    int xMap1 = round((newX - SPEED)/TILE_SIZE);
    int xMap2 = round((newX + SPEED)/TILE_SIZE);
    int yMap = round(newY / TILE_SIZE);
    int yMap1 = round((newY - SPEED)/TILE_SIZE);
    int yMap2 = round((newY + SPEED)/TILE_SIZE);
    rep =(int*)malloc(4*sizeof(int));

    if (map->cells[yMap1][xMap] == '.') {
        rep[0] = 1;
    } else if (map->cells[yMap2][xMap] == '.') {
        rep[2] = 1;
    } else if (map->cells[yMap][xMap1] == '.') {
        rep[3] = 1;
    } else if (map->cells[yMap][xMap2] == '.') {
        rep[1] = 1;
    }
    return rep;
}

/*
 *
 * Function used to free the elements of a map
 *
 */
void freeMap(){
    unsigned int i = 0;
    for(i = 0 ; i < map->row ; i++){
        free(map->cells[i]);
    }
    free(map->cells);
    free(map);
}
