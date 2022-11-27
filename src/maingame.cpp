#include <cstdlib>
#include <ncurses.h> // need to add "-lncurses" at last when compile
#include <iostream>

#include <unistd.h>
#include "player.h"
#include "maze.h"
#include "screenrenderer.h"
#include "ghost.h"

bool MainGame::mainLoop() {
    /*
        Runs the main game loop.
    */

    // Set random seed
    srand(time(NULL));

    // Initialize screen renderer
    ScreenRenderer screen;
    Player player(playername);
    Maze maze(s.takeCmdInput("Please enter the filename of the maze: "));

    screen.KeyboardModeOpen();
    screen.KeyboardModeWB();
    screen.KeyboardModePrint("Hi " + pl.getName() + "! Are you ready? (Press any key to continue)");
    getch();
    screen.KeyboardModeNB();
    
    int fakeVelocity[2]={0,0};
    // Main game logic
    while (1) {
        maze.printmaze();

        int input;
        input = getch();
        if (input == int('q')){
            screen.KeyboardModeClose();
            return false;   //stop game
        }

        switch (input) {
            case KEY_UP:
                fakeVelocity[0]=-1;
                fakeVelocity[1]=0;
                break;
            case KEY_DOWN:
                fakeVelocity[0]=1;
                fakeVelocity[1]=0;
                break;
            case KEY_LEFT:
                fakeVelocity[0]=0;
                fakeVelocity[1]=-1;
                break;
            case KEY_RIGHT:
                fakeVelocity[0]=0;
                fakeVelocity[1]=1;
                break;
        }
        
        if (! maze.isWall(p.getPosition()[0] + fakeVelocity[0] , p.getPosition()[1] + fakeVelocity[1]) )   /// Check if pacman is going to hit a wall
            maze.p.setVelocity(fakeVelocity[0] , fakeVelocity[1]);
        
        for (int i = 0 ; i < maze.ghosts.size() ; i++)
        {
            if ( collision( maze.ghosts[i] , maze.p ) and p.strong == 0 )
            {
                player.loseLife();
                if ( player.getLives == 0 ) {
                    // Ends the game when player loses all his lives
                    screen.printLoseScreen(pl);
                    screen.KeyboardModeWB();
                    int input;
                    screen.KeyboardModePrint("Retry?(y/n)")
                    input = getch();
                    switch (input){
                        case 'y':
                            screen.KeyboardModeClose();
                            return true;
                            break;
                        case 'n':
                            screen.KeyboardModeClose();
                            return false;
                            break;   
                    }  
                }
                maze.respawn(newLevel = false); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
                screen.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
                break;
            }
            if ( collision( maze.ghosts[i] , maze.p ) and p.strong > 0 )
            {
                maze.ghosts[i].respawn();
                continue;
            }
            maze.moveghost();
            maze.ghost.setPosition(maze.ghost.getPosition()[0] + maze.ghost.getVelocity()[0], maze.ghost.getPosition()[1] + maze.ghost.getVelocity()[1]);
        }
        
        if (maze.isFood(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1])) //if a food is eaten
            player.updateScore();
        
         if (maze.isPellet(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1])) //if a pellet is eaten
             p.strong = 20;
        if (player.getScore == maze.food) //win
        {
            screen.printWinScreen(pl);
                    screen.KeyboardModeWB();
                    int input;
                    screen.KeyboardModePrint("Continue?(y/n)")
                    input = getch();
                    switch (input){
                        case 'y':
                            screen.KeyboardModeClose();
                            return true;
                            break;
                        case 'n':
                            screen.KeyboardModeClose();
                            return false;
                            break;   
                    }  
        }
            
        maze.movepacman();
        p.setPosition(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1]);
        

        usleep(0.2 * 1000000); // 0.2s delay
        p.strong = max(0,p.strong-1);
    }
    s.keyboardModeClose();
}
Maingame::Maingame(string playername)
{
    this->playername = playername;
    
}
bool collision(Ghost ghost,Pacman p)
{
    return (ghost.getPosition()[0] + ghost.getVelocity()[0] == p.getPosition()[0] + p.getVelocity()[0] and  ghost.getPosition()[1] + ghost.getVelocity()[1] == p.getPosition()[1] + p.getVelocity()[1])
        or (ghost.getPosition()[0] + ghost.getVelocity()[0] == p.getPosition()[0] and  ghost.getPosition()[1] + ghost.getVelocity()[1] == p.getPosition()[1])
}
