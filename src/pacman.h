#ifndef PACMAN
#define PACMAN


class Pacman{
  public:
    void changeDirection(int x,int y);
    int* getVelocity();
    int* getPosition();
    Pacman(int spawnX, int spawnY);
  private:
    int* position;
    int* velocity;
  
};
#endif
