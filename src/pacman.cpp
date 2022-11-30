#include "pacman.h"

void Pacman::setCurrentPosition(int row, int col)
{
  this->currentPosition[0] = row;
  this->currentPosition[1] = col;
}

void Pacman::setCurrentVelocity(int row, int col){
  this->currentVelocity[0] = row;
  this->currentVelocity[1] = col;
}

void Pacman::setPresumedVelocity(int row, int col){
  this->presumedVelocity[0] = row;
  this->presumedVelocity[1] = col;
}

int* Pacman::getPresumedPosition(){
	static int temp[2] = {0,0};
	temp[0] = this->currentPosition[0] + this->currentVelocity[0];
	temp[1] = this->currentPosition[1] + this->currentVelocity[1];
	return temp;
}

int* Pacman::getCurrentVelocity()
{
  return this->currentVelocity;
}

int* Pacman::getCurrentPosition()
{
  return this->currentPosition;
}

int* Pacman::getPresumedVelocity(){
	return this->presumedVelocity;
}



