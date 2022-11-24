#ifndef MAZE
#define MAZE

#include <vector>
#include <string>
#include <tuple>
#include <ghost.h>
#include <pacman.h>

class Pacman;
class Ghost;

class Maze{
    public:
        Maze();
        
        // load maze from templates
        int loadMaze(std::string filename);

        // intialize a vector that stores the coordinates of dots
        int initDotsVector();

        // remove dots from maze and dots when eaten
        int removeDots(int x, int y);

        // restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawn(bool newLevel);

        // update position of entities
        void updatePos();

        // update states of entities
        void updateStates();

    private:
        Ghost clyde = new Ghost(1, 37); 
        Ghost inky = new Ghost(3, 37); 
        Ghost blinky = new Ghost(5, 37); 
        Ghost pinky = new Ghost(7, 37); 

        Pacman pacman = new Pacman(1, 1);

        const int ROWNUMBER = 9;
        const int COLNUMBER = 51;

        std::vector<vector<int>> maze;  // store positions of walls, dots and power pellets
        std::vector<tuple<int, int>> dots;  // store coordinates of dots
        std::vector<tuple<int, int>> powerpellets;  // store coordinates of power pellets
};

#endif