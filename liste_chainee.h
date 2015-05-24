#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element
{
    int *nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    int nuplet;
    Element *premier;
};

Liste *initialisation(int nbvaleur);
void insertion(Liste *liste, int *nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
int Empty(Liste *l); // 0 la liste est vide 1 sinon
Element *head(Liste *l); // Renvoie la tête de la liste sans la modifier (pas de remove ni de deplacement)
Liste *tail(Liste *l); // Renvoie la queue de la liste sans supprimer la tête
int nuplet(Liste *l);
int appartient(Element *e,Liste *l,int te);

#endif
