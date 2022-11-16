#ifndef PACMAN
#define PACMAN


class Pacman{
  public:
    Pacman(int spawnX, int spawnY);
    void setVelocity(int x,int y);
    void setPosition(int x,int y);
    int* getVelocity();
    int* getPosition();
    
  
  private:
    int* position;
    int* velocity;
  
};
#endif
