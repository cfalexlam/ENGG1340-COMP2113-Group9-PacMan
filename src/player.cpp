#include "player.h"

/*
  Function: Get the score variable of the player object
  Input: none
  Output: an integer of score
*/
int Player::getScore() {
    return score;
}

/*
  Function: Add the score variable of the player object by the increment
  Input: an integer of increment
  Output: None
*/
void Player::addScore(int increment){
    score += increment;
}

/*
  Function: Get the lives variable of the player object
  Input: None
  Output: an integer of lives
*/
int Player::getLives(){
    return lives;
}

/*
  Function: Reduce the lives of the player object by 1
  Input: None
  Output: None
*/
void Player::loseLife(){
    lives -= 1;
}
