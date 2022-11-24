#ifndef GHOST_H
#define GHOST_H


class Ghost{
  public:
    Ghost();
    void setVelocity(int row, int col);
    void setPosition(int row, int col);
    int* getVelocity();
    int* getPosition();
  private:
    int* position;
    int* velocity;
  
};
#endif
