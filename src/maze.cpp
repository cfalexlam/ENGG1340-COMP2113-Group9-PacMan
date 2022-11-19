#include "maze.h"
#include <fstream>
#include <sstream>

char WALL = '=';
char FOOD = '.';
char PLAYER = 'X';
char SPACE = ' ';
char GHOST = 'Q';
char PELLETS = 'O'
	
Maze::Maze(string filename){
	ifstream fin;
	fin.open(filename); 		//later change to ".//map//filename.txt"
  
	if ( fin.fail() ){ 			//file not exist;
    	return;
	}
	string line,row,col;
	isstringstream linein;
	
	getline(fin,line);    		//read in the pacman position
	linein.str(line);
	linein >> row;
	linein >> col;
	p.setPosition(stoi(row),stoi(col));
	linein.clear();
	
	getline(fin,line);  		//read in the ghost
	for (int i=0,j=stoi(line);i<j;i++)
	{
		getline(fin,line);
		linein.str(line);
		linein >> row;
		linein >> col;
								//set position of  ghost
		linein.clear();
	}
	
	getline(fin,line);  		//read in the power pellets
	for (int i=0,j=stoi(line);i<j;i++)
	{
		getline(fin,line);
		linein.str(line);
		linein >> row;
		linein >> col;
								//set position of power pellets
		linein.clear();
	}
	
  	int i=0;					//read in the map
  	while (getline(fin,line))
  	{
    	vector<char> temp;
    	maze.push_back(temp);
    	for (int j=0;j<line.size();j++)
			
    		if ( line[j] == WALL)
        		maze[i][j].push_back(WALL);
		
    		else if (i == p.getPostion[0] and j == p.getPostion[1])
        		maze[i][j].push_back(PLAYER);
		
			else if ()
				
			else if ()
				
     		else 
        		maze[i][j].push_back(FOOD);
	  			food+=1;
    	i+=1;
  	}
}

void Maze::printMaze(){
	for (int row=0;row<maze.size();row++)
		for (int col=0;col<maze[0].size();col++)
			printw("%c ",maze[row][col]);
}
int Maze::foodLeft(){
	return food;
}
void Maze::movePacman(int row,int col, int nrow,int ncol)
{
	maze[row][col] = SPACE;
	maze[nrow][ncol] = PLAYER;
}

bool Maze::isWall(int row,int col)
{
	return maze[row][col] == WALL;
}

bool Maze::isGhost(int row,int col)
{
	return maze[row][col] == GHOST;
}

bool Maze::isFood(int row,int col)
{
	return maze[row][col] == FOOD;
}
