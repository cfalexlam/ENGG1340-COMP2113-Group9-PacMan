#include "screenrenderer.h"
#include <iostream>
#include <fstream>

// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::KeyboardModeOpen(){ // in keyboardmode, use printw(mystring.c_str()) instead of cout<< mystring
    initscr(); //initialize screen
    noecho(); // no input display
}
void ScreenRenderer::KeyboardModeWb(){
    nodelay(stdscr,false); /* Takes keyboard input with blocking or delay */
    keypad(stdscr,false) // not allow arrow key
}
void ScreenRenderer::KeyboardModeNb(){
    nodelay(stdscr,true); /* Takes keyboard input without blocking or delay */
    keypad(stdscr,true) // allow arrow key
}
void ScreenRenderer::KeyboardModeClose(){
    endwin();
}
void ScreenRenderer::KeyboardModePrint(string str){
    printw(str.c_str());
}

string ScreenRenderer::takeCmdInput(string message){
    cout << message << endl;
    cin >> x;
    return x
}

void ScreenRenderer::printFile(const std::string& fileName) {
  std::ifstream fin(fileName);
  std::string line;
  while (std::getline(fin, line))
    std::cout << line << std::endl;
  fin.close();
}

void ScreenRenderer::printStartMenu() {
  system("clear");

  printFile("welcome.txt");

  printFile("command.txt");

  char input;
  while (std::cin >> input) {
    switch (input) {
      case 'p':
        return;

      case 'q':
        exit(0);

      case 'r':
        printFile("gamerule.txt");
        std::cout << "Please enter the next command (p/r/q)" << std::endl;
        break;

      default:
        std::cout << "Invalid command. Please try again." << std::endl;
    }
  }
}
