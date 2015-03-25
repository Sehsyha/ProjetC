#ifndef MAP_H
#define MAP_H

typedef struct Map Map;
struct Map
{
    int col;
    int row;
    int **lines;
};
#endif
