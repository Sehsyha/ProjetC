#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pacman.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 60

/*
 *
 * Function used to update the map with the move of the pacman
 *
 */
void update(Map *map, Pacman *pacman){
    switch(pacman->direction){
        case NORTH:
            if(testCollision(map, pacman->x, pacman->y - SPEED) != WALL){
                pacman->y -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case SOUTH:
            if(testCollision(map, pacman->x, pacman->y + SPEED + TILE_SIZE - 1) != WALL){
                pacman->y += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case EAST:
            if(testCollision(map, pacman->x + SPEED + TILE_SIZE - 1, pacman->y) != WALL){
                pacman->x += SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
        case WEST:
            if(testCollision(map, pacman->x - SPEED, pacman->y) != WALL){
                pacman->x -= SPEED;
            }else{
                pacman->direction = pacman->futureDirection;
                pacman->futureDirection = STATIC;
            }
            break;
    }
    printf("X : %d , Y : %d\n", pacman->x, pacman->y);
}

/*
 *
 * Function used to print the map and the pacman
 *
 */
int render(SDL_Texture *textureVoid, SDL_Texture *textureGum, SDL_Texture *texturePacman, SDL_Texture *texturePacmanN, SDL_Texture *texturePacmanS, SDL_Texture *texturePacmanE, SDL_Texture *texturePacmanW,SDL_Texture *textureWall, SDL_Renderer *renderer, Map *map, Pacman *pacman, int open)
{
    unsigned int i, j;
    //Clean the view
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    //Print the map
    for(i = 0 ; i < map->row ; i++){
        for(j = 0 ; j < map->col ; j++){
            SDL_Rect dest = { i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            switch(map->cells[j][i]){
                case WALL:
                    SDL_RenderCopy(renderer, textureWall, NULL, &dest);
                    break;
                case GUM:
                    SDL_RenderCopy(renderer, textureGum, NULL, &dest);
                    break;
                case VOID:
                    SDL_RenderCopy(renderer, textureVoid, NULL, &dest);
                    break;
            }
        }
    }
    SDL_Rect dest = {pacman->x, pacman->y, TILE_SIZE, TILE_SIZE};
    if(open >= 0){
        switch(pacman->direction){
            case NORTH:
                SDL_RenderCopy(renderer, texturePacmanN, NULL, &dest);
                break;
            case SOUTH:
                SDL_RenderCopy(renderer, texturePacmanS, NULL, &dest);
                break;
            case EAST:
                SDL_RenderCopy(renderer, texturePacmanE, NULL, &dest);
                break;
            case WEST:
                SDL_RenderCopy(renderer, texturePacmanW, NULL, &dest);
                break;
            case STATIC:
                SDL_RenderCopy(renderer, texturePacman, NULL, &dest);
                break;
        }
        open++;
        if(open >= FPS / (FPS / 10)){
            open = -FPS / (FPS / 10);
        }
    }else{

         SDL_RenderCopy(renderer, texturePacman, NULL, &dest);
         open++;
    }

    SDL_RenderPresent(renderer);
    return open;
}

/*
 *
 * Main function
 *
 */
int main(void)
{
    //Load the map
    Map *map = loadMap("../projec/1.map");

    //Search the pacman on the map and create him
    Pacman *pacman = searchAndCreate(map);

    //If the pacman is not found
    if(!pacman){
        printf("Pacman not found on map\n");
        freeMap(map);
        exit(EXIT_FAILURE);
    }
    printf("Pacman found !\n");
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
    SDL_Surface *wallI = IMG_Load("../projec/wall.png");
    SDL_Texture *textureWall = SDL_CreateTextureFromSurface(renderer, wallI);
    SDL_FreeSurface(wallI);

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


    int open = 0;
    //Infinite loop until we want to stop the game
    while(!terminate){
        open = render(textureVoid, textureGum, texturePacman, texturePacmanN, texturePacmanS, texturePacmanE, texturePacmanW, textureWall, renderer, map, pacman, open);
        //Event handling
        SDL_PollEvent(&event);
        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
            terminate = 1;
        }
        switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode){
                    case SDL_SCANCODE_UP:
                        setDirection(map, pacman, NORTH);
                        break;
                    case SDL_SCANCODE_DOWN:
                        setDirection(map, pacman, SOUTH);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        setDirection(map, pacman, EAST);
                        break;
                    case SDL_SCANCODE_LEFT:
                        setDirection(map, pacman, WEST);
                        break;
                    default:
                        break;
                }
                break;
        }
        update(map, pacman);
        SDL_Delay(1000 / FPS);
    }

    //Free all the objects we don't need anymore
    SDL_DestroyTexture(textureWall);
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
    freePacman(pacman);
    freeMap(map);
    return EXIT_SUCCESS;
}

