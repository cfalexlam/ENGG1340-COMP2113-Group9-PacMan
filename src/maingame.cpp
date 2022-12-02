#include <cstdlib>

#include <ncurses.h> // need to add "-lncurses" at last when compile

#include <iostream>

#include <string>

#include <unistd.h>

#include "player.h"

#include "maze.h"

#include "screenrenderer.h"

#include "ghost.h"

#include "maingame.h"
using namespace std;

const int DELAYSECONDS = 0.2;

bool collision(Ghost& ghost, Pacman& pacman);

MainGame::MainGame(string playername, string filename){
    this->playername = playername;
    this->filename = filename;
}

bool MainGame::mainLoop() {
    /*
        Runs the main game loop.
    */

    // Set random seed
    srand(time(NULL));

    // Initialize screen renderer
    ScreenRenderer screen;
    Player player(playername);
    
    Maze maze("../map/"+filename);
    
    screen.keyboardModeOpen();
    screen.keyboardModeWB();
    screen.keyboardModePrint("Hi " + player.getName() + "! Are you ready? (Press any key to continue)");
    getch();
    screen.keyboardModeNB();

    int input;
    // Main game logic
    while (1) {
        clear();
        printw("Score: %d\n",player.getScore());
        printw("Lives: %d\n",player.getLives());
        printw("Strong: %d\n",maze.pacman.strong);
        maze.printMaze();
        // Get user input from keyboard
        input = getch();
        if (input == int('q')) 
        {
            screen.keyboardModeClose();
            return false; // stop the game
        }

        // Set presumed velocities of pacman, which correspond to user input
        switch (input) 
        {
            case KEY_UP:
            	maze.pacman.setPresumedVelocity(-1,0);
                break;
            case KEY_DOWN:
                maze.pacman.setPresumedVelocity(1,0);
                break;
            case KEY_LEFT:
                maze.pacman.setPresumedVelocity(0,-1);
                break;
            case KEY_RIGHT:
                maze.pacman.setPresumedVelocity(0,1);
                break;
        }
        
        // Only update the actual velocities of pacman if the instruction is valid, i.e. the pacman is not bumping into a wall
        if (! maze.isWall(maze.pacman.getCurrentPosition()[0] + maze.pacman.getPresumedVelocity()[0], maze.pacman.getCurrentPosition()[1]+maze.pacman.getPresumedVelocity()[1])) 
        {
            maze.pacman.setCurrentVelocity(maze.pacman.getPresumedVelocity()[0] , maze.pacman.getPresumedVelocity()[1]);
        }
        if (maze.isWall(maze.pacman.getPresumedPosition()[0], maze.pacman.getPresumedPosition()[1])) 
        {
            maze.pacman.setCurrentVelocity(0,0);
        }
        // Update velocities of ghosts if it moves towards a wall, or has a velocity of {0, 0}

        for (int i=0; i<maze.ghosts.size(); i++){

            if ((maze.ghosts[i].getCurrentVelocity()[0] == 0 && maze.ghosts[i].getCurrentVelocity()[1] == 0) ||
                (maze.isWall(maze.ghosts[i].getPresumedPosition()[0],maze.ghosts[i].getPresumedPosition()[1]))) {
                    maze.ghosts[i].setRandomVelocity();    
                }
        }

        // Check if pacman is bumping into any of the ghosts
        for (int i = 0; i < maze.ghosts.size(); i++) {
            if (collision(maze.ghosts[i], maze.pacman) and maze.pacman.strong == 0) 
            {
                player.loseLife();
                if (player.getLives() == 0) 
                {
                    // Ends the game when player loses all his lives
                    screen.printLoseScreen(player);
                    screen.keyboardModeWB();
                    int input;
                    screen.keyboardModePrint("Retry?(y/n)");
                    do{
                        input = getch();
                        switch (input) {
                            case 'y': case 'Y':
                                screen.keyboardModeClose();
                                return true;
                                break;
                            case 'n': case 'N':
                                screen.keyboardModeClose();
                                return false;
                                break;
                        }

                    }while (true);
                }
                maze.respawnSameLevel(); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
                goto DELAY;
            }
            if (collision(maze.ghosts[i], maze.pacman) and maze.pacman.strong > 0)
                maze.respawnGhost(maze.ghosts[i]);

        }

        // Update score when a food is eaten
        if (maze.isFood(maze.pacman.getPresumedPosition()[0],maze.pacman.getPresumedPosition()[1])) 
            player.addScore(1);

        // Update score and pacman state when a power pellet is eaten
        for (int i=0;i<maze.pellets.size();i++)
        	if (maze.pellets[i].getPosition()[0] == maze.pacman.getPresumedPosition()[0] &&
        	    maze.pellets[i].getPosition()[1] == maze.pacman.getPresumedPosition()[1])
             		maze.pacman.strong = 50;

        // Update the position representation of Pacman and Ghost in the maze
        maze.movePacman(maze.pacman.getCurrentPosition(),maze.pacman.getPresumedPosition());
        maze.moveGhost();
        // Update position stored in the pacman object
        maze.pacman.setCurrentPosition(maze.pacman.getPresumedPosition()[0],maze.pacman.getPresumedPosition()[1]);

        // A player wins a level when its score == # of food (?)
        if (player.getScore() == maze.food)
        {
            screen.printWinScreen(player);
            screen.keyboardModeWB();
            int input;
            screen.keyboardModePrint("Continue?(y/n)");
            do{
                input = getch();
                switch (input) {
                    case 'y': case 'Y':
                        screen.keyboardModeClose();
                        return true;
                        break;
                    case 'n': case 'N':
                        screen.keyboardModeClose();
                        return false;
                        break;
                }

            }while (true);
        }

        // 0.2 second of delay for each looo
        DELAY:usleep(DELAYSECONDS * 1000000);

        // Pacman remains in "strong" state for 4 seconds (20 loops)
        maze.pacman.strong = max(0, maze.pacman.strong - 1);
    }
    screen.keyboardModeClose();
    return false;

}
bool collision(Ghost& ghost, Pacman& pacman) {
    return ( (ghost.getPresumedPosition()[0] == pacman.getPresumedPosition()[0] && ghost.getPresumedPosition()[1] == pacman.getPresumedPosition()[1])
    	     || ( (ghost.getPresumedPosition()[0] == pacman.getCurrentPosition()[0] && ghost.getPresumedPosition()[1] == pacman.getCurrentPosition()[1])
    	   	     && ( (pacman.getPresumedPosition()[0] == ghost.getCurrentPosition()[0] && pacman.getPresumedPosition()[1] == ghost.getCurrentPosition()[1])
    	   	     )));
    
}   
