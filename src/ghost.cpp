#include "ghost.h"
#include "maze.h"
#include <random>
#include <vector>

Ghost::Ghost(Maze *m, int row, int col)
{
// Initialize member properties
    this->m = m;
    this->initPosition[0] = row;
    this->initPosition[1] = col;
    this->currentPosition[0] = row;
    this->currentPosition[1] = col;
}

void Ghost::setRandomVelocity()
{
    /* Generate random directions of movement */
    std::vector<int> validDirections;
    int numberOfValidDirections = 0;

    if (currentVelocity[0] == 0 && currentVelocity[1] == 0){
        if (!m->isWall(currentPosition[0]+1, currentPosition[1]))
            validDirections.push_back(0);
        if (!m->isWall(currentPosition[0]-1, currentPosition[1]))
            validDirections.push_back(1);
        if (!m->isWall(currentPosition[0], currentPosition[1]+1))
            validDirections.push_back(2);
        if (!m->isWall(currentPosition[0], currentPosition[1]-1))
            validDirections.push_back(3);
    }
    else
    {
        if (currentVelocity[0]==0) //<> movement
        {
            if (m->isWall(getPresumedPosition()[0], getPresumedPosition()[1]))
            {
                if (currentVelocity[1]==1)          //moving right
                    validDirections.push_back(3);   //allow move left            
                if (currentVelocity[1]==-1)         //moving left
                    validDirections.push_back(2);   //allow move right
            }
            else
            {
                if (currentVelocity[1]==1)          //moving right
                    validDirections.push_back(2);   //allow move right              
                if (currentVelocity[1]==-1)         //moving left
                    validDirections.push_back(3);   //allow move left
            }

            if (!m->isWall(currentPosition[0]-1, currentPosition[1]))
                validDirections.push_back(1);
            if (!m->isWall(currentPosition[0]+1, currentPosition[1]))
                validDirections.push_back(0);
        }

        if (currentVelocity[1]==0) // If currently moving up or down
        {
            if (m->isWall(getPresumedPosition()[0], getPresumedPosition()[1])) // If pacman is hitting a wall
            {
                if (currentVelocity[0]==1)   //  Moving Down
                    validDirections.push_back(1);   // Allows moving up                   
                if (currentVelocity[0]==-1)  //  Moving Up
                    validDirections.push_back(0);  // Allows moving down
            }
            else
            {
                if (currentVelocity[0]==1)  // Moving Down
                    validDirections.push_back(0);   // Keep original moving direction: moving down                 
                if (currentVelocity[0]==-1) // Moving Up
                    validDirections.push_back(1);  // Keep original direction: moving up
            }

            if (!m->isWall(currentPosition[0], currentPosition[1]-1))
                validDirections.push_back(3);
            if (!m->isWall(currentPosition[0], currentPosition[1]+1))
                validDirections.push_back(2);
        }

    
    }
    

    int randomDirection = validDirections[rand() % validDirections.size()];

    switch (randomDirection)
    {
        case 0: //down
            currentVelocity[0] = 1;
            currentVelocity[1] = 0;
            break;
        case 1: //up
            currentVelocity[0] = -1;
            currentVelocity[1] = 0;
            break;
        case 2: //right
            currentVelocity[0] = 0;
            currentVelocity[1] = 1;
            break;
        case 3: //left
            currentVelocity[0] = 0;
            currentVelocity[1] = -1;
            break;
    }
}

void Ghost::setCurrentPosition(int row, int col)
{
    this->currentPosition[0] = row;
    this->currentPosition[1] = col;
}

void Ghost::setCurrentVelocity(int row, int col)
{
    this->currentVelocity[0] = row;
    this->currentVelocity[1] = col;
}

int* Ghost::getCurrentVelocity()
{
    return this->currentVelocity;
}

int* Ghost::getCurrentPosition()
{
    return this->currentPosition;
}

int* Ghost::getPresumedPosition()
{
    this->presumedPosition[0] = this->currentPosition[0] + this->currentVelocity[0];
    this->presumedPosition[1] = this->currentPosition[1] + this->currentVelocity[1];
    return this->presumedPosition;
}





