#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <tuple>
#include <ghost.h>
#include <pacman.h>
#include <pellet.h>

class Pacman;
class Ghost;

class Maze{
    public:
        Maze();
        
        Ghost inky;
        Ghost blinky;
        Ghost pinky;
        Ghost clyde;


        Pacman p;
        bool isWall(int row,int col);
        bool isGhost(int row,int col);
        bool isFood(int row,int col);
        void Maze::movePacman(int row,int col, int nrow,int ncol);
        int foodLeft();
        // load maze from templates
        Maze(string filename);

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
