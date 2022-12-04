#include "pellet.h"

Pellet::Pellet(int row, int col)
/*
    Function: Construct a pellet object
    Input: Row and column position of the pellet
    Output: None
*/
{
    this -> position[0] = row;
    this -> position[1] = col;
}

int * Pellet::getPosition()
/*
    Function: Get the position of the pellet
    Input: None
    Output: An integer pointer to the position array.
*/
{
    return this -> position;
}