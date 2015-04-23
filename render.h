#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "config.h"

int renderPacman(SDL_Texture *texturePacman, SDL_Texture *texturePacmanS, SDL_Texture *texturePacmanN, SDL_Texture *texturePacmanW, SDL_Texture *texturePacmanE, int open, SDL_Renderer *renderer);
void renderMap(SDL_Texture *textureVoid, SDL_Texture *textureGum, SDL_Texture *textureWallH, SDL_Texture *textureWallV, SDL_Texture *textureWallNE, SDL_Texture *textureWallNW, SDL_Texture *textureWallSE, SDL_Texture *textureWallSW, SDL_Renderer *renderer);
void renderClyde(SDL_Texture *textureClyde, Ghost *clyde, SDL_Renderer *renderer);

#endif
