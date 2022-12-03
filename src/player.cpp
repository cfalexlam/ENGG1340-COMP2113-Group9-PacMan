#include "player.h"

int Player::getScore(){
    return score;
}

void Player::addScore(int increment){
    score += increment;
}


int Player::getLives(){
    return lives;
}

void Player::loseLife(){
    lives -= 1;
}
