#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player{
    public:
        Player(std::string playername);

        // score manipulation
        int getScore();
        void addScore(int increment);

        // level manipulation
        int getLevel();
        void addLevel();

        // lives manipulation
        int getLives();
        void loseLife();
        
        std::string getName();
    private:
        int level;
        int lives;
        int* score;
        int scoreSum;

        std::string playername;
};

#endif
