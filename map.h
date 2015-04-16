#ifndef MAP_H
#define MAP_H

#define MAX_SIZE 100
#define TILE_SIZE 20
#define GUM '.'
#define WALL '1'
#define PAC '2'
#define VOID '0'
#define CLYDE 'C'

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define STATIC 4

typedef struct Map Map;
struct Map
{
    unsigned int col;
    unsigned int row;
    char **cells;
};

void printMap(Map *map);
Map *loadMap(char *path);
void freeMap(Map *map);
char testCollision(Map *map, unsigned int newX, unsigned int newY);

#endif
