#include "ghost.h"
#include "maze.h"
#include <random>
#include <vector>

Ghost::Ghost(Maze *m, int row, int col){
  // Initialize member properties
  this->m = m;
  this->initPosition[0] = row;
  this->initPosition[1] = col;
  this->currentPosition[0] = row;
  this->currentPosition[1] = col;
}

void Ghost::setPosition(int row, int col)
{
  this->currentPosition[0] = row;
  this->currentPosition[1] = col;
}

void Ghost::setVelocity(int row, int col){
  this->currentVelocity[0] = row;
  this->currentVelocity[1] = col;
}

int* Ghost::getVelocity()
{
  return this->currentVelocity;
}

int* Ghost::getPosition()
{
  return this->currentPosition;
}

void Ghost::setRandomVelocity(){
  /* Generate random directions of movement */
  std::vector<int> validDirections;
  int numberOfValidDirections = 0;
  if (!m->isWall(currentPosition[0]+1, currentPosition[1])){
    validDirections.push_back(0);
  }
  if (!m->isWall(currentPosition[0]-1, currentPosition[1])){
    validDirections.push_back(1);
  }
  if (!m->isWall(currentPosition[0], currentPosition[1]+1)){
    validDirections.push_back(2);
  }
  if (!m->isWall(currentPosition[0], currentPosition[1]-1)){
    validDirections.push_back(3);
  }

  int randomDirection = validDirections[rand() % validDirections.size()];
  
  switch (randomDirection){
    case 0:
      currentVelocity[0] = 1;
      currentVelocity[1] = 0;
      break;
    case 1:
      currentVelocity[0] = -1;
      currentVelocity[1] = 0;
      break;
    case 2:
      currentVelocity[0] = 0;
      currentVelocity[1] = 1;
      break;
    case 3:
      currentVelocity[0] = 0;
      currentVelocity[1] = -1;
      break;
  }
}
void Ghost::respawn(){
  currentPosition[0] = initPosition[0];
  currentPosition[1] = initPosition[1];
}



