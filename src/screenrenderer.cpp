#include "screenrenderer.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ncurses.h>

using namespace std;

// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::KeyboardModeOpen() { // in keyboardmode, use printw(mystring.c_str()) instead of cout<< mystring
    initscr(); // initialize screen
    noecho(); // no input display
    keypad(stdscr,true); // allow arrow key
}

void ScreenRenderer::KeyboardModeWB() {
    nodelay(stdscr,false); /* Takes keyboard input with blocking or delay */
}

void ScreenRenderer::KeyboardModeNB() {
    nodelay(stdscr,true); /* Takes keyboard input without blocking or delay */
}

void ScreenRenderer::KeyboardModeClose() {
    echo();
    endwin();
}

void ScreenRenderer::KeyboardModePrint(string str) {
    printw(str.c_str());
}

void ScreenRenderer::printLoseScreen(Player pl) {
  cout << setw(20) << "YOU LOSE" << endl;
  cout << "You die at level " << pl.getLevel() << endl;
  cout << "Your total score is " << pl.getScore() << endl;
  cout << "(Press any key to continue)"<< endl;
}
