#include <pacman.h>



int pacman::getXVelocity()
{
  return this->xVelocity;
}

int pacman::getYVelocity()
{
  return this->yVelocity;
}

void pacman::moveup()
{
  this->xVelocity = 0;
  this->yVelocity = -1;
}

void pacman::movedown()
{
  this->xVelocity = 0;
  this->yVelocity = 1;
}

void pacman::moveleft()
{
  this->xVelocity = -1;
  this->yVelocity = 0;
}

void pacman::moveright()
{
  this->xVelocity = 1;
  this->yVelocity = 0;
}

