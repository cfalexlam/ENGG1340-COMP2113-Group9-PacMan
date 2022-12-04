#include "ghost.h"
#include "maze.h"
#include <random>
#include <vector>

Ghost::Ghost(Maze *m, int row, int col)
{
    /*
        Function: Construct a ghost object.
        Input: A pointer to the maze object, and two integers, each indicating the initial row and col positions.
        Output: None
    */
    this->m = m;
    this->initPosition[0] = row;
    this->initPosition[1] = col;
    this->currentPosition[0] = row;
    this->currentPosition[1] = col;
}

void Ghost::setRandomVelocity()
{
    /*
        Function: Generates random direction of movement, depending on the current velocity.
                  This function also updates the current velocity of the ghost.
        Input: None
        Output: None
    */
    std::vector<int> validDirections;
    int numberOfValidDirections = 0;

    if (currentVelocity[0] == 0 && currentVelocity[1] == 0){    // When the ghost is stationary
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
        if (currentVelocity[0]==0) // If current movement if horizontal
        {
            if (m->isWall(getPresumedPosition()[0], getPresumedPosition()[1]))
            {
                if (currentVelocity[1]==1)          // Moving right
                    validDirections.push_back(3);   // Allow move left            
                if (currentVelocity[1]==-1)         // Moving left
                    validDirections.push_back(2);   // Allow move right
            }
            else
            {
                if (currentVelocity[1]==1)          // Moving right
                    validDirections.push_back(2);   // Allow move right              
                if (currentVelocity[1]==-1)         // Moving left
                    validDirections.push_back(3);   // Allow move left
            }

            if (!m->isWall(currentPosition[0]-1, currentPosition[1]))
                validDirections.push_back(1);
            if (!m->isWall(currentPosition[0]+1, currentPosition[1]))
                validDirections.push_back(0);
        }

        if (currentVelocity[1]==0) // if current movement is vertical
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
    
    // Picks a direction from the vector of validDirections
    int randomDirection = validDirections[rand() % validDirections.size()];

    switch (randomDirection)
    {
        case 0: // Down
            currentVelocity[0] = 1;
            currentVelocity[1] = 0;
            break;
        case 1: // Up
            currentVelocity[0] = -1;
            currentVelocity[1] = 0;
            break;
        case 2: // Right
            currentVelocity[0] = 0;
            currentVelocity[1] = 1;
            break;
        case 3: // Left
            currentVelocity[0] = 0;
            currentVelocity[1] = -1;
            break;
    }
}


void Ghost::setCurrentPosition(int row, int col)
    /*
        Function: Set the current position of the ghost.
        Input: Two integers, each corresponding to the row number and the column number.
        Output: None
    */
{
    this->currentPosition[0] = row;
    this->currentPosition[1] = col;
}

void Ghost::setCurrentVelocity(int row, int col)
    /*
        Function: Set the current velocity of the ghost.
        Input: Two integers, each corresponding to the row number and the column number.
        Output: None
    */
{
    this->currentVelocity[0] = row;
    this->currentVelocity[1] = col;
}

int* Ghost::getCurrentVelocity()
    /*
        Function: Get the current velocity of the ghost.
        Input: None
        Output: An integer pointer pointing to the current velocity array.
    */
{
    return this->currentVelocity;
}

int* Ghost::getCurrentPosition()
    /*
        Function: Get the current position of the ghost.
        Input: None
        Output: An integer pointer pointing to the current position array.
    */
{
    return this->currentPosition;
}

int* Ghost::getPresumedPosition()
    /*
        Function: Calculate and return the presumed position of the ghost.
        Input: None
        Output: An integer pointer pointing to the presumed position array.
    */
{
    this->presumedPosition[0] = this->currentPosition[0] + this->currentVelocity[0];
    this->presumedPosition[1] = this->currentPosition[1] + this->currentVelocity[1];
    return this->presumedPosition;
}





