#ifndef PACMAN_H
#define PACMAN_H


class Pacman{
  public:
    void setVelocity(int row, int col);
    void setPosition(int row, int col);
    int* getVelocity();
    int* getPosition();

    // Invulnerable state counter
    int strong;
  
  private:
    int* position;
    int* velocity;
  
};
#endif
