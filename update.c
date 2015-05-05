#include "update.h"

/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
void update(Ghost *clyde){
    Map *map = getMapInstance();
    Pacman *pacman = getPacmanInstance();
    int result = 0;
    switch(clyde->direction){
        case NORTH:
            clyde->y -= SPEED;
            break;
        case SOUTH:
            clyde->y += SPEED;
            break;
        case EAST:
            clyde->x += SPEED;
            break;
        case WEST:
            clyde->x -= SPEED;
            break;
    }

    switch(pacman->direction){
        case NORTH:
            if((result = testCollision(pacman->x, pacman->y - SPEED)) != WALL){
                pacman->y -= SPEED;

            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if((result = testCollision(pacman->x, pacman->y + SPEED + TILE_SIZE - 1)) != WALL){
                pacman->y += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case EAST:
            if((result = testCollision(pacman->x + SPEED + TILE_SIZE - 1, pacman->y)) != WALL){
                pacman->x += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case WEST:
            if((result = testCollision(pacman->x - SPEED, pacman->y)) != WALL){
                pacman->x -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
    }
    if(result == GUM){
        map->cells[pacman->y / TILE_SIZE][pacman->x / TILE_SIZE] = VOID;
        pacman->point++;
    }
}
