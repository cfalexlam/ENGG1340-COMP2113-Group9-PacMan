#include <pacman.h>

Pacman::Pacman(int spawnRow, int spawnCol){
  this->postion[0] = spawnRow;
  this->postion[1] = spawnCol;
}

void Pacman::setPosition(int row , int col)
{
  this->postion[0] = row;
  this->postion[1] = col;
}

void Pacman::setVelocity(int row , int col){
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



