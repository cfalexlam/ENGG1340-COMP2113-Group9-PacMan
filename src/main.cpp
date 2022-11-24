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
    ScreenRenderer s;

    s.printStartMenu();

    Player pl(s.takeCmdInput("Please enter your name: "));

    Maze m(s.takeCmdInput("Please enter the filename of the maze: "));
    s.takeCmdInput("Hi " + p.getName() + "! Are you ready? (Press any key to continue)");

    // Change keyboard mode
    s.KeyboardModeOpen();
    s.KeyboardModeWB();
    getch();
    s.KeyboardModeNB();

    // Main game logic
    while (1) {
        m.printmaze();

        int input;
        input = getch();
        if (input == int('q')){
            break;
        }

        switch (input) {
            case KEY_UP:
                p.setVelocity(-1, 0);
                break;
            case KEY_DOWN:
                p.setVelocity(1, 0);
                break;
            case KEY_LEFT:
                p.setVelocity(0, -1);
                break;
            case KEY_RIGHT:
                p.setVelocity(0, 1);
                break;
        }

        /// Check if pacman is hitting a wall
        if (!m.isWall(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1])) {
            // Check collisions of ghosts and pacman
            if (m.isGhost(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1])) {
                pl.loseLife();
                if (pl.getLives == 0) {
                    // Ends the game when player loses all his lives
                    s.printLoseScreen(pl.getScore());
                    s.KeyboardModeWb();
                    getch();
                    s.KeyboardModeClose();
                    exit();
                }
                m.respawn(newLevel = false); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
                s.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
            } else {
                // Check if pacman eats a dot
                if (m.isFood(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1])) {
                    pl.updateScore(); // increase the player's score if a dot is eaten
                }
                m.movepacman();
                p.setPosition(p.getPosition()[0] + p.getVelocity()[0], p.getPosition()[1] + p.getVelocity()[1]);
            }
        }

        m.updatePos(); // update the positions of dots, ghosts and pacman on the maze
        m.updateStates(); // update the states of ghosts and pacman on the maze

        if (!m.getDotsPos()) {
            pl.updateCurrentLevel();
            m.respawn(true);
            s.printRespawnCountdown();
        }

        usleep(0.2 * 1000000); // 0.2s delay
    }
    s.keyboardModeClose();
}