#ifndef MAP_H
#define MAP_H

#define MAX_SIZE 100
#define GUM 0
#define WALL 1
#define PAC 2

typedef struct Map Map;
struct Map
{
    unsigned int col;
    unsigned int row;
    int **cells;
};
Map *loadMap(char *path);
void freeMap(Map *map);

#endif
