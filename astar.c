#include "astar.h"


unsigned int nextDirection(int srcX, int srcY, int dstX, int dstY){
    int diffX = srcX - dstX;
    int diffY = srcY - dstY;
    int direction = STATIC;
    if(abs(diffX) > abs(diffY)){
        if(diffX < 0){
            direction = EAST;
        }else{
            direction = WEST;
        }
    }else{
        if(diffY < 0){
            direction = SOUTH;
        }else{
            direction = NORTH;
        }
    }
    return direction;
}
