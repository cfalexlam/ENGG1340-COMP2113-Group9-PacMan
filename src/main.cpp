#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include "makemaze.h"
#include "maingame.h"
using namespace std;

void printStartMenu();
string takeCmdInput(string prompt);
void printFile(const string& fileName);
vector<string> getMapList();
string chooseMap(vector<string> MapList);

int main() {
    string command;
    do {
        printStartMenu();
        command = takeCmdInput("Input your choice");
        if (command=="p") // start game
        {   
            string filename = chooseMap(getMapList());
            MainGame game(filename);
            while(game.mainLoop());
        }
        else if (command=="r") // show rule form file
        {
            printFile("../templates/gamerule.txt");
            takeCmdInput("Enter any key to quit");
        }
        else if (command == "m") {
            makemaze();
        } 
    }while (command!="q");
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

// get the map list in the map directory
vector<string> getMapList() {
  vector<string> MapList;
  if (auto dir = opendir("../map/")) {
    while (auto f = readdir(dir)) {
      if (!f->d_name || f->d_name[0] == '.')
        continue;  // Skip everything that starts with a dot
      MapList.push_back(f->d_name);
    }
    closedir(dir);
  }
  sort(MapList.begin(), MapList.end());
  return MapList;
}

// choose a map from the maplist
string chooseMap(vector<string> MapList) {
  // Print the map list
  system("clear");
  cout << "Map list:" << endl;
  for (int i = 0; i < MapList.size(); i++) {
    cout << MapList[i] << endl;
  }
  cout << endl;

  string filename;
  while (true) {
    cout << "Which map you want to load? Please type the file name." << endl;
    cin >> filename;
	// Check if the input is in the map list
    for (int i = 0; i < MapList.size(); i++) {
      if (filename == MapList[i]) {
        return filename;
      }
    }
    cout << "Invalid file name." << endl;
  }
}