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


class Maze{
    public:
        
        Ghost inky;
        Ghost blinky;
        Ghost pinky;
        Ghost clyde;
        std::vector <std::vector <char>> themaze;

        Pacman pacman;
        bool isWall(std::vector <std::vector <char>> maze, int row,int col);
        bool isGhost(std::vector <std::vector <char>> maze, int row,int col);
        bool isFood(std::vector <std::vector <char>> maze, int row,int col);
        void movePacman(std::vector <std::vector <char>> maze, int row,int col, int nrow,int ncol);
        void printMaze();
        int foodLeft();
        // load maze from templates
        void maze(std::string filename);

        // restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawn(bool newLevel);

        // update position of entities
        void updatePos();

        // update states of entities
        void updateStates();
    private:
        int food=0;
};

#endif
