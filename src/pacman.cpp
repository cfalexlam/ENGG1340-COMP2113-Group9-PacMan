#include "pacman.h"

void Pacman::setCurrentPosition(int row, int col)
{
    /*
    Function: Change pacman's current poistion
    Input: 2 integers: horizontal position and vetical position
    Output: None
    */
    this->currentPosition[0] = row;         
    this->currentPosition[1] = col;
}

void Pacman::setCurrentVelocity(int row, int col)
{
    /*
    Function: Change pacman's current velocity
    Input: 2 integers: horizontal velocity and vetical velocity
    Output: None
    */
    this->currentVelocity[0] = row;
    this->currentVelocity[1] = col;
}

void Pacman::setPresumedVelocity(int row, int col)
{
    /*
    Function: Change pacman's presumed velocity
    Input: 2 integers:  horizontal velocity and vetical velocity
    Output: None
    */
    this->presumedVelocity[0] = row;
    this->presumedVelocity[1] = col;
}

int* Pacman::getPresumedPosition()
{
    /*
    Function: Get pacman's presumed position
    Input: None
    Output: An array, which represent pacman's presumed position
    */
    this->presumedPosition[0] = this->currentPosition[0] + this->currentVelocity[0];
    this->presumedPosition[1] = this->currentPosition[1] + this->currentVelocity[1];
    return this->presumedPosition;
}

int* Pacman::getCurrentVelocity()
{
    /*
    Function: Get pacman's current velocity
    Input: None
    Output: An array, which represent pacman's current velocity
    */
    return this->currentVelocity;
}

int* Pacman::getCurrentPosition()
{
    /*
    Function: Get pacman's current velocity
    Input: None
    Output: An array, which represent pacman's current position
    */
    return this->currentPosition;
}

int* Pacman::getPresumedVelocity() 
{
    /*
    Function: Get pacman's current velocity
    Input: 
    Output: An array, which represent pacman's presumed velocity
    */
    return this->presumedVelocity;
}



