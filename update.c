#include "update.h"

/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
void update(Ghost *clyde, Ghost *blinky){
    Map *map = getMapInstance();
    Pacman *pacman = getPacmanInstance();
    int result = 0;
    if(clyde->x % TILE_SIZE == 0 && clyde->y % TILE_SIZE == 0){
        if(clyde->futureDirection != STATIC){
            clyde->direction = clyde->futureDirection;
            clyde->futureDirection = STATIC;
        }
    }
    switch(clyde->direction){
        case NORTH:
            if(testCollision(clyde->x, clyde->y - SPEED) != WALL){
                clyde->y -= SPEED;
            }else{
                clyde->direction = clyde->futureDirection;
                clyde->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if(testCollision(clyde->x, clyde->y + SPEED + TILE_SIZE - 1) != WALL){
                clyde->y += SPEED;
            }else{
                clyde->direction = clyde->futureDirection;
                clyde->futureDirection = STATIC;
            }
            break;
        case EAST:
            if(testCollision(clyde->x + SPEED + TILE_SIZE - 1, clyde->y) != WALL){
                clyde->x += SPEED;
            }else{
                clyde->direction = clyde->futureDirection;
                clyde->futureDirection = STATIC;
            }
            break;
        case WEST:
            if(testCollision(clyde->x - SPEED, clyde->y) != WALL){
                clyde->x -= SPEED;
            }else{
                clyde->direction = clyde->futureDirection;
                clyde->futureDirection = STATIC;
            }
            break;
    }

    if(blinky->x % TILE_SIZE == 0 && blinky->y % TILE_SIZE == 0){
        if(blinky->futureDirection != STATIC){
            blinky->direction = blinky->futureDirection;
            blinky->futureDirection = STATIC;
        }
    }
    switch(blinky->direction){
        case NORTH:
            if(testCollision(blinky->x, blinky->y - SPEED) != WALL){
                blinky->y -= SPEED;
            }else{
                blinky->direction = blinky->futureDirection;
                blinky->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if(testCollision(blinky->x, blinky->y + SPEED + TILE_SIZE - 1) != WALL){
                blinky->y += SPEED;
            }else{
                blinky->direction = blinky->futureDirection;
                blinky->futureDirection = STATIC;
            }
            break;
        case EAST:
            if(testCollision(blinky->x + SPEED + TILE_SIZE - 1, blinky->y) != WALL){
                blinky->x += SPEED;
            }else{
                blinky->direction = blinky->futureDirection;
                blinky->futureDirection = STATIC;
            }
            break;
        case WEST:
            if(testCollision(blinky->x - SPEED, blinky->y) != WALL){
                blinky->x -= SPEED;
            }else{
                blinky->direction = blinky->futureDirection;
                blinky->futureDirection = STATIC;
            }
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
