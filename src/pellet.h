#ifndef PELLET_H
#define PELLET_H

class Pellet{
    public:
        int* getPosition();
        void setPosition(int row, int col); 
    private:
        int position[2];
};

#endif
