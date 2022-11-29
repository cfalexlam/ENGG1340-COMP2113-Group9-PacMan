#include <cstdlib>

#include <ncurses.h> // need to add "-lncurses" at last when compile

#include <iostream>

#include <string>

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
    ScreenRenderer s;
    Player pl(playername);
    std::string fn;
    fn = s.takeCmdInput("Please enter the filename of the maze: ");
    Maze m(fn);

    screen.KeyboardModeOpen();
    screen.KeyboardModeWB();
    screen.KeyboardModePrint("Hi " + pl.getName() + "! Are you ready? (Press any key to continue)");
    getch();
    screen.KeyboardModeNB();

    int presumedVelocity[2] = {
        0,
        0
    };

    // Main game logic
    while (1) {
        m.printMaze();

        // Get user input from keyboard
        int input;
        input = getch();
        if (input == int('q')) {
            s.KeyboardModeClose();
            return false; // stop the game
        }

        // Set presumed velocities of pacman, which correspond to user input
        switch (input) {
            case KEY_UP:
                presumedVelocity[0] = -1;
                presumedVelocity[1] = 0;
                break;
            case KEY_DOWN:
                presumedVelocity[0] = 1;
                presumedVelocity[1] = 0;
                break;
            case KEY_LEFT:
                presumedVelocity[0] = 0;
                presumedVelocity[1] = -1;
                break;
            case KEY_RIGHT:
                presumedVelocity[0] = 0;
                presumedVelocity[1] = 1;
                break;
        }

        // Only update the actual velocities of pacman if the instruction is valid, i.e. the pacman is not bumping into a wall
        if (!m.isWall(pacman.getPosition()[0] + presumedVelocity[0], pacman.getPosition()[1] + presumedVelocity[1])) 
            m.pacman.setVelocity(presumedVelocity[0], presumedVelocity[1]);

        // Update velocities of ghosts if it moves towards a wall, or has a velocity of {0, 0}
        for (int i=0; i<m.ghosts.size(); i++){
            if ((m.ghosts[i][0] == 0 && m.ghosts[i][1] == 0) ||
                (m.isWall(m.ghosts[i].getPosition()[0]+m.ghosts[i].getVelocity()[0],
                          m.ghosts[i].getPosition()[1]+m.ghosts[i].getVelocity()[1]))) {
                    ghosts[i].setRandomVelocity();
                }
        }
        
        // Check if pacman is bumping into any of the ghosts
        for (int i = 0; i < m.ghosts.size(); i++) {
            if (collision(m.ghosts[i], m.pacman) and m.pacman.strong == 0) {
                pl.loseLife();
                if (pl.getLives == 0) {
                    // Ends the game when player loses all his lives
                    s.printLoseScreen(pl);
                    s.KeyboardModeWB();
                    int input;
                    s.KeyboardModePrint("Retry?(y/n)")
                    input = getch();
                    switch (input) {
                    case 'y':
                        s.KeyboardModeClose();
                        return true;
                        break;
                    case 'n':
                        s.KeyboardModeClose();
                        return false;
                        break;
                    }
                }
                m.respawnSameLevel(); // restore the starting positions of ghosts and pacman, while keeping the dots at their current places
                s.printRespawnCountdown(); // countdown for 3 seconds before restarting the game
                break;
            }
            if (collision(m.ghosts[i], m.pacman) && m.pacman.strong > 0) {
                m.respawnGhost(m.ghosts[i]);
                continue;
            }
        }

        // Update score when a food is eaten
        if (m.isFood(m.pacman.getPosition()[0] + m.pacman.getVelocity()[0], m.pacman.getPosition()[1] + m.pacman.getVelocity()[1])) 
            pl.updateScore();

        // Update score and pacman state when a power pellet is eaten
        if (m.isPellet(m.pacman.getPosition()[0] + m.pacman.getVelocity()[0], m.pacman.getPosition()[1] + m.pacman.getVelocity()[1]))
            m.pacman.strong = 20;

        // Update the position representation of Pacman and Ghost in the maze
        m.movePacman();
        m.moveGhost();

        // A player wins a level when its score == # of food (?)
        if (pl.getScore == m.food)
        {
            s.printWinScreen(pl);
            s.KeyboardModeWB();
            int input;
            s.KeyboardModePrint("Continue?(y/n)")
            input = getch();
            switch (input) {
            case 'y':
                s.KeyboardModeClose();
                maze = Maze(fn);
                return true;
                break;
            case 'n':
                s.KeyboardModeClose();
                return false;
                break;
            }
        }

        // Update position stored in the pacman object
        m.pacman.setPosition(m.pacman.getPosition()[0] + m.pacman.getVelocity()[0], m.pacman.getPosition()[1] + m.pacman.getVelocity()[1]);

        // 0.2 second of delay for each looo
        usleep(0.2 * 1000000);

        // Pacman remains in "strong" state for 4 seconds (20 loops)
        m.pacman.strong = max(0, m.pacman.strong - 1);
    }
    s.keyboardModeClose();
}
Maingame::Maingame(string playername) {
    this -> playername = playername;

}
bool collision(Ghost& ghost, Pacman& pacman) {
    return (ghost.getPosition()[0] + ghost.getVelocity()[0] == pacman.getPosition()[0] + pacman.getVelocity()[0] && ghost.getPosition()[1] + ghost.getVelocity()[1] == pacman.getPosition()[1] + pacman.getVelocity()[1]);
    //|| (ghost.getPosition()[0] + ghost.getVelocity()[0] == pacman.getPosition()[0] && ghost.getPosition()[1] + ghost.getVelocity()[1] == pacman.getPosition()[1])
}   // second expression is redundant, with extra case included (e.g. a ghost and a pacman moving in the same direction, while being adjacent to each other)