#ifndef PACMAN
#define PACMAN


class PACMAN{
  public:
  
    void initpacman();
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    int getXvelocity();
    int getYvelocity();
  private:
    int currentX,currentY;
    int xVelocity=0,yVelocity=0;
  
};
#endif
