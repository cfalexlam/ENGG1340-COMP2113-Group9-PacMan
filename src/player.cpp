#include <vector>

class Player{ // constructor tbc
    public:
        vector<int> getScore();
        vector<int> updateScore();
        vector<int> updateCurrentLevel();
    private:
        int currentLevel = 1;
        int *score = new int[currentLevel];
        int lives = 3
};

vector<int> Player::getScore(){
    return score;
}

vector<int> Player::updateScore(int increment){
    score += increment;
}

vector<int> Player::updateCurrentLevel(){
    currentLevel += 1;
    // resize array, to be completed
    delete [] score;
}