#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pacman.h"
#include <SDL2/SDL.h>

int main(void)
{
    Map *map = loadMap("1.map");
    Pacman *pacman = searchAndCreate(map);
    if(!pacman){
        printf("Pacman not found on map\n");
        freeMap(map);
        exit(EXIT_FAILURE);
    }
    printf("Pacman found !\n");
    printMap(map);
    int continuer = 1;
    char input;
    while(continuer){
        scanf(" %c", &input);
        switch(input){
            case 'q':
                continuer = 0;
                break;
            case 'n':
                move(map, pacman, NORTH);
                break;
            case 'e':
                move(map, pacman, EAST);
                break;
            case 's':
                move(map, pacman, SOUTH);
                break;
            case 'w':
                move(map, pacman, WEST);
                break;
        }
        printf("X : %d, Y : %d, points : %d\n", pacman->x, pacman->y, pacman->point);
        printMap(map);
    }

//    printf("SDL initialisation\n");

//    SDL_Window *window = 0;
//    SDL_Event event;
//    int terminate = 0;

//    if(SDL_Init(SDL_INIT_VIDEO) < 0){
//        printf("Error with SDL : %s\n", SDL_GetError());
//        SDL_Quit();
//        freeMap(map);
//        return EXIT_FAILURE;
//    }

//    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TILE_SIZE * map->row, TILE_SIZE * map->col, SDL_WINDOW_SHOWN);

//    if(window == 0){
//        printf("Error during window creation : %s \n", SDL_GetError());
//        SDL_Quit();
//        freeMap(map);
//        return EXIT_FAILURE;
//    }

//    printf("SDL init success\n");
//    while(!terminate){
//        SDL_WaitEvent(&event);
//        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
//            terminate = 1;
//        }
//    }

//    SDL_DestroyWindow(window);
//    SDL_Quit();
    freePacman(pacman);
    freeMap(map);
    return EXIT_SUCCESS;
}

