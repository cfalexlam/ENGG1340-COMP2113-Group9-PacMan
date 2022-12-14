#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';
char PELLETS = 'O';


Maze::Maze(std::string filename) {
    /*
        Function: Constructer of maze. It read in text file to locate and create the ghost, pellet and player,
        and input the data into vector map.
        Input: The file save in "../map"
        Output: Output nothing
    */
    std::ifstream fin;
    fin.open(filename); 

    std::string line;
    int row, col;
    std::istringstream linein;

    getline(fin, line); // Read in pacman position
    linein.str(line);
    linein >> row >> col;

    pacman.initPosition[0] = row;
    pacman.initPosition[1] = col;
    pacman.setCurrentPosition(row, col);

    linein.clear();

    getline(fin, line); // Read in ghost positions
    for (int i = 0, j = stoi(line); i < j; i++) 
    {
        getline(fin, line);
        linein.str(line);
        linein >> row >> col;

        Ghost ghost(this,row, col);
        ghosts.push_back(ghost);

        linein.clear();
    }

    getline(fin, line); // Read in power pellet positions

    for (int i = 0, j = stoi(line); i < j; i++) 
    {
        getline(fin, line);
        linein.str(line);
        linein >> row >> col;

        Pellet pellet(row, col);// Store positions in power pellets
        pellets.push_back(pellet);

        linein.clear();
    }


    int i = 0; // Read in the map
    while (getline(fin, line)) 
    {
        std::vector <char> temp;
        maze.push_back(temp);
        for (int j = 0; j < line.size(); j++) 
        {
            if (line[j] == WALL)
                maze[i].push_back(WALL);
            else 
            {
                maze[i].push_back(FOOD);
                food += 1;
            }
        }
        i += 1;
    }

    // udate food amount by deleting the space occupied by pellet, ghost and player
    for (int i = 0; i < pellets.size(); i++) 
        maze[pellets[i].getPosition()[0]][pellets[i].getPosition()[1]] = PELLETS;
    food -= pellets.size();

    for (int i = 0; i < ghosts.size(); i++) 
        maze[ghosts[i].getCurrentPosition()[0]][ghosts[i].getCurrentPosition()[1]] = GHOST;
    food -= ghosts.size();
    
    maze[pacman.getCurrentPosition()[0]][pacman.getCurrentPosition()[1]] = PLAYER;
    food -= 1;
}

void Maze::printMaze()
{
    /*
        Function: Print the maze to screen
        Input: Do not require input, but it will use the map constructed
        Output: Ouput map to screen
    */
    for (int row = 0; row < maze.size(); row++) {
        for (int col = 0; col < maze[0].size(); col++)
            printw("%c ", maze[row][col]);
        printw("\n");
    }
}

void Maze::movePacman(int* currentPosition, int* presumedPosition)
{
    /*
        Function: Move the pacman
        Input: The current position and the presume position of pacman
        Output: Nothing will be outputted, but it will update pacman position
    */
    maze[currentPosition[0]][currentPosition[1]] = SPACE;
    maze[presumedPosition[0]][presumedPosition[1]] = PLAYER;
}

void Maze::moveGhost()
{
    /*
        Function: Move the ghost
        Input: Nothing will be inputed, but it will use the ghost object declare in constructer
        Output: Nothing will be outputted, but it will update ghost's position
    */
    for (int i=0; i<ghosts.size(); i++)
        maze[ghosts[i].getCurrentPosition()[0]][ghosts[i].getCurrentPosition()[1]] = ghosts[i].liftedObject;
    
    for (int i=0; i<ghosts.size(); i++)
    {
        int newPosX = ghosts[i].getPresumedPosition()[0];
        int newPosY = ghosts[i].getPresumedPosition()[1];
        ghosts[i].liftedObject  = maze[newPosX][newPosY];
        ghosts[i].setCurrentPosition(newPosX,newPosY);
    }

    for (int i=0; i<ghosts.size(); i++)
        maze[ghosts[i].getCurrentPosition()[0]][ghosts[i].getCurrentPosition()[1]] = GHOST;
}

void Maze::respawnGhost(Ghost &ghost)
    /*
        Function: Respawn the ghost when it is hit by player and put it back to its original position
        Input: The ghost object
        Output: Nothing will be outputted, but it will update ghost's position
    */
{
    maze[ghost.getCurrentPosition()[0]][ghost.getCurrentPosition()[1]] = ghost.liftedObject;
    ghost.liftedObject = ' ';
    maze[ghost.initPosition[0]][ghost.initPosition[1]] = GHOST;
    ghost.setCurrentPosition(ghost.initPosition[0], ghost.initPosition[1]);
    ghost.setCurrentVelocity(0,0);
}

void Maze::respawnSameLevel()
{
    /*
        Function: Respawn the player when it is hit by ghost and put it back to its original position
        Input: Nothing, but it will use the pacman object declare in constructer
        Output: Nothing will be outputted, but it will update ghost's position
    */
    movePacman(pacman.getCurrentPosition(),pacman.initPosition);
    pacman.setCurrentPosition(pacman.initPosition[0], pacman.initPosition[1]);
    pacman.setCurrentVelocity(0, 0);
    pacman.setPresumedVelocity(0, 0);

    for (int i=0; i<ghosts.size(); i++)
        maze[ghosts[i].getCurrentPosition()[0]][ghosts[i].getCurrentPosition()[1]] = ghosts[i].liftedObject;

    for (int i=0; i<ghosts.size(); i++)
    {
        ghosts[i].liftedObject = ' ';
        ghosts[i].setCurrentPosition(ghosts[i].initPosition[0],ghosts[i].initPosition[1]);
    }
    for (int i=0; i<ghosts.size(); i++)
        maze[ghosts[i].initPosition[0]][ghosts[i].initPosition[1]] = GHOST;
}

bool Maze::isWall(int row, int col) 
{
    /*
        Function: Check whether the location is a wall
        Input: The row and col of the map
        Output: Return ture if the location is a wall, vice versa
    */
    return maze[row][col] == WALL;
}

bool Maze::isGhost(int row, int col) 
{
    /*
        Function: Check whether the location is a ghost
        Input: The row and col of the map
        Output: Return ture if the location is a ghost, vice versa
    */
    return maze[row][col] == GHOST;
}

bool Maze::isFood(int row, int col) 
{
    /*
        Function: Check whether the location is a food
        Input: The row and col of the map
        Output: Return ture if the location is a food, vice versa
    */
    return maze[row][col] == FOOD;
}
