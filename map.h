#ifndef MAP_H
#define MAP_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <pacman.h>

#define MAX_SIZE 100
#define TILE_SIZE 20
#define GUM '.'
#define WALL '1'
#define GATE '-'
#define PAC '2'
#define VOID '0'
#define CLYDE 'C'
#define BLINKY 'B'
#define PINKY 'P'
#define INKY 'I'
#define BIGGUM 'G'

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

Map *getMapInstance();
void printMap(Map *map);
void loadMap(char *path);
void freeMap();
char testCollision(unsigned int newX, unsigned int newY);
<<<<<<< HEAD
int *testCoude(unsigned int newX, unsigned int newY);

=======
int *testCoude(unsigned int newX, unsigned int newY, int *rep);
void setQ();
int getQ();
>>>>>>> 7cc32468e8556d976d99e6e79a06b42293818c5a
#endif
