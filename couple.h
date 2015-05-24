#ifndef COUPLE
#define COUPLE


typedef struct couple {
    int first;
    int second;
} couple;


couple *initialisation();
void couple_free(couple *c);
int getFirst(couple *c);
int getSecond(couple *c);
void setFirst(couple *c,int a);
void setSecond(couple *c,int a);


#endif
