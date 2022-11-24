#ifndef GHOST
#define GHOST


class Ghost{
  public:
    void initGhost();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getXVelocity();
    int getYVelocity();
    Ghost(int initX, int initY, int xVelocity, int yVelocity);
  private:
    int initX, initY;
    int currentX, currentY;
    int xVelocity, yVelocity;
    
};
#endif
