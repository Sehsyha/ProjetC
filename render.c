#include "render.h"

/*
 *
 * Function used to render the pacman
 *
 */
int renderPacman(int open, SDL_Renderer *renderer){
    Pacman *pacman = getPacmanInstance();
    SDL_Rect dest = {pacman->x, pacman->y, TILE_SIZE, TILE_SIZE};
    if(open >= 0){
        switch(pacman->direction){
            case NORTH:
                SDL_RenderCopy(renderer, getTexturePacmanN(), NULL, &dest);
                break;
            case SOUTH:
                SDL_RenderCopy(renderer, getTexturePacmanS(), NULL, &dest);
                break;
            case EAST:
                SDL_RenderCopy(renderer, getTexturePacmanE(), NULL, &dest);
                break;
            case WEST:
                SDL_RenderCopy(renderer, getTexturePacmanW(), NULL, &dest);
                break;
            case STATIC:
                SDL_RenderCopy(renderer, getTexturePacman(), NULL, &dest);
                break;
        }
        open++;
        if(open >= FPS / (FPS / 10)){
            open = -FPS / (FPS / 10);
        }
    }else{

         SDL_RenderCopy(renderer, getTexturePacman(), NULL, &dest);
         open++;
    }
    Map *map = getMapInstance();
    int i = 0;
    for(i = pacman->life ; i > 0; i--){
        SDL_Rect dest2 = { map->col * TILE_SIZE - i * TILE_SIZE, map->row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        SDL_RenderCopy(renderer, getTexturePacman(), NULL, &dest2);
    }
    return open;
}

/*
 *
 * Function used to print the map and the pacman
 *
 */
void renderMap(SDL_Renderer *renderer){
    Map *map = getMapInstance();
    unsigned int i, j;
    //Clean the view
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    //Print the map
    for(i = 0 ; i < map->col ; i++){
        for(j = 0 ; j < map->row; j++){
            SDL_Rect dest = { i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            switch(map->cells[j][i]){
                case WALL:
                    if(j > 0 && i > 0 && i < map->col - 1 && j < map->row - 1){
//                        printf("%d %d\n", j, i);
                        if(map->cells[j - 1][i] == WALL && map->cells[j + 1][i] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallV(), NULL, &dest);
                        }else if(map->cells[j][i - 1] == WALL && map->cells[j][i + 1] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallH(), NULL, &dest);
                        }else if(map->cells[j][i + 1] == WALL && map->cells[j + 1][i] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallNW(), NULL, &dest);
                        }else if(map->cells[j][i + 1] == WALL && map->cells[j - 1][i] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallSW(), NULL, &dest);
                        }else if(map->cells[j][i - 1] == WALL && map->cells[j + 1][i] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallNE(), NULL, &dest);
                        }else if(map->cells[j][i - 1] == WALL && map->cells[j - 1][i] == WALL){
                            SDL_RenderCopy(renderer, getTextureWallSE(), NULL, &dest);
                        }
                    }else{
                        if(i == 0 && j == 0){
                            SDL_RenderCopy(renderer, getTextureWallNW(), NULL, &dest);
                        }else if(i == 0 && j == map->row - 1){
                            SDL_RenderCopy(renderer, getTextureWallSW(), NULL, &dest);
                        }else if(i == map->col - 1 && j == 0){
                            SDL_RenderCopy(renderer, getTextureWallNE(), NULL, &dest);
                        }else if(i == map->col - 1 && j == map->row - 1){
                            SDL_RenderCopy(renderer, getTextureWallSE(), NULL, &dest);
                        }else if(i == 0){
                            if(map->cells[j + 1][i] == WALL && map->cells[j - 1][i] == WALL){
                                SDL_RenderCopy(renderer, getTextureWallV(), NULL, &dest);
                            }
                        }else if(j == 0){
                            if(map->cells[j][i + 1] == WALL && map->cells[j][i - 1] == WALL){
                                SDL_RenderCopy(renderer, getTextureWallH(), NULL, &dest);
                            }
                        }else if(i == map->col - 1){
                            if(map->cells[j + 1][i] == WALL && map->cells[j - 1][i] == WALL){
                                SDL_RenderCopy(renderer, getTextureWallV(), NULL, &dest);
                            }
                        }else if(j == map->row - 1){
                            if(map->cells[j][i + 1] == WALL && map->cells[j][i - 1] == WALL){
                                SDL_RenderCopy(renderer, getTextureWallH(), NULL, &dest);
                            }
                        }
                    }
                    break;
                case GUM:
                    SDL_RenderCopy(renderer, getTextureGum(), NULL, &dest);
                    break;
                case BIGGUM:
                    SDL_RenderCopy(renderer, getTextureBigGum(), NULL, &dest);
                    break;
                default:
                case VOID:
                    SDL_RenderCopy(renderer, getTextureVoid(), NULL, &dest);
                    break;
            }
        }
    }
}

void renderClyde(Ghost *clyde, SDL_Renderer *renderer){
    SDL_Rect dest = { clyde->x, clyde->y, TILE_SIZE, TILE_SIZE };
    Pacman *pacman = getPacmanInstance();
    if(pacman->powerTime > 0){
        SDL_RenderCopy(renderer, getTextureFear(), NULL, &dest);
    }else{
        SDL_RenderCopy(renderer, getTextureClyde(), NULL, &dest);
    }
}

void renderBlinky(Ghost *blinky, SDL_Renderer *renderer){
    SDL_Rect dest = { blinky->x, blinky->y, TILE_SIZE, TILE_SIZE };
    Pacman *pacman = getPacmanInstance();
    if(pacman->powerTime > 0){
        SDL_RenderCopy(renderer, getTextureFear(), NULL, &dest);
    }else{
        SDL_RenderCopy(renderer, getTextureBlinky(), NULL, &dest);
    }
}

void renderInky(Ghost *inky, SDL_Renderer *renderer){
    SDL_Rect dest = { inky->x, inky->y, TILE_SIZE, TILE_SIZE };
    Pacman *pacman = getPacmanInstance();
    if(pacman->powerTime > 0){
        SDL_RenderCopy(renderer, getTextureFear(), NULL, &dest);
    }else{
        SDL_RenderCopy(renderer, getTextureInky(), NULL, &dest);
    }
}

void renderPinky(Ghost *pinky, SDL_Renderer *renderer){
    SDL_Rect dest = { pinky->x, pinky->y, TILE_SIZE, TILE_SIZE };
    SDL_RenderCopy(renderer, getTexturePinky(), NULL, &dest);
    Pacman *pacman = getPacmanInstance();
    if(pacman->powerTime > 0){
        SDL_RenderCopy(renderer, getTextureFear(), NULL, &dest);
    }else{
        SDL_RenderCopy(renderer, getTexturePinky(), NULL, &dest);
    }
}
