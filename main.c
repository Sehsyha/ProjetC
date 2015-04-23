#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "render.h"
#include "config.h"


/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
void update(Map *map, Pacman *pacman, Ghost *clyde){
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

    //Create the textures of all the sprites we need
    SDL_Surface *wallV = IMG_Load("../projec/wallV.png");
    SDL_Texture *textureWallV = SDL_CreateTextureFromSurface(renderer, wallV);
    SDL_FreeSurface(wallV);

    SDL_Surface *wallH = IMG_Load("../projec/wallH.png");
    SDL_Texture *textureWallH = SDL_CreateTextureFromSurface(renderer, wallH);
    SDL_FreeSurface(wallH);

    SDL_Surface *wallNW = IMG_Load("../projec/wallNW.png");
    SDL_Texture *textureWallNW = SDL_CreateTextureFromSurface(renderer, wallNW);
    SDL_FreeSurface(wallNW);

    SDL_Surface *wallNE = IMG_Load("../projec/wallNE.png");
    SDL_Texture *textureWallNE = SDL_CreateTextureFromSurface(renderer, wallNE);
    SDL_FreeSurface(wallNE);

    SDL_Surface *wallSW = IMG_Load("../projec/wallSW.png");
    SDL_Texture *textureWallSW = SDL_CreateTextureFromSurface(renderer, wallSW);
    SDL_FreeSurface(wallSW);

    SDL_Surface *wallSE = IMG_Load("../projec/wallSE.png");
    SDL_Texture *textureWallSE = SDL_CreateTextureFromSurface(renderer, wallSE);
    SDL_FreeSurface(wallSE);

    SDL_Surface *voidI = IMG_Load("../projec/void.png");
    SDL_Texture *textureVoid = SDL_CreateTextureFromSurface(renderer, voidI);
    SDL_FreeSurface(voidI);

    SDL_Surface *pacmanI = IMG_Load("../projec/pacman.png");
    SDL_Texture *texturePacman = SDL_CreateTextureFromSurface(renderer, pacmanI);
    SDL_FreeSurface(pacmanI);

    SDL_Surface *pacmanN = IMG_Load("../projec/pacmanN.png");
    SDL_Texture *texturePacmanN = SDL_CreateTextureFromSurface(renderer, pacmanN);
    SDL_FreeSurface(pacmanN);

    SDL_Surface *pacmanE = IMG_Load("../projec/pacmanE.png");
    SDL_Texture *texturePacmanE = SDL_CreateTextureFromSurface(renderer, pacmanE);
    SDL_FreeSurface(pacmanE);

    SDL_Surface *pacmanS = IMG_Load("../projec/pacmanS.png");
    SDL_Texture *texturePacmanS = SDL_CreateTextureFromSurface(renderer, pacmanS);
    SDL_FreeSurface(pacmanS);

    SDL_Surface *pacmanW = IMG_Load("../projec/pacmanW.png");
    SDL_Texture *texturePacmanW = SDL_CreateTextureFromSurface(renderer, pacmanW);
    SDL_FreeSurface(pacmanW);

    SDL_Surface *gumI = IMG_Load("../projec/gum.png");
    SDL_Texture *textureGum = SDL_CreateTextureFromSurface(renderer, gumI);
    SDL_FreeSurface(gumI);

    SDL_Surface *clydeI = IMG_Load("../projec/clyde.png");
    SDL_Texture *textureClyde = SDL_CreateTextureFromSurface(renderer, clydeI);
    SDL_FreeSurface(clydeI);


    int open = 0;
    //Infinite loop until we want to stop the game
    while(!terminate){
        renderMap(textureVoid, textureGum, textureWallH, textureWallV, textureWallNE, textureWallNW, textureWallSE, textureWallSW, renderer);
        open = renderPacman(texturePacman, texturePacmanS, texturePacmanN, texturePacmanW, texturePacmanE, open, renderer);
        renderClyde(textureClyde, clyde, renderer);
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
        update(map, pacman, clyde);
        SDL_Delay(1000 / FPS);
    }

    //Free all the objects we don't need anymore
    SDL_DestroyTexture(textureWallV);
    SDL_DestroyTexture(textureWallH);
    SDL_DestroyTexture(textureWallNE);
    SDL_DestroyTexture(textureWallNW);
    SDL_DestroyTexture(textureWallSE);
    SDL_DestroyTexture(textureWallSW);
    SDL_DestroyTexture(textureClyde);
    SDL_DestroyTexture(textureVoid);
    SDL_DestroyTexture(textureGum);
    SDL_DestroyTexture(texturePacman);
    SDL_DestroyTexture(texturePacmanN);
    SDL_DestroyTexture(texturePacmanE);
    SDL_DestroyTexture(texturePacmanS);
    SDL_DestroyTexture(texturePacmanW);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    freePacman();
    freeMap();
    return EXIT_SUCCESS;
}

