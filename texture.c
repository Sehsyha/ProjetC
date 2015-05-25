#include "texture.h"

//Regroupe les fonctions qui instancie pour la SDL toutes les textures utilisé


SDL_Texture *textureWallV = NULL;
SDL_Texture *textureWallH = NULL;
SDL_Texture *textureWallNW = NULL;
SDL_Texture *textureWallNE = NULL;
SDL_Texture *textureWallSW = NULL;
SDL_Texture *textureWallSE = NULL;
SDL_Texture *textureVoid = NULL;
SDL_Texture *texturePacman = NULL;
SDL_Texture *texturePacmanN = NULL;
SDL_Texture *texturePacmanE = NULL;
SDL_Texture *texturePacmanS = NULL;
SDL_Texture *texturePacmanW = NULL;
SDL_Texture *textureGum = NULL;
SDL_Texture *textureClyde = NULL;
SDL_Texture *textureBlinky = NULL;
SDL_Texture *textureInky = NULL;
SDL_Texture *texturePinky = NULL;
SDL_Texture *textureBigGum = NULL;
SDL_Texture *textureFear = NULL;
SDL_Texture *textureGate = NULL;
SDL_Texture *textureQ = NULL;

SDL_Texture *getTextureQ(){
    return textureQ;
}

SDL_Texture *getTextureGate(){
    return textureGate;
}

SDL_Texture *getTextureFear(){
    return textureFear;
}

SDL_Texture *getTextureBigGum(){
    return textureBigGum;
}

SDL_Texture *getTextureWallV(){
    return textureWallV;
}

SDL_Texture *getTextureWallH(){
    return textureWallH;
}

SDL_Texture *getTextureWallNW(){
    return textureWallNW;
}

SDL_Texture *getTextureWallNE(){
    return textureWallNE;
}

SDL_Texture *getTextureWallSW(){
    return textureWallSW;
}

SDL_Texture *getTextureWallSE(){
    return textureWallSE;
}

SDL_Texture *getTextureVoid(){
    return textureVoid;
}

SDL_Texture *getTexturePacman(){
    return texturePacman;
}

SDL_Texture *getTexturePacmanN(){
    return texturePacmanN;
}

SDL_Texture *getTexturePacmanE(){
    return texturePacmanE;
}

SDL_Texture *getTexturePacmanS(){
    return texturePacmanS;
}

SDL_Texture *getTexturePacmanW(){
    return texturePacmanW;
}

SDL_Texture *getTextureGum(){
    return textureGum;
}

SDL_Texture *getTextureClyde(){
    return textureClyde;
}

SDL_Texture *getTextureBlinky(){
    return textureBlinky;
}

SDL_Texture *getTextureInky(){
    return textureInky;
}

SDL_Texture *getTexturePinky(){
    return texturePinky;
}

