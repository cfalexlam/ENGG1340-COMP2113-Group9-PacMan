#ifndef PACMAN_H
#define PACMAN_H


class Pacman{
  public:
    void setCurrentVelocity(int row, int col);
    void setCurrentPosition(int row, int col);
    void setPresumedVelocity(int row,int col);
    int* getCurrentVelocity();
    int* getCurrentPosition();
    int* getPresumedVelocity();
    int* getPresumedPosition();

    // Invulnerable state counter
    int strong;
    int initPosition[2];
  private:
    void setPresumedPosition();
    int currentPosition[2];
    int currentVelocity[2];
    int presumedPosition[2];
    int presumedVelocity[2]={0,0};
    
    
  
};
#endif
