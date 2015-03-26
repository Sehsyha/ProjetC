#include "pacman.h"

void moveCorrect(Map *map, Pacman *pacman, int changeX, int changeY);
int detectCollision(Map *map, Pacman *pacman, int changeX, int changeY);

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
        pacman = malloc(sizeof(Pacman));
        pacman->x = j;
        pacman->y = i;
        pacman->life = START_LIFE;
        pacman->point = 0;
    }
    return pacman;
}

void freePacman(Pacman *pacman){
    free(pacman);
}

int move(Map *map, Pacman *pacman, int move){
    int correctMove = 1;
    switch(move){
        case NORTH:
            correctMove = detectCollision(map, pacman, 0, -1);
            break;
        case SOUTH:
            correctMove = detectCollision(map, pacman, 0, 1);
            break;
        case EAST:
            correctMove = detectCollision(map, pacman, 1, 0);
            break;
        case WEST:
            correctMove = detectCollision(map, pacman, -1, 0);
            break;
    }

    return correctMove;
}

void moveCorrect(Map *map, Pacman *pacman, int changeX, int changeY){
    map->cells[pacman->y][pacman->x] = VOID;
    pacman->x += changeX;
    pacman->y += changeY;
    map->cells[pacman->y][pacman->x] = PAC;
}


int detectCollision(Map *map, Pacman *pacman, int changeX, int changeY){
    int correctMove = 1;
    switch(map->cells[pacman->y + changeY][pacman->x + changeX]){
        case WALL:
            correctMove = 0;
            break;
        case GUM:
            pacman->point += 1;
        case VOID:
            moveCorrect(map, pacman, changeX, changeY);
            break;
    }
    return correctMove;
}
