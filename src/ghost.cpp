#include <ghost.h>

void Ghost::setPosition(int row, int col)
{
  this->position[0] = row;
  this->position[1] = col;
}

void Ghost::setVelocity(int row, int col){
  this->velocity[0] = row;
  this->velocity[1] = col;
}

int* Ghost::getVelocity()
{
  return this->velocity;
}

int* Ghost::getPosition()
{
  return this->position;
}



