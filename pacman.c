#include "pacman.h"

/*
 *
 * Function used to search the pacman in a map and create the object
 *
 */
Pacman *searchAndCreate(Map *map){
    Pacman *pacman = 0;
    unsigned int i = 0, j = 0;
    int found = 0;
    while(i < map->row && !found){
        j = 0;
        while(j < map->col && !found){
            if(map->cells[i][j] == PAC){
                found = 1;
            }
            j++;
        }
        i++;
    }
    j--;
    i--;
    if(found){
        //Remove the pacman from the map
        map->cells[i][j] = VOID;
        pacman = malloc(sizeof(Pacman));
        pacman->x = j * TILE_SIZE;
        pacman->y = i * TILE_SIZE;
        pacman->direction = STATIC;
        pacman->futureDirection = STATIC;
        pacman->life = START_LIFE;
        pacman->point = 0;
    }
    return pacman;
}

/*
 *
 * Function used to set the direction or the future direction of the pacman
 *
 */
void setDirection(Map *map, Pacman *pacman, unsigned int direction){
    if(pacman->direction == STATIC){
        pacman->direction = direction;
    }else{
        switch(direction){
            case NORTH:
                if(testCollision(map, pacman->x, pacman->y - SPEED) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case SOUTH:
                if(testCollision(map, pacman->x, pacman->y + SPEED + TILE_SIZE - 1) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case EAST:
                if(testCollision(map, pacman->x + SPEED + TILE_SIZE - 1, pacman->y) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case WEST:
                if(testCollision(map, pacman->x - SPEED, pacman->y) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
        }

        pacman->futureDirection = direction;
    }
}

/*
 *
 * Free the pacman object
 *
 */
void freePacman(Pacman *pacman){
    free(pacman);
}
