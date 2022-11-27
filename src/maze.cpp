#include "maze.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';
char PELLETS = 'O';

Maze::Maze(string filename) {
  ifstream fin;
  fin.open(filename); //later change to ".//map//filename.txt"

  if (fin.fail()) { //file not exist;
    return;
  }
  string line, row, col;
  isstringstream linein;

  getline(fin, line); //read in the pacman position
  linein.str(line);
  linein >> row >> col;
  p.setPosition(stoi(row), stoi(col));
  linein.clear();

  getline(fin, line); //read in the ghost
  for (int i = 0, j = stoi(line); i < j; i++) {
    getline(fin, line);
    linein.str(line);
    linein >> row >> col;
   
    Ghost ghost;   //set position of  ghost
    vector <Ghost> ghosts;
    ghost.setPosition(stoi(row),stoi(col));
    ghosts.push_back(ghost);
    linein.clear();
  }

  getline(fin, line); //read in the power pellets
  for (int i = 0, j = stoi(line); i < j; i++) {
    getline(fin, line);
    linein.str(line);
    linein >> row >> col;
    
    Pellet pellet;   //set position of power pellets
    vector <Pellet> pellets;
    pellet.setPosition(stoi(row),stoi(col));
    pellets.push_back(pellet);
    linein.clear();
  }

  int i = 0; //read in the map
  while (getline(fin, line)) {
    vector < char > temp;
    maze.push_back(temp);
    for (int j = 0; j < line.size(); j++)
      if (line[j] == WALL)
        maze[i].push_back(WALL);
      else
      {
        maze[i].push_back(FOOD);
        food += 1;
      }
    i += 1;
  }
  for (int i=0;i<pellets.size();i++)
  {
    maze[pellets[i].getPosition()[0]][pellets[i].getPosition()[1]] = PELLET;
    food -= 1;
  }
  for (int i=0;i<ghosts.size();i++)
  {
    maze[ghosts[i].getPosition()[0]][ghosts[i].getPosition()[1]] = GHOST;
    fodd -= 1;
  }
  maze[pacman.getPosition()[0]][pacman.getPosition()[1]] = PLAYER;
  food -= 1;
}

void Maze::printMaze() {
  for (int row = 0; row < maze.size(); row++)
    for (int col = 0; col < maze[0].size(); col++)
      printw("%c ", maze[row][col]);
}
int Maze::foodLeft() {
  return food;
}
void Maze::movePacman(int row, int col, int nrow, int ncol) {
  maze[row][col] = SPACE;
  maze[nrow][ncol] = PLAYER;
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
