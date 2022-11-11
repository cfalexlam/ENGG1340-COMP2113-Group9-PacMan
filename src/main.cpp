#include <cstdlib>
#include <conio.h>
#include <iostream>

#include "player.h"
#include "maze.h"
#include "screenrenderer.h"
#include "ghosts.h"
#include "dots.h"
#include "player.h"

void MainGame::mainLoop(){
    /*
        Runs the main game loop.
    */
    
    // Set random seed
    srand(time(NULL));

    ScreenRenderer s;

    s.printStartMenu();

    Player pl(s.takeCmdInput("Please enter your name: "));

    Maze m(s.takeCmdInput("Please enter the filename of the maze: "));

    s.takeCmdInput("Hi " + p.getName() + "! Are you ready? (Press any key to continue)");

    do{
        char input;
        input = s.takeKeyboardInput();

        // check collisions of ghosts and pacman before updating the screen
        if (isLosing(m)){

            pl.loseLife();

            if (pl.getLives == 0){
                s.printLoseScreen(pl.getScore());
                if (s.takeKeyboardInput()){
                    exit();
                }
            }

            m.respawn(newLevel=false); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
            s.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
        }

        m.updatePos(); // update the positions of dots, ghosts and pacman on the maze
        m.updateStates(); // update the states of ghosts and pacman on the maze
        pl.updateScore();  // increase the player's score if a dot is eaten

        if (!m.getDotsPos()){
            pl.updateCurrentLevel();
            m.respawn(newLevel=true);
            s.printRespawnCountdown();
        }

        s.updateScreen();  // print new maze to screen
    }
    while (input != "q" || input != "Q")

}


// Check if lose state is reached with the planned move, proceed otherwise
bool MainGame::isLosing(Maze m){
    /* Check if there are any collisions in the position of ghosts and pacman with the keyboard input*/

}