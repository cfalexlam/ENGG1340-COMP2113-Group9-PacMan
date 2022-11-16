#include "maze.h"
#include <fstream>
#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';

Maze::Maze(string filename){
  ifstream fin;
  fin.open(filename); //later change to ".//map//filename.txt"
  
  if ( fin.fail() ){
    return;
  }
  
  string line;
  int i=0;
  while (getline(fin,line))
  {
    vector<char> temp;
    this->maze.push_back(temp);
    for (int j=0;j<line.size();j++)
    	if (line[j]==WALL)
        	this->maze[i][j].push_back(WALL);
    	else if (i == this-p->getPostion[0] and j == this-p->getPostion[1])
        	this->maze[i][j].push_back(PLAYER);
     	else 
        	this->maze[i][j].push_back(FOOD);
    i+=1;
  }
}

void Maze::printMaze(){
	for (int i=0;i<this->maze.size();i++)
		for (int j=0;j<this->maze[0].size();j++)
			printw("%c",maze[i][j]);
}

bool Maze::isWall(int x,int y)
{
	return this-> maze[x][y]==WALL;
}

bool Maze::isGhost(int x,int y)
{
	return this-> maze[x][y]==GHOST;
}

bool Maze::isFood(int x,int y)
{
	return this-> maze[x][y]==FOOD;
}
