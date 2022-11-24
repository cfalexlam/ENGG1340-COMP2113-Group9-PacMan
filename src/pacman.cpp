#include <pacman.h>



int Pacman::getXVelocity()
{
  return this->xVelocity;
}

int Pacman::getYVelocity()
{
  return this->yVelocity;
}

void Pacman::moveUp()
{
  this->xVelocity = 0;
  this->yVelocity = -1;
}

void Pacman::moveDown()
{
  this->xVelocity = 0;
  this->yVelocity = 1;
}

void Pacman::moveLeft()
{
  this->xVelocity = -1;
  this->yVelocity = 0;
}

void Pacman::moveRight()
{
  this->xVelocity = 1;
  this->yVelocity = 0;
}

