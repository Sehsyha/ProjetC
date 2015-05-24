#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
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
    loadMap("../projec/maplol.map");

    //Search the pacman on the map and create him
    Pacman *pacman = getPacmanInstance();
    unsigned int initialX = pacman->x;
    unsigned int initialY = pacman->y;
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

    Ghost *inky = searchAndCreateGhost(INKY);
    if(!inky){
        printf("Inky not found on map\n");
        freeMap(map);
        freeGhost(clyde);
        freeGhost(blinky);
        exit(EXIT_FAILURE);
    }
    printf("Inky found !\n");

    Ghost *pinky = searchAndCreateGhost(PINKY);
    if(!pinky){
        printf("Pinky not found on map\n");
        freeMap(map);
        freeGhost(clyde);
        freeGhost(blinky);
        freeGhost(inky);
        exit(EXIT_FAILURE);
    }
    printf("Pinky found !\n");
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

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
        printf("%s", Mix_GetError());
    }

    Mix_Music *music = NULL;
    music = Mix_LoadMUS("../projec/pacman.wav");
    if(!music){
        printf("Erreur de chargement de la musique %s \n", Mix_GetError());
    }else{
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        Mix_PlayMusic(music, -1);
    }

    if(TTF_Init() == -1){
        printf("Error during TTF initialization : %s\n", TTF_GetError());
    }

    TTF_Font *police = NULL;

    police = TTF_OpenFont("../projec/monof.ttf", 65);
    if(!police){
        printf("Error during font load : %s\n", TTF_GetError());
    }
    SDL_Color color = { 255, 255, 255, 255};



    //Create the window
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TILE_SIZE * map->col, TILE_SIZE * map->row + TILE_SIZE, SDL_WINDOW_SHOWN);

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

    SDL_Surface *score = TTF_RenderText_Solid(police, "Score : ", color);
    SDL_Texture *scoreT = SDL_CreateTextureFromSurface(renderer, score);
    SDL_FreeSurface(score);
    char scoreString[15];

    SDL_Rect dest = {0, map->row * TILE_SIZE , map->row * TILE_SIZE / 6, 20};
    SDL_RenderCopy(renderer, scoreT, NULL, &dest);
    SDL_Surface *scoreN;
    SDL_Texture *scoreTN;
    int open = 0;
    //Infinite loop until we want to stop the game
    while(!terminate){
        SDL_Rect dest2 = {map->row * TILE_SIZE / 6, map->row * TILE_SIZE, map->row * TILE_SIZE / 15, 20};
        sprintf(scoreString, "%d", pacman->point);
        scoreN = TTF_RenderText_Solid(police, scoreString, color);
        scoreTN = SDL_CreateTextureFromSurface(renderer, score);
        renderMap(renderer);
        open = renderPacman(open, renderer);
        renderClyde(clyde, renderer);
        renderBlinky(blinky, renderer);
        renderPinky(pinky, renderer);
        renderInky(inky, renderer);

        changeDirectionGhost(blinky);
        changeDirectionGhost(clyde);
        changeDirectionGhost(inky);
        changeDirectionGhost(pinky);
        SDL_Rect dest = {0, map->row * TILE_SIZE , map->row * TILE_SIZE / 6, 20};
        SDL_RenderCopy(renderer, scoreT, NULL, &dest);



        SDL_RenderCopy(renderer, scoreTN, NULL, &dest2);

        SDL_RenderPresent(renderer);
        //Event handling

        SDL_PollEvent(&event);
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
        terminate = update(clyde, blinky, inky, pinky);
        if(terminate){
            if(pacman->life > 0 ){
                pacman->life--;
                terminate = 0;
                pacman->x = initialX;
                pacman->y = initialY;
            }
        }
        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
            terminate = 1;
        }
        SDL_Delay(1000 / FPS);
        SDL_DestroyTexture(scoreTN);
        SDL_FreeSurface(scoreN);
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    freeTextures();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_DestroyTexture(scoreT);
    freePacman();
    freeGhost(clyde);
    freeGhost(blinky);
    freeGhost(inky);
    freeGhost(pinky);
    freeMap();
    TTF_CloseFont(police);
    TTF_Quit();
    return EXIT_SUCCESS;
}

