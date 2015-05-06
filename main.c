#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "render.h"
#include "config.h"
#include "texture.h"
#include "update.h"


/*
 *
 * Main function
 *
 */
int main(void)
{
    //Load the map
    loadMap("../projec/1.map");

    //Search the pacman on the map and create him
    Pacman *pacman = getPacmanInstance();
    Map *map = getMapInstance();
    //If the pacman is not found
    if(!pacman){
        printf("Pacman not found on map\n");
        freeMap(map);
        exit(EXIT_FAILURE);
    }
    printf("Pacman found !\n");

    Ghost *clyde = searchAndCreateGhost(CLYDE);
    if(!clyde){
        printf("Clyde not found on map\n");
        freeMap(map);
        exit(EXIT_FAILURE);
    }
    printf("Clyde found !\n");

    Ghost *blinky = searchAndCreateGhost(BLINKY);
    if(!blinky){
        printf("Blinky not found on map\n");
        freeMap(map);
        freeGhost(clyde);
        exit(EXIT_FAILURE);
    }
    printf("Blinky found !\n");
    printf("SDL initialisation\n");

    //Create SDL objects
    SDL_Window *window = 0;
    SDL_Event event;
    int terminate = 0;

    //Initialise SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error with SDL : %s\n", SDL_GetError());
        SDL_Quit();
        freeMap(map);
        return EXIT_FAILURE;
    }

    //Create the window
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TILE_SIZE * map->row, TILE_SIZE * map->col, SDL_WINDOW_SHOWN);

    //If there is an error
    if(window == 0){
        printf("Error during window creation : %s \n", SDL_GetError());
        SDL_Quit();
        freeMap(map);
        return EXIT_FAILURE;
    }

    printf("SDL init success\n");
    SDL_Renderer *renderer = 0;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //NEED gerer erreurs


    loadTextures(renderer);

    int open = 0;
    //Infinite loop until we want to stop the game
    while(!terminate){
        renderMap(renderer);
        open = renderPacman(open, renderer);
        renderClyde(clyde, renderer);
        renderBlinky(blinky, renderer);


        changeDirectionGhost(blinky);
        changeDirectionGhost(clyde);

        SDL_RenderPresent(renderer);
        //Event handling
        SDL_PollEvent(&event);
        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
            terminate = 1;
        }
        switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode){
                    case SDL_SCANCODE_UP:
                        setPacmanDirection(NORTH);
                        break;
                    case SDL_SCANCODE_DOWN:
                        setPacmanDirection(SOUTH);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        setPacmanDirection(EAST);
                        break;
                    case SDL_SCANCODE_LEFT:
                        setPacmanDirection(WEST);
                        break;
                    default:
                        break;
                }
                break;
        }
        update(clyde, blinky);
        SDL_Delay(1000 / FPS);
    }


    freeTextures();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    freePacman();
    freeGhost(clyde);
    freeGhost(blinky);
    freeMap();
    return EXIT_SUCCESS;
}

