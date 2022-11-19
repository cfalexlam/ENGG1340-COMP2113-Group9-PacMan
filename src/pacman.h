#ifndef PACMAN
#define PACMAN


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
