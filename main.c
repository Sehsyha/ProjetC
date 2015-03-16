#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    //Affichage de la fe,être
    SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
    //Booleen de fin de boucle
    int continuer = 1;
    //Evenement clavier
    SDL_Event event;
    //Boucle
    while(continuer){
        SDL_WaitEvent(&event);

        //Traitement de l'évènement
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
    printf("Hé ouaip ça pèèèèèse grave!!\n");
    SDL_Quit();
    return EXIT_SUCCESS;
}

