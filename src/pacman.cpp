#include "pacman.h"

void Pacman::setPosition(int row, int col)
{
  this->position[0] = row;
  this->position[1] = col;
}

void Pacman::setVelocity(int row, int col){
  this->velocity[0] = row;
  this->velocity[1] = col;
}

int* Pacman::getVelocity()
{
  return this->velocity;
}

int* Pacman::getPosition()
{
  return this->position;
}



