#include "screenrenderer.h"
#include "player.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

/*
  Function: Receive and convert keyboard input into move and decide further actions
  Input: None
  Output: None
*/
void ScreenRenderer::keyboardModeOpen() {
    initscr(); // initialize screen
    noecho(); // no input display
    keypad(stdscr,true); // allow arrow key
}

/*
  Function: Takes keyboard input with blocking or delay
  Input: None
  Output: None
*/
void ScreenRenderer::keyboardModeWB() {
    nodelay(stdscr,false);
}

/*
  Function: Takes keyboard input without blocking or delay
  Input: None
  Output: None
*/
void ScreenRenderer::keyboardModeNB() {
    nodelay(stdscr,true);
}

/*
  Function: Close the instant input mode
  Input: None
  Output: None
*/
void ScreenRenderer::keyboardModeClose() {
    echo();
    endwin();
}

/*
  Function: Print a string in the keyboard mode
  Input: a string of message
  Output: None
*/
void ScreenRenderer::keyboardModePrint(string str) {
    printw(str.c_str());
}

/*
  Function: Display screen when the player loses
  Input: a player object
  Output: None
*/
void ScreenRenderer::printLoseScreen(Player player) {
    printw("YOU LOSE!\n");
    printw("Your total score is %d \n", player.getScore());
}

/*
  Function: Display screen when the player wins
  Input: a player object
  Output: None
*/
void ScreenRenderer::printWinScreen(Player player) {
    printw("CONGRATULATION! YOU WIN!\n");
    printw("Your total score is %d \n", player.getScore());
}

