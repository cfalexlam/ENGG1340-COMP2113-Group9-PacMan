#include "screenrenderer.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ncurses.h>



// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::keyboardModeOpen() { // in keyboardmode, use printw(mystring.c_str()) instead of cout<< mystring
    initscr(); // initialize screen
    noecho(); // no input display
    keypad(stdscr,true); // allow arrow key
}

void ScreenRenderer::keyboardModeWB() {
    nodelay(stdscr,false); /* Takes keyboard input with blocking or delay */
}

void ScreenRenderer::keyboardModeNB() {
    nodelay(stdscr,true); /* Takes keyboard input without blocking or delay */
}

void ScreenRenderer::keyboardModeClose() {
    echo();
    endwin();
}

void ScreenRenderer::keyboardModePrint(std::string str) {
    printw(str.c_str());
}

void ScreenRenderer::printLoseScreen(Player pl) {
    printw("YOU LOSE!\n");
    printw("You die at level %d \n", pl.getLevel());
    printw("Your total score is %d \n", pl.getScore());
}

void ScreenRenderer::printWinScreen(Player pl) {
    printw("CONGRATULATION! YOU WIN!\n");
    printw("Your total score is %d \n", pl.getScore());
}

