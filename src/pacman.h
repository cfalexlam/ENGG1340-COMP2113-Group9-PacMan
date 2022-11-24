#ifndef PACMAN_H
#define PACMAN_H


class Pacman{
  public:
    void setVelocity(int row,int col);
    void setPosition(int row,int col);
    int* getVelocity();
    int* getPosition();
    
  
  private:
    int* position;
    int* velocity;
  
};
#endif
