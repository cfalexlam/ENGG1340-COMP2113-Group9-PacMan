#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <tuple>
#include "ghost.h"
#include "pacman.h"
#include "pellet.h"
#include <ncurses.h>

class Pacman;
class Ghost;
class Pellet;
using namespace std;

class Maze{
    public:
        // Storing the maze structure in a 2D vector
        vector<vector <char> > maze;

        // Storing the positions of pacman, ghosts and pellets
        Pacman pacman;
        vector<Ghost> ghosts;
        vector<Pellet> pellets;

        // Load maze
        Maze(string filename);

        // Check identity of each grid
        bool isWall(int row, int col);
        bool isGhost(int row, int col);
        bool isFood(int row, int col);

        // Print the maze (can consider moving this function to the screenrenderer class)
        void printMaze();

        // Update position of pacman
        void movePacman(int* currentPosition, int* presumedPosition);
        void moveGhost();


        
        // Restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawnSameLevel();

        void respawnGhost(Ghost &ghost);

        // Update position of entities (TBC)
        void updatePos();

        // Update states of entities (TBC)
        void updateStates();
        int food=0;
    private:
        // Store number of food
        
};

#endif
