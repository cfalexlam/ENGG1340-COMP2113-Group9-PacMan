#include "maze.h"

#include <fstream>

#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';
char PELLETS = 'O';

void Maze::Maze(std::string filename) {
    std::ifstream fin;
    fin.open(filename); //later change to ".//map//filename.txt"

    if (fin.fail()) { // file not exist;
        return;
    }
    std::string line, row, col;
    std::istringstream linein;

    getline(fin, line); // Read in pacman position
    linein.str(line);
    linein >> row >> col;
    pacman.setPosition(stoi(row), stoi(col));
    linein.clear();

    getline(fin, line); // Read in ghost positions

    for (int i = 0, j = stoi(line); i < j; i++) {
        getline(fin, line);
        linein.str(line);
        linein >> row >> col;

        Ghost ghost(stoi(row), stoi(col));
        ghosts.push_back(ghost);
        linein.clear();
    }

    getline(fin, line); // Read in power pellet positions
    Pellet pellet;
    for (int i = 0, j = stoi(line); i < j; i++) {
        getline(fin, line);
        linein.str(line);
        linein >> row >> col;

        pellet.setPosition(stoi(row), stoi(col)); // Store positions in power pellets
        pellets.push_back(pellet);
        linein.clear();
    }

    int i = 0; // Read in the map
    while (getline(fin, line)) {
        std::vector < char > temp;
        maze.push_back(temp);
        for (int j = 0; j < line.size(); j++)
            if (line[j] == WALL)
                maze[i].push_back(WALL);
            else {
                maze[i].push_back(FOOD);
                food += 1;
            }
        i += 1;
    }
    for (int i = 0; i < pellets.size(); i++) {
        maze[pellets[i].getPosition()[0]][pellets[i].getPosition()[1]] = PELLETS;
        food -= 1;
    }
    for (int i = 0; i < ghosts.size(); i++) {
        maze[ghosts[i].getPosition()[0]][ghosts[i].getPosition()[1]] = GHOST;
        food -= 1;
    }
    maze[pacman.getPosition()[0]][pacman.getPosition()[1]] = PLAYER;
    food -= 1;
}

void Maze::printMaze() {
    for (int row = 0; row < maze.size(); row++) {
        for (int col = 0; col < maze[0].size(); col++)
            printw("%c ", maze[row][col]);
    }
}
int Maze::foodLeft() {
    return food;
}
void Maze::movePacman(std::vector < std::vector < char >> maze, int row, int col, int nrow, int ncol) {
    maze[row][col] = SPACE;
    maze[nrow][ncol] = PLAYER;
}

void Maze::moveGhost(){
    for (int i=0; i<maze.ghosts.size(); i++){
        int newPosX = ghosts[i].currentPosition()[0] + ghosts[i].currentVelocity()[0];
        int newPosY = ghosts[i].currentPosition()[1] + ghosts[i].currentVelocity()[1];

        maze[ghosts[i].currentPosition()[0]][ghosts[i].currentPosition()[0]] = ghosts[i].liftedObject;
        ghost[i].liftedObject = maze[newPosX][newPosY]
        maze[newPosX][newPosY] = GHOST;

        ghost[i].currentPosition[0] = newPosX;
        ghost[i].currentPosition[1] = newPosY;
    }
}

void Maze::respawnGhost(Ghost& g){
    maze[g.currentPosition[0]][currentPosition[1]] = g.liftedObject;
    g.liftedObject = maze[g.initPosition[0]][g.initPosition[1]];
    maze[g.initPosition[0]][g.initPosition[1]] = GHOST;
    
    g.currentPosition = g.initPosition;
    g.setVelocity(0, 0);
}

void Maze::respawnSameLevel(){
    movePacman(pacman.currentPosition[0], pacman.currentPosition[1],
               pacman.initPosition[0], pacman.initPosition[1])
    pacman.setPosition(pacman.initPosition[0], pacman.initPosition[1])
    pacman.setVelocity(0, 0);
    for (int i=0; i<ghosts.size(); i++){
        respawnGhost(ghosts[i]);
    }
}

bool Maze::isWall(int row, int col) {
    return maze[row][col] == WALL;
}

bool Maze::isGhost(int row, int col) {
    return maze[row][col] == GHOST;
}

bool Maze::isFood(int row, int col) {
    return maze[row][col] == FOOD;
}