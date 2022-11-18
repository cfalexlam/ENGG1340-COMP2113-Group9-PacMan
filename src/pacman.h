#ifndef PACMAN
#define PACMAN


class Pacman{
  public:
    Pacman(int spawnRow, int spawnCol);
    void setVelocity(int row,int col);
    void setPosition(int row,int col);
    int* getVelocity();
    int* getPosition();
    
  
  private:
    int* position;
    int* velocity;
  
};
#endif
