#include <iostream>
#include <fstream>
#include "maingame.h"
using namespace std;

int main(){
  string command;
  do{
    printStartMenu();
    command = takeCmdInput("Input your choice");
    if (command=="p") // start game
    {
      string playername;
      playername = takeCmdInput("Input your name");
      MainGame game(playername);
      while (game.mainLoop);
    }
    if (command=="r") //show rule
      
  }
  while (command!="q");
  return 1;
}

void printStartMenu() {
  system("clear");
  printFile("../templates/welcome.txt");
  printFile("../templates/command.txt");
}

string takeCmdInput(string prompt) {
    cout << prompt << endl;
    string input;
    cin >> input;
    return input;
}

void printFile(const string& fileName) {
  ifstream fin(fileName);

  if (fin.fail()) {
    return;
  }

  string line;
  while (getline(fin, line))
    cout << line << endl;
  fin.close();
}
