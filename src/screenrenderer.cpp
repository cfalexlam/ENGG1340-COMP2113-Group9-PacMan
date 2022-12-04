#include "screenrenderer.h"
#include "player.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::keyboardModeOpen() {
    initscr(); // initialize screen
    noecho(); // no input display
    keypad(stdscr,true); // allow arrow key
}

// Takes keyboard input with blocking or delay
void ScreenRenderer::keyboardModeWB() {
    nodelay(stdscr,false);
}

// Takes keyboard input without blocking or delay
void ScreenRenderer::keyboardModeNB() {
    nodelay(stdscr,true);
}

// Close the instant keyboard input mode
void ScreenRenderer::keyboardModeClose() {
    echo();
    endwin();
}

// In keyboardmode, use printw(mystring.c_str()) instead of cout << mystring
void ScreenRenderer::keyboardModePrint(string str) {
    printw(str.c_str());
}

// Display screen when the player loses
void ScreenRenderer::printLoseScreen(Player player) {
    printw("YOU LOSE!\n");
    printw("Your total score is %d \n", player.getScore());
}

// Display screen when the player wins
void ScreenRenderer::printWinScreen(Player player) {
    printw("CONGRATULATION! YOU WIN!\n");
    printw("Your total score is %d \n", player.getScore());
}

