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
    move(map, pacman, NORTH);
    printMap(map);

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

