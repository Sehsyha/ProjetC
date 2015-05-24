#include <stdio.h>
#include <stdlib.h>
#include "couple.h"


couple *initialisation() {

    couple *p;
    p = (couple *)malloc(sizeof(couple));

    if (p != NULL) {
        p ->first = -1;
        p ->second = -1;
    } else {
        exit(EXIT_FAILURE);
    }
}

void couple_free(couple *c) {
    free(p);
}

int getFirst(couple *c) {
    return c ->first;
}

int getSecond(couple *c) {
    return c ->second;
}

void setFirst(couple *c,int a) {
    c->first = a;
}

void setSecond(couple *c,int a) {
    c->second = a;
}
