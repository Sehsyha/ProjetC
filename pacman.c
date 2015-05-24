#include "pacman.h"

Pacman *pacman = NULL;

Pacman *getPacmanInstance(){
    if(pacman == NULL){
        pacman = malloc(sizeof(Pacman));
        Map *map = getMapInstance();
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
            pacman->x = j * TILE_SIZE;
            pacman->y = i * TILE_SIZE;
            pacman->direction = STATIC;
            pacman->futureDirection = STATIC;
            pacman->life = START_LIFE;
            pacman->point = 0;
            pacman->powerTime = 0;
        }
    }
    return pacman;
}


/*
 *
 * Function used to set the direction or the future direction of the pacman
 *
 */
void setPacmanDirection(unsigned int direction){
    Pacman *pacman = getPacmanInstance();
    if(pacman->direction == STATIC){
        pacman->direction = direction;
    }else if(pacman->x % TILE_SIZE == 0 && pacman->y % TILE_SIZE == 0){
        switch(direction){
            case NORTH:
                if(testCollision(pacman->x, pacman->y - SPEED) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case SOUTH:
                if(testCollision(pacman->x, pacman->y + SPEED + TILE_SIZE - 1) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case EAST:
                if(testCollision(pacman->x + SPEED + TILE_SIZE - 1, pacman->y) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
            case WEST:
                if(testCollision(pacman->x - SPEED, pacman->y) != WALL){
                    pacman->direction = direction;
                    pacman->futureDirection = STATIC;
                }
                break;
        }
    }else{
        pacman->futureDirection = direction;
    }
}

/*
 *
 * Free the pacman object
 *
 */
void freePacman(){
    free(pacman);
}
