#ifndef PELLET_H
#define PELLET_H

class Pellet {
    public: 
        Pellet(int row, int col);
        int * getPosition();
        bool exist = true;
    private: 
        int position[2];
};

#endif