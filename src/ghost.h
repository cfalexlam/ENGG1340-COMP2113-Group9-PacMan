#ifndef GHOST_H
#define GHOST_H

class Maze;

class Ghost{
public:
    // Passing parent object and initial position of the ghost
    Ghost(Maze* m, int row, int col);

    // Update velocities and positions
    void setCurrentVelocity(int row, int col);
    void setCurrentPosition(int row, int col);
    int* getCurrentVelocity();
    int* getCurrentPosition();
    int* getPresumedPosition();
    void setRandomVelocity();
    
    // Store the initial position of the ghost
    int initPosition[2];

    // Store the entity on the map that overlaps with the current position of the ghost
    char liftedObject = ' ';

private:
    // Store positions and celocities of the ghost
    int currentPosition[2];
    int currentVelocity[2]={0,0};
    int presumedPosition[2];
    Maze* m;
};

#endif
