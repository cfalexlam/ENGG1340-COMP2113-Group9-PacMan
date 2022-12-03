#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        // score manipulation
        int getScore();
        void addScore(int increment);

        // lives manipulation
        int getLives();
        void loseLife();

    private:
        int lives=3;
        int score=0;
};

#endif
