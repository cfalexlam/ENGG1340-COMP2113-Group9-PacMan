#include <cstdlib>

#include <ncurses.h> // need to add "-lncurses" at last when compile

#include <iostream>

#include <unistd.h>

#include "player.h"

#include "maze.h"

#include "screenrenderer.h"

#include "ghost.h"

void MainGame::mainLoop() {
    /*
        Runs the main game loop.
    */

    // Set random seed
    srand(time(NULL));

    // Initialize screen renderer
    ScreenRenderer screen;

    s.printStartMenu();

    Player player(s.takeCmdInput("Please enter your name: "));

    Maze maze(s.takeCmdInput("Please enter the filename of the maze: "));
    screen.takeCmdInput("Hi " + pl.getName() + "! Are you ready? (Press any key to continue)");

    // Change keyboard mode
    screen.KeyboardModeOpen();
    screen.KeyboardModeWB();
    getch();
    screen.KeyboardModeNB();
    int fakeVelocity[2]={0,0};
    // Main game logic
    while (1) {
        maze.printmaze();

        int input;
        input = getch();
        if (input == int('q')){
            break;
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
        if (!maze.isWall(p.getPosition()[0] + fakeVelocity[0], p.getPosition()[1] + fakeVelocity[1]))   /// Check if pacman is going to hit a wall
            maze.p.setVelocity(fakeVelocity[0],fakeVelocity[1]);
        
        for (int i=0;i<maze.ghosts.size();i++)
        {
            if (collision(maze.ghosts[i],maze.p))
            {
                player.loseLife();
                if (player.getLives == 0) {
                    // Ends the game when player loses all his lives
                    screen.printLoseScreen(pl);
                    screen.KeyboardModeWB();
                    getch();
                    screen.KeyboardModeClose();
                    exit();
                }
                maze.respawn(newLevel = false); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
                screen.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
            }
        }
        if (maze.isFood(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1]))
            player.updateScore(); // increase the player's score if a dot is eaten
        
        if (player.getScore==maze.food) //win
            
        maze.movepacman();
        p.setPosition(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1]);
        

        usleep(0.2 * 1000000); // 0.2s delay
    }
    s.keyboardModeClose();
}
bool collision(Ghost ghost,Pacman p)
{
    return (ghost.getPosition()[0] + ghost.getVelocity()[0] == p.getPosition()[0] + p.getVelocity()[0] and  ghost.getPosition()[1] + ghost.getVelocity()[1] == p.getPosition()[1] + p.getVelocity()[1])
        or (ghost.getPosition()[0] + ghost.getVelocity()[0] == p.getPosition()[0] and  ghost.getPosition()[1] + ghost.getVelocity()[1] == p.getPosition()[1])
}
