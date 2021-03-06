#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


/*
 * Regroupe les fonctions qui instancie pour la SDL toutes les textures utilisé
 *
 */


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
SDL_Texture *getTextureInky();
SDL_Texture *getTexturePinky();
SDL_Texture *getTextureBigGum();
SDL_Texture *getTextureFear();
SDL_Texture *getTextureGate();


#endif
