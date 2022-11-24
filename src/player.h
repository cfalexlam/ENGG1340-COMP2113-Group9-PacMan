#ifndef PLAYER_H
#define PLAYER_H


class PLAYER{
    public:
        vector<int> getScore();
        vector<int> updateScore();
        vector<int> updateLevel();
    private:
        int currentLevel = 1;
        int *score = new int[currentLevel];
};

#endif
