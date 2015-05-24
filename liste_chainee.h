#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element
{
    int *nombre;
    float f_score;
    float g_score;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    int nuplet;
    Element *premier;
};

Liste *initialisation(int nbvaleur);
void insertion(Liste *liste, int *nvNombre, float f_score, float g_score);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
int isEmpty(Liste *l);
Element *head(Liste *l); // Renvoie la tête de la liste sans la modifier (pas de remove ni de deplacement)
Liste *tail(Liste *l); // Renvoie la queue de la liste sans supprimer la tête
int nuplet(Liste *l);
int appartient(Element *e,Liste *l,int te);

#endif
