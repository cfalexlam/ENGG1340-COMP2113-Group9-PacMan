#ifndef GHOST_H
#define GHOST_H

class Maze;

class Ghost{
  public:
    // https://softwareengineering.stackexchange.com/questions/388977/how-to-reach-the-parent-object
    Ghost(Maze* m, int row, int col);
    void setCurrentVelocity(int row, int col);
    void setCurrentPosition(int row, int col);
    int* getCurrentVelocity();
    int* getCurrentPosition();
    void setRandomVelocity();
    
    // Reset position of ghost
    void respawn();
    int initPosition[2];
    char liftedObject = ' ';
  private:
    
    int currentPosition[2];
    int currentVelocity[2]={0,0};
    
    Maze* m;
  
};
#endif
