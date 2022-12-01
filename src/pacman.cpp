#include "pacman.h"

void Pacman::setCurrentPosition(int row, int col)
{
    this->currentPosition[0] = row;
    this->currentPosition[1] = col;
}

void Pacman::setCurrentVelocity(int row, int col)
{
    this->currentVelocity[0] = row;
    this->currentVelocity[1] = col;
}

void Pacman::setPresumedVelocity(int row, int col)
{
    this->presumedVelocity[0] = row;
    this->presumedVelocity[1] = col;
}

int* Pacman::getPresumedPosition()
{
    this->presumedPosition[0] = this->currentPosition[0] + this->currentVelocity[0];
    this->presumedPosition[1] = this->currentPosition[1] + this->currentVelocity[1];
    return this->presumedPosition;
}

int* Pacman::getCurrentVelocity()
{
    return this->currentVelocity;
}

int* Pacman::getCurrentPosition()
{
    return this->currentPosition;
}

int* Pacman::getPresumedVelocity() 
{
    return this->presumedVelocity;
}



