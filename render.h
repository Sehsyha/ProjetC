#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "config.h"
#include "texture.h"

int renderPacman(int open, SDL_Renderer *renderer);
void renderMap(SDL_Renderer *renderer);
void renderClyde(Ghost *clyde, SDL_Renderer *renderer);
void renderBlinky(Ghost *blinky, SDL_Renderer *renderer);
void renderInky(Ghost *inky, SDL_Renderer *renderer);
void renderPinky(Ghost *pinky, SDL_Renderer *renderer);
#endif
