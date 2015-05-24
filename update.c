#include "update.h"
#include "config.h"

int collision(Ghost *ghost);

/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
int update(Ghost *clyde, Ghost *blinky, Ghost *inky, Ghost *pinky){
    Map *map = getMapInstance();
    Pacman *pacman = getPacmanInstance();
    int result = 0;
    if(pacman->powerTime > 0){
        pacman->powerTime--;
    }
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
            if((result = testCollision(pacman->x, pacman->y - SPEED)) != WALL && result != GATE){
                pacman->y -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if((result = testCollision(pacman->x, pacman->y + SPEED + TILE_SIZE - 1)) != WALL && result != GATE){
                pacman->y += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case EAST:
            if((result = testCollision(pacman->x + SPEED + TILE_SIZE - 1, pacman->y)) != WALL && result != GATE){
                pacman->x += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case WEST:
            if((result = testCollision(pacman->x - SPEED, pacman->y)) != WALL && result != GATE){
                pacman->x -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
    }
    if(result == BIGGUM){
        pacman->point += 100;
        pacman->powerTime = FPS * POWER_TIME;
        map->cells[pacman->y / TILE_SIZE][pacman->x / TILE_SIZE] = VOID;
    }
    if(result == GUM){
        map->cells[pacman->y / TILE_SIZE][pacman->x / TILE_SIZE] = VOID;
        pacman->point++;
    }
    result = 0;
    if(collision(clyde)){
        if(pacman->powerTime > 0){
            pacman->point += 250;
            clyde->x = clyde->initialX;
            clyde->y = clyde->initialY;
        }else{
            result = 1;
        }

    }
    if(collision(blinky)){
        if(pacman->powerTime > 0){
            pacman->point += 250;
            clyde->x = clyde->initialX;
            clyde->y = clyde->initialY;
        }else{
            result = 1;
        }
    }
    if(collision(inky)){
        if(pacman->powerTime > 0){
            pacman->point += 250;
            inky->x = inky->initialX;
            inky->y = inky->initialY;
        }else{
            result = 1;
        }
    }
    if(collision(pinky)){
        if(pacman->powerTime > 0){
            pacman->point += 250;
            pinky->x = pinky->initialX;
            pinky->y = pinky->initialY;
        }else{
            result = 1;
        }
    }
    return result;
}

int inSquare(Ghost *ghost, unsigned int x, unsigned int y){
    return x >= ghost->x && y >= ghost->y && x <= ghost->x + TILE_SIZE && y <= ghost->y + TILE_SIZE;
}

int collision(Ghost *ghost){
    int retour = 0;
    Pacman *pacman = getPacmanInstance();
    if(inSquare(ghost, pacman->x, pacman->y)){
        retour = 1;
    }
    if(inSquare(ghost, pacman->x, pacman->y + TILE_SIZE - 1)){
        retour = 1;
    }
    if(inSquare(ghost, pacman->x + TILE_SIZE - 1, pacman->y)){
        retour = 1;
    }
    if(inSquare(ghost, pacman->x + TILE_SIZE - 1, pacman->y + TILE_SIZE - 1)){
        retour = 1;
    }


    return retour;
}
