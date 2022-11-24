#include <Ghost.h>

Ghost::Ghost(int initX, int initY, int xVelocity, int yVelocity){
    initX = initX;
    initY = initY;
    xVelocity = xVelocity;
    yVelocity = yVelocity;
}

int Ghost::getXVelocity()
{
  return this->xVelocity;
}

int Ghost::getYVelocity()
{
  return this->yVelocity;
}

void Ghost::moveUp()
{
  this->xVelocity = 0;
  this->yVelocity = -1;
}

void Ghost::moveDown()
{
  this->xVelocity = 0;
  this->yVelocity = 1;
}

void Ghost::moveLeft()
{
  this->xVelocity = -1;
  this->yVelocity = 0;
}

void Ghost::moveRight()
{
  this->xVelocity = 1;
  this->yVelocity = 0;
}

