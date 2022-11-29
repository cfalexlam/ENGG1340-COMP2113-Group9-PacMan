#ifndef GHOST_H
#define GHOST_H

class Maze;

class Ghost{
  public:
    // https://softwareengineering.stackexchange.com/questions/388977/how-to-reach-the-parent-object
    Ghost(Maze &m, int row, int col) : Maze(m) {};
    void setVelocity(int row, int col);
    void setPosition(int row, int col);
    int* getVelocity();
    int* getPosition();
    
    // Reset position of ghost
    void respawn();

  private:
    int* initPosition;
    int* currentPosition;
    int* currentVelocity;
    char liftedObject;
    Maze &m;
  
};
#endif
