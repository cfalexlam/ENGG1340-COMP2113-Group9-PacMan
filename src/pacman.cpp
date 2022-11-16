#include <pacman.h>


Pacman::Pacman(int spawnX, int spawnY){
  this->postion[0] = spawnX;
  this->postion[1] = spawnY;
}
int* Pacman::getVelocity()
{
  return this->velocity;
}

int* Pacman::getPosition()
{
  return this->position;
}

void Pacman::changeDirection(int x , int y){
  this->velocity[0] = x;
  this->velocity[1] = y;
}