void loadTextures(SDL_Renderer *renderer){
    //Create the textures of all the sprites we need

    SDL_Surface *q = IMG_Load("../projec/texture/personnage/ghost/quinson.png");
    textureQ = SDL_CreateTextureFromSurface(renderer, q);
    SDL_FreeSurface(q);

    SDL_Surface *gate = IMG_Load("../projec/texture/mur/gate.png");
    textureGate = SDL_CreateTextureFromSurface(renderer, gate);
    SDL_FreeSurface(gate);

    SDL_Surface *bigGum = IMG_Load("../projec/texture/gum/bigGum.png");
    textureBigGum = SDL_CreateTextureFromSurface(renderer, bigGum);
    SDL_FreeSurface(bigGum);

    SDL_Surface *fear = IMG_Load("../projec/texture/personnage/ghost/fear.png");
    textureFear = SDL_CreateTextureFromSurface(renderer, fear);
    SDL_FreeSurface(fear);

    SDL_Surface *wallV = IMG_Load("../projec/texture/mur/wallV.png");
    textureWallV = SDL_CreateTextureFromSurface(renderer, wallV);
    SDL_FreeSurface(wallV);

    SDL_Surface *wallH = IMG_Load("../projec/texture/mur/wallH.png");
    textureWallH = SDL_CreateTextureFromSurface(renderer, wallH);
    SDL_FreeSurface(wallH);

    SDL_Surface *wallNW = IMG_Load("../projec/texture/mur/wallNW.png");
    textureWallNW = SDL_CreateTextureFromSurface(renderer, wallNW);
    SDL_FreeSurface(wallNW);

    SDL_Surface *wallNE = IMG_Load("../projec/texture/mur/wallNE.png");
    textureWallNE = SDL_CreateTextureFromSurface(renderer, wallNE);
    SDL_FreeSurface(wallNE);

    SDL_Surface *wallSW = IMG_Load("../projec/texture/mur/wallSW.png");
    textureWallSW = SDL_CreateTextureFromSurface(renderer, wallSW);
    SDL_FreeSurface(wallSW);

    SDL_Surface *wallSE = IMG_Load("../projec/texture/mur/wallSE.png");
    textureWallSE = SDL_CreateTextureFromSurface(renderer, wallSE);
    SDL_FreeSurface(wallSE);

    SDL_Surface *voidI = IMG_Load("../projec/texture/mur/void.png");
    textureVoid = SDL_CreateTextureFromSurface(renderer, voidI);
    SDL_FreeSurface(voidI);

    SDL_Surface *pacmanI = IMG_Load("../projec/texture/personnage/pacman/pacman.png");
    texturePacman = SDL_CreateTextureFromSurface(renderer, pacmanI);
    SDL_FreeSurface(pacmanI);

    SDL_Surface *pacmanN = IMG_Load("../projec/texture/personnage/pacman/pacmanN.png");
    texturePacmanN = SDL_CreateTextureFromSurface(renderer, pacmanN);
    SDL_FreeSurface(pacmanN);

    SDL_Surface *pacmanE = IMG_Load("../projec/texture/personnage/pacman/pacmanE.png");
    texturePacmanE = SDL_CreateTextureFromSurface(renderer, pacmanE);
    SDL_FreeSurface(pacmanE);

    SDL_Surface *pacmanS = IMG_Load("../projec/texture/personnage/pacman/pacmanS.png");
    texturePacmanS = SDL_CreateTextureFromSurface(renderer, pacmanS);
    SDL_FreeSurface(pacmanS);

    SDL_Surface *pacmanW = IMG_Load("../projec/texture/personnage/pacman/pacmanW.png");
    texturePacmanW = SDL_CreateTextureFromSurface(renderer, pacmanW);
    SDL_FreeSurface(pacmanW);

    SDL_Surface *gumI = IMG_Load("../projec/texture/gum/gum.png");
    textureGum = SDL_CreateTextureFromSurface(renderer, gumI);
    SDL_FreeSurface(gumI);

    SDL_Surface *clydeI = IMG_Load("../projec/texture/personnage/ghost/clyde.png");
    textureClyde = SDL_CreateTextureFromSurface(renderer, clydeI);
    SDL_FreeSurface(clydeI);

    SDL_Surface *blinkyI = IMG_Load("../projec/texture/personnage/ghost/blinky.png");
    textureBlinky = SDL_CreateTextureFromSurface(renderer, blinkyI);
    SDL_FreeSurface(blinkyI);

    SDL_Surface *inkyI = IMG_Load("../projec/texture/personnage/ghost/inky.png");
    textureInky = SDL_CreateTextureFromSurface(renderer, inkyI);
    SDL_FreeSurface(inkyI);

    SDL_Surface *pinkyI = IMG_Load("../projec/texture/personnage/ghost/pinky.png");
    texturePinky = SDL_CreateTextureFromSurface(renderer, pinkyI);
    SDL_FreeSurface(pinkyI);
}

void freeTextures(){
    SDL_DestroyTexture(textureGate);
    SDL_DestroyTexture(textureWallV);
    SDL_DestroyTexture(textureWallH);
    SDL_DestroyTexture(textureWallNE);
    SDL_DestroyTexture(textureWallNW);
    SDL_DestroyTexture(textureWallSE);
    SDL_DestroyTexture(textureWallSW);
    SDL_DestroyTexture(textureClyde);
    SDL_DestroyTexture(textureBlinky);
    SDL_DestroyTexture(textureInky);
    SDL_DestroyTexture(texturePinky);
    SDL_DestroyTexture(textureVoid);
    SDL_DestroyTexture(textureGum);
    SDL_DestroyTexture(texturePacman);
    SDL_DestroyTexture(texturePacmanN);
    SDL_DestroyTexture(texturePacmanE);
    SDL_DestroyTexture(texturePacmanS);
    SDL_DestroyTexture(texturePacmanW);
    SDL_DestroyTexture(textureBigGum);
    SDL_DestroyTexture(textureFear);
}
