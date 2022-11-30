#include <vector>
#include <cstring>
#include "player.h"

Player::Player(std::string plname){
    level = 1;
    lives = 3;
    score = new int[level];
    scoreSum = 0;

    this->playername = playername;
}
std::string Player::getName(){
	return this->playername;
}
int Player::getScore(){
    return scoreSum;
}

void Player::addScore(int increment){
    score[level-1] += increment;
    scoreSum += increment;
}

int Player::getLevel(){
    return level;
}

void Player::addLevel(){
    level += 1;
    int* newScore = new int[level];
    std::memcpy(newScore, score, sizeof(score));
    delete [] score;
    score = newScore;
}

int Player::getLives(){
    return lives;
}

void Player::loseLife(){
    lives -= 1;
}
