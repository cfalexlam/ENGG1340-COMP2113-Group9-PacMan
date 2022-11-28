#include "ghost.h"
#include "maze.h"
#include <random>
#include <vector>

Maze m;

Ghost::Ghost(){
  std::vector<int> validDirections;
  int numberOfValidDirections = 0;
  if (!m.isWall(position[0]+1, position[1])){
    validDirections.push_back(0);
  }
  if (!m.isWall(position[0]-1, position[1])){
    validDirections.push_back(1);
  }
  if (!m.isWall(position[0], position[1]+1)){
    validDirections.push_back(2);
  }
  if (!m.isWall(position[0], position[1]-1)){
    validDirections.push_back(3);
  }

  int randomDirection = validDirections[rand() % validDirections.size()];
  
  switch (randomDirection){
    case 0:
      velocity[0] = 1;
      velocity[1] = 0;
      break;
    case 1:
      velocity[0] = -1;
      velocity[1] = 0;
      break;
    case 2:
      velocity[0] = 0;
      velocity[1] = 1;
      break;
    case 3:
      velocity[0] = 0;
      velocity[1] = -1;
      break;
  }
}

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



