# ENGG1340-COMP2113-Group9-PacMan
Group project for ENGG1340/COMP2113 

## Team members (Group 9)
* Guo Tsz Wang
* Lam Cheuk Fung Alex
* Mak Wan Sing
* Tse Yun Lam

## About the game

Pacman, originally called Puck Man in Japan, is a legendary and classic maze action video game which was developed and released in the 1980s. To score, a player controls the "Pacman" to move inside an enclosed maze filled up with dots and "eats" all the dots. There are four ghosts patroling freely inside the maze, and that the players have to avoid them while eating up the dots. Eating the large flashing dots (also called the power pellet) turns the ghosts into a benign state, where additional scores are given when Pac-Man eats them up.

## Game rules

1. The player starts a game by entering the player name and the file name of the map in the terminal.

2. The player can choose pre-designed maps or self-made maps.

3. When the game starts, the player can use arrow keys (↑↓←→) in the keyboard to control the Pacman.

4. The player loses 1 life each time he/she is caught by the ghost.

5. Eating the pellet boosts the pacman to 50 strength. The player can then eat the ghosts until the strength level drops to 0.

6. The player wins the game by eating all the dots in the map.

7. The player loses the game when he/she loses all 3 lifes.


## Features implemented
1.  Generation of random game sets or events
    * The next move of ghost is randomly generated using random seeds.

2.  Data structures for storing game status
    * Custom classes are implemented to partition the program into smaller bits and bundling functional parts together for modularization and effective problem solving.
        1. The player's status is represented by the Player class.
        2. The pacman and ghosts states are represented by the Pacman and Ghost classes respectively.
        3. MainGame, ScreenRenedrer and Map exist as utility classes that constitute the core game logic and functions.

3.  Dynamic memory management
    * Vectors are used in the maze class to store the positions of the pacman, ghosts and walls.
    * A dynamically allocated integer array is used to store the player's scores in each difficulty level.

4.  File I/O (e.g. for loading or saving game status)
    * For file input, text files which contain the structure of the maze is loaded during initialization of the game. A player can also choose to load exisiting saves.
    * For file output, when mode m is choosen, player are allowed to create a map on their own and save the map for later use. 

5.  Program codes in multiple files
    * The program's code is partitioned into multiple .cpp and header files, according to classes.

## List of non-standard C/C++ libraries included

* Ncurses

## Compilation and execution instruction
1. Navigate to the src directory by the command "cd src"

2. Compile the game by the command "make main"

3. Execute the game by the command "./main"

4. Clean the object codes by the command "make clean"

## Demonstration of gameplay

