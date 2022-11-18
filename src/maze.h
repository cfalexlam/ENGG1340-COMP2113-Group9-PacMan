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
        bool isWall(int row,int col);
        bool isGhost(int row,int col);
        bool isFood(int row,int col);
        void Maze::movePacman(int row,int col, int nrow,int ncol);
        int foodLeft();
        // load maze from templates
        Maze(string filename);

        // restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
        void respawn();

        // update position of entities
        void updatePos();

        // update states of entities
        void updateStates();
    private:
        int food=0;
};

#endif
