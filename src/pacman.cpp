#include <pacman.h>

Pacman::Pacman(int spawnX, int spawnY){
  this->postion[0] = spawnX;
  this->postion[1] = spawnY;
}

void Pacman::setPosition(int x , int y)
{
  this->postion[0] = x;
  this->postion[1] = y;
}

void Pacman::setVelocity(int x , int y){
  this->velocity[0] = x;
  this->velocity[1] = y;
}

int* Pacman::getVelocity()
{
  return this->velocity;
}

int* Pacman::getPosition()
{
  return this->position;
}



