#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

Liste *initialisation(int nbvaleur)
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = malloc(nbvaleur*sizeof(int));
    element->suivant = NULL;
    liste->premier = element;
    liste->nuplet = nbvaleur;

    return liste;
}

int Empty(Liste *l) {
    if (l->premier->nombre == -1) {
        return 0;
    } else {
        return 1;
    }
}


void insertion(Liste *liste, int *nvNombre)
{
    /* Cr�ation du nouvel �l�ment */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'�l�ment au d�but de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

Element *head(Liste *l) {
    if (Empty(l) == 0) {
        return l->premier;
    } else {
        return NULL;
    }

}

Liste *tail(Liste *l) {
    if (Empty(l) == 0) {
        l->premier = l->premier->suivant;
        return l;
    } else {
        return NULL;
    }
}

int nuplet(Liste *l) {
    if (Empty(l) == 0) {
        return -1;
    } else {
        l->nuplet;
    }
}
