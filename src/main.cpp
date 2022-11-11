#include <cstdlib>
#include <ncurses.h> // need to add "-lncurses" at last when compile
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
    
    s.KeyboardModeOpen();
	s.KeyboardModeWb();
    getch();
	s.KeyboardModeNb();
	
    while(1){
        m.printmaze();
        int input;
        input = getch();
        switch(input)
        {
            case KEY_UP:
                m.p.moveup();
                break;
            case KEY_DOWN;
                m.p.movedown;
                break;
            case KEY_LEFT;
                m.p.moveleft();
                break;
            case KEY_RIGHT;
                m.p.moveright();
                break;
            case int('q');
        }
		
        // check collisions of ghosts and pacman before updating the screen
        if (isLosing(m)){
            pl.loseLife();
            if (pl.getLives == 0){
                s.printLoseScreen(pl.getScore());
				s.KeyboardModeWb();
				getch();
				s.KeyboardModeClose();
                exit();
            }
            m.respawn(); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
            s.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
        }

        m.updatePos(); // update the positions of dots, ghosts and pacman
        m.updateStates(); // update the states of ghosts and pacman
        pl.updatePlayerScore();  // increase the player's score if a dot is eaten
        clear();
    }


}


// Check if lose state is reached with the planned move, proceed otherwise
bool MainGame::isLosing(Maze m){
    /* Check if there are any collisions in the position of ghosts and pacman with the keyboard input*/

}
