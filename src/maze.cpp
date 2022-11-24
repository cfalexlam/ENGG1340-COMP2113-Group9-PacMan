#include "maze.h"
#include <fstream>
#include <string>
#include <vector>

int Maze::loadMaze(std::string fileName){
    /*
    Load maze from text file into vector; and initialize the position of Pacman and Ghosts
    */

    // load file
    std::ifstream fin(fileName);

    // error handling
    if (fin.fail()){
        return 1;
    }

    std::string line;
    int currentLineNumber = 0;
    while (std::getline(fin, line)){
        std::vector<int> v;
        for (int i = 0; i < line.length(); i++){
            v.push_back(line[i]);
        }
        maze.push_back(v);
    }
    fin.close();
    
    return 0;
}

int Maze::initDotsVector(){
    for (int i=0; i<this->ROWNUMBER; i++){
        for (int j=0; j<this->COLNUMBER; j++){
            if (maze[i][j] == '·'){
                dots.emplace_back(i,j);
            }
        }
    }
}

int Maze::removeDots(int x, int y){
    
}

// restart the game while keeping the dots; respawn the ghosts and pacman at their spawnpoints
void Maze::respawn(bool newLevel){ // will implement increase in difficulty later
    this->pinky.currentX = 1;
    this->pinky.currentY = 1;
    this->clyde.currentX = 37;
    this->clyde.currentY = 1;
    this->inky.currentX = 37;
    this->inky.currentY = 3;
    this->blinky.currentX = 37;
    this->blinky.currentY = 5;
    this->pacman.currentX = 37;
    this->pacman.currentY = 7;
}

// update position of entities
void Maze::updatePos(){

}

// update states of entities
void Maze::updateStates(){

}