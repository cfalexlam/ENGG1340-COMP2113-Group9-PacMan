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


class Maze{
    public:
        // Storing the maze structure in a 2D vector
        std::vector<std::vector <char>> maze;

        // Storing the positions of pacman, ghosts and pellets
        Pacman pacman;
        std::vector<Ghost> ghosts;
        std::vector<Pellet> pellets;

        // Class constructor to load maze from templates
        // https://softwareengineering.stackexchange.com/questions/388977/how-to-reach-the-parent-object
        Maze(std::string filename): Ghost(*this);

        // Check identity of each grid
        bool isWall(int row, int col);
        bool isGhost(int row, int col);
        bool isFood(int row, int col);

        // Print the maze (can consider moving this function to the screenrenderer class)
        void printMaze();

        // Update position of pacman
        void movePacman(int row,int col, int nrow,int ncol);
        void moveGhost();

        // Return the number of remaining food
        int foodLeft();
        
        // Restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawn(bool newLevel);

        // Update position of entities (TBC)
        void updatePos();

        // Update states of entities (TBC)
        void updateStates();

    private:
        // Store number of food
        int food = 0;
};

#endif
