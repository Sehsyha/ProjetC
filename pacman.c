#include "pacman.h"

Pacman *searchAndCreate(Map *map){
    Pacman *pacman = 0;
    unsigned int i = 0, j = 0;
    int found = 0;
    printf("%d %d\n", map->row, map->col);
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

int move(Map *map, Pacman *pacman){

    return 0;
}
