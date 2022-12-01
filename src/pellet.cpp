#include "pellet.h"

Pellet::Pellet(int row,int col)
{
    this->position[0]=row;
    this->position[1]=col;
}
int* Pellet::getPosition()
{
    return this->position;
}

void Pellet::setPosition(int row, int col) {
    this->position[0] = row;
    this->position[1] = col;
}