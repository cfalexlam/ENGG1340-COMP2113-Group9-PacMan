#ifndef PACMAN_H
#define PACMAN_H

class Pacman{
public:
    // Set the current and presumed velocity and postion of pacman
    void setCurrentVelocity(int row, int col);
    void setCurrentPosition(int row, int col);
    void setPresumedVelocity(int row,int col);
    int* getCurrentVelocity();
    int* getCurrentPosition();
    int* getPresumedVelocity();
    int* getPresumedPosition();

    // Invulnerable state counter
    int strong=0;
    int initPosition[2];
private:
    int currentPosition[2];
    int currentVelocity[2];
    int presumedPosition[2];
    int presumedVelocity[2]={0,0};
};
#endif
