#include "maze.h"
#include <fstream>
#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';
char PELLETS = 'O';

void Maze::maze(std::string filename) {
  std::ifstream fin;
  fin.open(filename); //later change to ".//map//filename.txt"

  if (fin.fail()) { //file not exist;
    return;
  }
  std::string line, row, col;
  std::istringstream linein;

  getline(fin, line); //read in the pacman position
  linein.str(line);
  linein >> row >> col;
  pacman.setPosition(stoi(row), stoi(col));
  linein.clear();

  getline(fin, line); //read in the ghost
  Ghost ghost;   //set position of  ghost
  std::vector <Ghost> ghosts;
  for (int i = 0, j = stoi(line); i < j; i++) {
    getline(fin, line);
    linein.str(line);
    linein >> row >> col;
   
    ghost.setPosition(stoi(row),stoi(col));
    ghosts.push_back(ghost);
    linein.clear();
  }

  getline(fin, line); //read in the power pellets
  Pellet pellet;   //set position of power pellets
  std::vector <Pellet> pellets;
  for (int i = 0, j = stoi(line); i < j; i++) {
    getline(fin, line);
    linein.str(line);
    linein >> row >> col;

    pellet.setPosition(stoi(row),stoi(col));
    pellets.push_back(pellet);
    linein.clear();
  }

  for (int i = 0, j = stoi(line); i < j; i++) {
    getline(fin, line);
    linein.str(line);
    linein >> row >> col;
    
    pellet.setPosition(stoi(row),stoi(col));
    pellets.push_back(pellet);
    linein.clear();
  }

  int i = 0; //read in the map
  while (getline(fin, line)) {
    std::vector < char > temp;
    themaze.push_back(temp);
    for (int j = 0; j < line.size(); j++)
      if (line[j] == WALL)
        themaze[i].push_back(WALL);
      else
      {
        themaze[i].push_back(FOOD);
        food += 1;
      }
    i += 1;
  }
  for (int i=0;i < pellets.size();i++)
  {
    themaze[pellets[i].getPosition()[0]][pellets[i].getPosition()[1]] = PELLETS;
    food -= 1;
  }
  for (int i=0;i < ghosts.size();i++)
  {
    themaze[ghosts[i].getPosition()[0]][ghosts[i].getPosition()[1]] = GHOST;
    food -= 1;
  }
  themaze[pacman.getPosition()[0]][pacman.getPosition()[1]] = PLAYER;
  food -= 1;
}

void Maze::printMaze() {
  for (int row = 0; row < themaze.size(); row++) {
    for (int col = 0; col < themaze[0].size(); col++)
      printw("%c ", themaze[row][col]);
    }
}
int Maze::foodLeft() {
  return food;
}
void Maze::movePacman(std::vector <std::vector <char>> maze, int row, int col, int nrow, int ncol) {
  maze[row][col] = SPACE;
  maze[nrow][ncol] = PLAYER;
}

bool Maze::isWall(std::vector <std::vector <char>> maze, int row, int col) {
  return maze[row][col] == WALL;
}

bool Maze::isGhost(std::vector <std::vector <char>> maze, int row, int col) {
  return maze[row][col] == GHOST;
}

bool Maze::isFood(std::vector <std::vector <char>> maze, int row, int col) {
  return maze[row][col] == FOOD;
}