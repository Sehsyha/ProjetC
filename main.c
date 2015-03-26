#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pacman.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
//    printMap(map);
//    int continuer = 1;
//    char input;
//    while(continuer){
//        scanf(" %c", &input);
//        switch(input){
//            case 'q':
//                continuer = 0;
//                break;
//            case 'n':
//                move(map, pacman, NORTH);
//                break;
//            case 'e':
//                move(map, pacman, EAST);
//                break;
//            case 's':
//                move(map, pacman, SOUTH);
//                break;
//            case 'w':
//                move(map, pacman, WEST);
//                break;
//        }
//        printf("X : %d, Y : %d, points : %d\n", pacman->x, pacman->y, pacman->point);
//        printMap(map);
//    }

    printf("SDL initialisation\n");

    SDL_Window *window = 0;
    SDL_Event event;
    int terminate = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error with SDL : %s\n", SDL_GetError());
        SDL_Quit();
        freeMap(map);
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TILE_SIZE * map->row, TILE_SIZE * map->col, SDL_WINDOW_SHOWN);

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
    SDL_Surface *wallI = IMG_Load("wall.png");
    SDL_Texture *textureWall = SDL_CreateTextureFromSurface(renderer, wallI);
    SDL_FreeSurface(wallI);

    SDL_Surface *voidI = IMG_Load("void.png");
    SDL_Texture *textureVoid = SDL_CreateTextureFromSurface(renderer, voidI);
    SDL_FreeSurface(voidI);

    SDL_Surface *pacmanI = IMG_Load("pacman.png");
    SDL_Texture *texturePacman = SDL_CreateTextureFromSurface(renderer, pacmanI);
    SDL_FreeSurface(pacmanI);

    SDL_Surface *gumI = IMG_Load("gum.png");
    SDL_Texture *textureGum = SDL_CreateTextureFromSurface(renderer, gumI);
    SDL_FreeSurface(gumI);

    unsigned int i = 0, j = 0;
    while(!terminate){
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
                    case PAC:
                        SDL_RenderCopy(renderer, texturePacman, NULL, &dest);
                        break;
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_WaitEvent(&event);
        if(event.window.event == SDL_WINDOWEVENT_CLOSE){
            terminate = 1;
        }
        switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode){
                    case SDL_SCANCODE_UP:
                        move(map, pacman, NORTH);
                        break;
                    case SDL_SCANCODE_DOWN:
                        move(map, pacman, SOUTH);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        move(map, pacman, EAST);
                        break;
                    case SDL_SCANCODE_LEFT:
                        move(map, pacman, WEST);
                        break;
                    default:
                        break;
                }

                break;
        }
    }
    SDL_DestroyTexture(textureWall);
    SDL_DestroyTexture(textureVoid);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    freePacman(pacman);
    freeMap(map);
    return EXIT_SUCCESS;
}

