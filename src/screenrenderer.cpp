#include "screenrenderer.h"
#include <iostream>
#include <fstream>
#include <ncurses.h>

using namespace std;

// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::KeyboardModeOpen() { // in keyboardmode, use printw(mystring.c_str()) instead of cout<< mystring
    initscr(); //initialize screen
    noecho(); // no input display
    keypad(stdscr,true) // allow arrow key
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

string ScreenRenderer::takeCmdInput(string message) {
    cout << message << endl;
    string input;
    cin >> input;
    return input;
}

void ScreenRenderer::printFile(const string& fileName) {
  ifstream fin(fileName);
  string line;
  while (getline(fin, line))
    cout << line << endl;
  fin.close();
}

void ScreenRenderer::printStartMenu() {
  system("clear");

  printFile("welcome.txt");

  printFile("command.txt");

  char input;
  while (cin >> input) {
    switch (input) {
      case 'p':
        return;

      case 'q':
        exit(0);

      case 'r':
        printFile("gamerule.txt");
        cout << "Please enter the next command (p/r/q)" << endl;
        break;

      default:
        cout << "Invalid command. Please try again." << endl;
    }
  }
}
