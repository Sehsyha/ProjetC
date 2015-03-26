#include <stdio.h>
#include <stdlib.h>
#include "map.h"


int main(void)
{
    Map *map = loadMap("1.map");
    freeMap(map);
    return EXIT_SUCCESS;
}

