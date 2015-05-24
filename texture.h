#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void loadTextures(SDL_Renderer *renderer);
void freeTextures();


SDL_Texture *getTextureWallV();
SDL_Texture *getTextureWallH();
SDL_Texture *getTextureWallNW();
SDL_Texture *getTextureWallNE();
SDL_Texture *getTextureWallSW();
SDL_Texture *getTextureWallSE();
SDL_Texture *getTextureVoid();
SDL_Texture *getTexturePacman();
SDL_Texture *getTexturePacmanN();
SDL_Texture *getTexturePacmanE();
SDL_Texture *getTexturePacmanS();
SDL_Texture *getTexturePacmanW();
SDL_Texture *getTextureGum();
SDL_Texture *getTextureClyde();
SDL_Texture *getTextureBlinky();


#endif
