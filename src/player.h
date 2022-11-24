#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        Player(char* name);

        // score manipulation
        int getScore();
        void addScore(int increment);

        // level manipulation
        int getLevel();
        void addLevel();

        // lives manipulation
        int getLives();
        void loseLife();
    private:
        int level;
        int lives;
        int* score;
        int scoreSum;

        char* name;
};

#endif
