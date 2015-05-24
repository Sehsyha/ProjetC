#include "ghost.h"
#include "astar.h"
void changeDirectionClyde(Ghost *g);
void changeDirectionBlinky(Ghost *g);
void changeDirectionInky(Ghost *g);
void changeDirectionPinky(Ghost *g);

Ghost *searchAndCreateGhost(char ghostType){
    Map *map = getMapInstance();
    Ghost *g = 0;
    unsigned int i = 0, j = 0;
    int found = 0;
    while(i < map->row && !found){
        j = 0;
        while(j < map->col && !found){
            if(map->cells[i][j] == ghostType){
                found = 1;
            }
            j++;
        }
        i++;
    }
    j--;
    i--;
    if(found){
        g = malloc(sizeof(Ghost));
        g->x = j * TILE_SIZE;
        g->y = i * TILE_SIZE;
        g->initialX = g->x;
        g->initialY = g->y;
        g->direction = STATIC;
        g->futureDirection = STATIC;
        g->type = ghostType;
    }
    return g;
}

void freeGhost(Ghost *g){
    free(g);
}

void changeDirectionGhost(Ghost *g){
    switch(g->type){
        case CLYDE:
            changeDirectionClyde(g);
            break;
        case BLINKY:
            changeDirectionBlinky(g);
            break;
        case INKY:
            changeDirectionInky(g);
            break;
        case PINKY:
            changeDirectionPinky(g);
            break;
    }
}

void changeDirectionClyde(Ghost *g){


    int collision = 1;
    switch(g->direction){
        case NORTH:
            if(testCollision(g->x, g->y - SPEED) != WALL){
                collision = 0;
            }
            break;
        case SOUTH:
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL){
                collision = 0;
            }
            break;
        case EAST:
            if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                collision = 0;
            }
            break;
        case WEST:
            if(testCollision(g->x - SPEED, g->y) != WALL){
                collision = 0;
            }
            break;
    }
    if(collision){
        unsigned int direction = rand() % 4;
        collision = 1;
        do{
            direction = rand() % 4;
            switch(direction){
                case NORTH:
                    if(testCollision(g->x, g->y - SPEED) != WALL){
                        collision = 0;
                    }
                    break;
                case SOUTH:
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL){
                        collision = 0;
                    }
                    break;
                case EAST:
                    if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                        collision = 0;
                    }
                    break;
                case WEST:
                    if(testCollision(g->x - SPEED, g->y) != WALL){
                        collision = 0;
                    }
                    break;
            }
        }while(collision);

        if(direction != g->direction){
            if(g->direction == STATIC){
                g->direction = direction;
            }else{
                g->futureDirection = direction;
            }
        }
    }
}

void changeDirectionBlinky(Ghost *g){

    int collision = 1;

    switch(g->direction){
        case NORTH:
            if(testCollision(g->x, g->y - SPEED) != WALL){
                collision = 0;
            }
            break;
        case SOUTH:
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL){
                collision = 0;
            }
            break;
        case EAST:
            if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                collision = 0;
            }
            break;
        case WEST:
            if(testCollision(g->x - SPEED, g->y) != WALL){
                collision = 0;
            }
            break;
    }
    if (collision == 0) {
        unsigned int direction = rand() % 4;
        collision = 1;
        do{
            direction = rand() % 4;
            switch(direction){
                case NORTH:
                    if(testCollision(g->x, g->y - SPEED) != WALL){
                        collision = 0;
                    }
                    break;
                case SOUTH:
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL){
                        collision = 0;
                    }
                    break;
                case EAST:
                    if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                        collision = 0;
                    }
                    break;
                case WEST:
                    if(testCollision(g->x - SPEED, g->y) != WALL){
                        collision = 0;
                    }
                    break;
            }
        }while(collision);

        if(direction != g->direction){
            if(g->direction == STATIC){
                g->direction = direction;
            }else{
                g->futureDirection = direction;
            }
        }
    }

}

void changeDirectionInky(Ghost *g){
    g->direction = nextDirection(g);
}


void changeDirectionPinky(Ghost *g){
    g->direction = nextDirection(g);
}

