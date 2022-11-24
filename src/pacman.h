#ifndef PACMAN
#define PACMAN


class PACMAN{
  public:
  
    void initPacman();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getXvelocity();
    int getYvelocity();
  private:
    int currentX,currentY;
    int xVelocity=0,yVelocity=0;
  
};
#endif
