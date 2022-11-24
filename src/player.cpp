#include <vector>
#include <cstring>
#include "player.h"

Player::Player(char* name){
    int level = 1;
    int lives = 3;
    int *score = new int[level];
    int scoreSum = 0;

    char* name = name;
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