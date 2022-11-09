#ifndef MAIN_GAME
#define MAIN_GAME

#include "maze.h"

class Maze;

// Perform all main game-related functions
class MainGame{
    public:
        // Run the main game loop
        void mainLoop();

        // Check if lose state is reached with the planned move, proceed otherwise
        bool isLosing(Maze m);
};

#endif