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
        g->sortie = 0;
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

    if (g->sortie == 0) {
        if (testCollision(g->x, g->y - SPEED) == WALL) {
            g->sortie = 1;
        } else {
            g->direction = 0;
        }

    } else {

        int collision = 1;
        switch(g->direction){
        case NORTH:
            if(testCollision(g->x, g->y - SPEED) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                collision = 0;
            }
            break;
        case SOUTH:
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                collision = 0;
            }
            break;
        case EAST:
            if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                collision = 0;
            }
            break;
        case WEST:
            if(testCollision(g->x - SPEED, g->y) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
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
                    if(testCollision(g->x, g->y - SPEED) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                        collision = 0;
                    }
                    break;
                case SOUTH:
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                        collision = 0;
                    }
                    break;
                case EAST:
                    if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
                        collision = 0;
                    }
                    break;
                case WEST:
                    if(testCollision(g->x - SPEED, g->y) != WALL || testCollision(g->x, g->y - SPEED) != GATE){
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
}

void changeDirectionBlinky(Ghost *g){

    if (g->sortie == 0) {

        if (testCollision(g->x,g->y - SPEED) == GATE || testCollision(g->x + SPEED , g->y) == WALL) {
            g->sortie = 1;
        }

        if (testCollision(g->x, g->y - SPEED) == WALL) {
            g->direction = 1;
        } else {
            g->direction = 0;
        }

    } else {

        unsigned int direction = g->direction;
        int tc = testCoude(g->x,g->y);
        if (tc > 0) {
            if (tc == 1) {
                direction = rand() % 2;
            } else if (tc == 2) {
                direction = 1 + rand() % 2;
            } else if (tc == 3) {
                direction = 2 + rand() % 2;
            } else if (tc == 4) {
                direction = ( 3 + rand() % 2) % 4;
            } else if (tc == 5) {
                direction = (rand()%2 == 0)? 0 : 2;
            } else if (tc == 6) {
                direction = (rand()%2 == 0 )? 1 : 3;
            }
        }

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
    if (g->sortie == 0) {
        if (testCollision(g->x, g->y - SPEED) == WALL) {
            g->sortie = 1;
        } else {
            g->direction = 0;
        }

    } else {
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

}


void changeDirectionPinky(Ghost *g){
    if (g->sortie == 0) {
        if (testCollision(g->x, g->y - SPEED) == WALL) {
            g->direction = 3;
        } else {
            g->direction = 0;
        }

        if (testCollision(g->x + SPEED , g->y) == WALL) {
            g->sortie = 1;
        }

    } else {

        unsigned int direction = g->direction;
        int tc = testCoude(g->x,g->y);
        if (tc > 0) {
            if (tc == 1) {
                direction = rand() % 2;
            } else if (tc == 2) {
                direction = 1 + rand() % 2;
            } else if (tc == 3) {
                direction = 2 + rand() % 2;
            } else if (tc == 4) {
                direction = ( 3 + rand() % 2) % 4;
            } else if (tc == 5) {
                direction = (rand()%2 == 0)? 0 : 2;
            } else if (tc == 6) {
                direction = (rand()%2 == 0 )? 1 : 3;
            }
        }

        if(direction != g->direction){
            if(g->direction == STATIC){
                g->direction = direction;
            }else{
                g->futureDirection = direction;
            }
        }
    }
}
