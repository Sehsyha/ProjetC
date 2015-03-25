#include <stdio.h>
#include <stdlib.h>
#include "map.h"


int main(void)
{
    Map *map = loadMap();
    freeMap(map);
    return EXIT_SUCCESS;
}

