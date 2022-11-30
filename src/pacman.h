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
    int* initPosition;
  private:
    int* currentPosition;
    int* currentVelocity;
    int* presumedPosition;
    int* presumedVelocity;
    
    
  
};
#endif
