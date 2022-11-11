# ENGG1340-COMP2113-Group9-PacMan
Group project for ENGG1340/COMP2113 

## Team members (Group 9)

## About the game

Pac-Man, originally called Puck Man in Japan, is a legendary and classic maze action video game which was developed and released in the 1980s. To score, a player controls the "Pac-Man" to move inside an enclosed maze filled up with dots and "eats" all the dots. There are four ghosts patroling freely inside the maze, and that the players have to avoid them while eating up the dots. Eating the large flashing dots (also called the power pellet) turns the ghosts into a benign state, where additional scores are given when Pac-Man eats them up.

### Game rules

1. The player starts the game by entering his name in the terminal.
2. The action of the Pac-Man is controlled using WASD keys. Press W to move upward, A to move downward, S to move left and D to move right.
3. Consuming a dot will grant the player 10 points, while consuming the power pellets, which are the large flashing dots, turns the ghosts blue for 10 seconds for Level 1 and make them edible for 200 points each. Extra points will be given (double the points of the most recently eaten ghost) if ghosts are eaten in succession.
4. Bonus fruit may appear and counts for 50 points when eaten.
5. The player is brought to the next level when all dots on the maze are eaten, where difficulty is raised: the ghosts move faster, and the power pellets' effect lasts shorter.
6. The game has 10 levels, and each player has 3 bonus lives. One life is lost when the Pac-Man collides with any of the ghosts.


## Features implemented
1. Generation of random game sets or events
    * Power pellets are randomly generated on the maze using random seeds

2. Data structures for storing game status
    * Custom classes are implemented to partition the program into smaller bits and bundling functional parts together for modularization and effective problem solving.
        1. The player's status is represented by the Player class.
        2. The pacman and ghosts states are represented by the Pacman and Ghost classes respectively.
        3. MainGame, ScreenRenedrer and Map exist as utility classes that constitute the core game logic and functions.

3. Dynamic memory management
    * Vectors are used in the maze class to store the positions of the pacman, ghosts and walls.
    * A dynamically allocated integer array is used to store the player's scores in each difficulty level.

4. File I/O (e.g. for loading or saving game status)
    * For file input, text files which contain the structure of the maze is loaded during initialization of the game. A player can also choose to load exisiting saves.
    * For file output, when the player quits the game, his current game status will be output to a text file. 

5. Program codes in multiple files
    * The program's code is partitioned into multiple .cpp and header files, according to classes.

## List of non-standard C/C++ libraries included

## Compilation and execution instruction

## Demonstration of gameplay

