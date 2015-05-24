#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

Liste *initialisation(int nbvaleur)
{
    Liste *liste = malloc(sizeof(*liste));

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    liste->nuplet = nbvaleur;

    return liste;
}

int isEmpty(Liste *l) {
    return l->premier == NULL;
}

int isEqual(Element *e,Element *p,int te, int tp) {
    int rep = 1,i;
    if (tp == te) {
        for(i = 0; i < te; i++) {
            rep = rep && ((e->nombre[i]) == (p->nombre[i]));
        }
    } else {
        rep = 0;
    }

    return rep;
}

int appartient(Element *e,Liste *l,int te) {
    Liste *p;
    p=l;
    int taille = p->nuplet;

    if (te != l->nuplet) {
        return 0;
    } else {
        while(p->premier != NULL) {
            if (isEqual(e,p->premier,te,taille)) {
                return 1;
            } else {
                p->premier = p->premier->suivant;
            }
        }
    }
    return 0;
}


void insertion(Liste *liste, int *nvNombre, float f_score, float g_score)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    nouveau->f_score = f_score;
    nouveau->g_score = g_score;

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

    if (liste->premier)
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
    int i = 0 ;
    while (actuel != NULL)
    {
        printf("[ ");
        for(i = 0 ; i < liste->nuplet ; i++){
            printf("%d", actuel->nombre[i]);
            printf(", ");
        }
        printf("%f, %f", actuel->f_score, actuel->g_score);
        printf(" ]");
        actuel = actuel->suivant;
        printf("->");
    }
    printf("NULL\n");
}

Element *head(Liste *l) {
    if (isEmpty(l) == 0) {
        return l->premier;
    } else {
        return NULL;
    }

}

Liste *tail(Liste *l) {
    if (!isEmpty(l)) {
        l->premier = l->premier->suivant;
        return l;
    } else {
        return NULL;
    }
}

int nuplet(Liste *l) {
    if (!isEmpty(l)) {
        return -1;
    } else {
        return l->nuplet;
    }
}
