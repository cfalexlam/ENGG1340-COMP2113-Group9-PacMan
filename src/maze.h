#ifndef MAZE
#define MAZE

#include <vector>
#include <string>

class Pacman;
class Ghost;

class Maze{
    public:
        vector<vector<int>> maze;  // store state of maze
        vector<vector<int>> dots;  // store coordinates of dots
        vector<vector<int>> powerpellets;  // store coordinates of power pellets
        
        Ghost inky;
        Ghost blinky;
        Ghost pinky;
        Ghost clyde;

        Pacman p;

        // load maze from templates
        void loadMaze(str filename);

        // restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawn();

        // update position of entities
        void updatePos();

        // update states of entities
        void updateStates();
};

#endif