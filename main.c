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

/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
void update(Ghost *clyde){
    Map *map = getMapInstance();
    Pacman *pacman = getPacmanInstance();
    int result = 0;
    if(clyde->direction == EAST){
        clyde->x += SPEED;

    }
    switch(pacman->direction){
        case NORTH:
            if((result = testCollision(pacman->x, pacman->y - SPEED)) != WALL){
                pacman->y -= SPEED;

            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if((result = testCollision(pacman->x, pacman->y + SPEED + TILE_SIZE - 1)) != WALL){
                pacman->y += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case EAST:
            if((result = testCollision(pacman->x + SPEED + TILE_SIZE - 1, pacman->y)) != WALL){
                pacman->x += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case WEST:
            if((result = testCollision(pacman->x - SPEED, pacman->y)) != WALL){
                pacman->x -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
    }
    if(result == GUM){
        map->cells[pacman->y / TILE_SIZE][pacman->x / TILE_SIZE] = VOID;
        pacman->point++;
    }
}


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

    Ghost *clyde = searchAndCreateGhost(map, CLYDE);
    if(!clyde){
        printf("Clyde not found on map\n");
        freeMap(map);
        exit(EXIT_FAILURE);
    }
    printf("Clyde found !\n");
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
        changeDirectionGhost(map, clyde);
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
        update(clyde);
        SDL_Delay(1000 / FPS);
    }


    freeTextures();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    freePacman();
    freeMap();
    return EXIT_SUCCESS;
}

