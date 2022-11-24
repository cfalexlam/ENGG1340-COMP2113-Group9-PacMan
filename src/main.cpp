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
                m.p.moveup(); // Alex: check losing before making the move? also have to reject invalid moves (collision with walls)
                break;
            case KEY_DOWN;
                m.p.movedown();
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
        if (isLosing(m, input)){

            pl.loseLife();

            if (pl.getLives == 0){
                s.printLoseScreen(pl.getScore());
				s.KeyboardModeWb();
				getch();
				s.KeyboardModeClose();
                exit();
            }

            m.respawn(false); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
            s.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
        }

        if (eatingPowerPellet()){
            m.updateStates();
        }

        m.updatePos(); // update the positions of dots, ghosts and pacman on the maze
        pl.updateScore();  // increase the player's score if a dot is eaten

        if (!m.getDotsPos()){
            pl.updateCurrentLevel();
            m.respawn(true);
            s.printRespawnCountdown();
        }

        s.updateScreen();  // print new maze to screen
    }


}


// Check if lose state is reached with the planned move, proceed otherwise
bool MainGame::isLosing(Maze m, int input){
    /* Check if there are any collisions in the position of ghosts and pacman with the keyboard input*/
    int newPacmanPosX = m.p.currentX;
    int newPacmanPosY = m.p.currentY;
    
    if (input == KEY_UP){
        newPacmanPosY -= 1;
    }
    else if (input == KEY_DOWN){
        newPacmanPosY += 1;
    }
    else if (input == KEY_LEFT){
        newPacmanPosX -= 1;
    }
    else if (input == KEY_RIGHT){
        newPacmanPosX += 1;
    }

    if (m.p.currentX == m.&& m.p.currentY == ){

    }
}
