#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = -1;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

int Empty(Liste *l) {
    if (l->premier->nombre == -1) {
        return 0;
    } else {
        return 1;
    }
}


void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
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
    if (Emplty(l) == 0) {
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
