#include "ghost.h"
#include "astar.h"
void changeDirectionClyde(Ghost *g);
void changeDirectionBlinky(Ghost *g);
void changeDirectionInky(Ghost *g);
void changeDirectionPinky(Ghost *g);


// Instancie les fantomes aprés lecture sur la carte
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

//Efface le fantome de la memoire
void freeGhost(Ghost *g){
    free(g);
}

// Attribut au fantome en attribut une nouvelle direction suivant son algorithme
void changeDirectionGhost(Ghost *g){
    Pacman *pacman = getPacmanInstance();
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

// Algorithme de deplacement de Clyde ( change de direction à chaque collision)
void changeDirectionClyde(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    if(g->sortie == 0 && pacman->powerTime > 0){

    }else
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
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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

// Algorithme de deplacement de Blinky ( change de direction à chaque collision)
void changeDirectionBlinky(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    if(g->sortie == 0 && pacman->powerTime > 0){

    }else
    if (g->sortie == 0) {

        if (testCollision(g->x, g->y - SPEED) != WALL) {
            g->direction = 0;
        } else if (testCollision(g->x + SPEED, g->y) != WALL) {
            g->direction = 1;
        }

        if (testCollision(g->x,g->y - SPEED) == GATE || testCollision(g->x , g->y + SPEED) == WALL) {
            g->sortie = 1;
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
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
                        collision = 0;
                    }
                    break;
                case EAST:
                    if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                        collision = 0;
                    }
                    break;
                case WEST:
                    if(testCollision(g->x - SPEED, g->y) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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

// Algorithme de deplacement de Inky ( change de direction à chaque collision)
void changeDirectionInky(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    if(g->sortie == 0 && pacman->powerTime > 0){

    }else
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
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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

// Algorithme de deplacement de Pynky ( change de direction à chaque collision)
void changeDirectionPinky(Ghost *g){
    Pacman *pacman = getPacmanInstance();
    if(g->sortie == 0 && pacman->powerTime > 0){

    }else
    if (g->sortie == 0) {

        if (testCollision(g->x, g->y - SPEED) != WALL) {
            g->direction = 0;
        } else if (testCollision(g->x + SPEED, g->y) != WALL) {
            g->direction = 3;
        }

        if (testCollision(g->x,g->y - SPEED) == GATE || testCollision(g->x , g->y + SPEED) == WALL) {
            g->sortie = 1;
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
            if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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
                    if(testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
                        collision = 0;
                    }
                    break;
                case EAST:
                    if(testCollision(g->x + SPEED + TILE_SIZE - 1, g->y) != WALL){
                        collision = 0;
                    }
                    break;
                case WEST:
                    if(testCollision(g->x - SPEED, g->y) != WALL && testCollision(g->x, g->y + SPEED + TILE_SIZE - 1) != GATE){
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

