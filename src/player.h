#ifndef PLAYER
#define PLAYER


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
