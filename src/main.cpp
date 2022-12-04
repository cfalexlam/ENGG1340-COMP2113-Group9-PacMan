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
void printFile(const string & fileName);
vector < string > getMazeList();
string chooseMaze(vector < string > MazeList);

int main() {
    string command;
    do {
        printStartMenu();
        command = takeCmdInput("Input your choice");
        if (command == "p") // start game
        {
            string filename = chooseMaze(getMazeList());
            MainGame game(filename);
            while (game.mainLoop());
        } else if (command == "r") // show rule form file
        {
            printFile("../templates/gamerule.txt");
            takeCmdInput("Enter any key to quit");
        } else if (command == "m") {
            makemaze();
        }
    } while (command != "q");
    return 1;
}

/*
  Function: Print the main menu of the game
  Input: None
  Output: None
*/
void printStartMenu() {
    system("clear");
    printFile("../templates/welcome.txt");
    printFile("../templates/command.txt");
}

/*
  Ask for user input with prompt
  Input: a string of prompt
  Output: a string of user input
*/
string takeCmdInput(string prompt) {
    cout << prompt << endl;
    string input;
    cin >> input;
    return input;
}

/*
  Print the content of the file
  Input: a string of file name
  Output: None
*/
void printFile(const string & fileName) {
    ifstream fin(fileName);

    if (fin.fail()) {
        return;
    }

    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

/*
  Get the file list in the map directory
  Input: None
  Output: a string vector with file names as elements
*/
vector < string > getMazeList() {
    vector < string > MazeList;
    if (auto dir = opendir("../maze/")) {
        while (auto f = readdir(dir)) {
            if (!f -> d_name || f -> d_name[0] == '.')
                continue; // Skip everything that starts with a dot
            MazeList.push_back(f -> d_name);
        }
        closedir(dir);
    }
    sort(MazeList.begin(), MazeList.end());
    return MazeList;
}

/*
  Function: Choose a maze from the mazelist
  Input: a string vector with file names as elements 
  Output: a string of valid file name
*/
string chooseMaze(vector < string > MazeList) {
    // Print the map list
    system("clear");
    cout << "Map list:" << endl;
    for (int i = 0; i < MazeList.size(); i++) {
        cout << MazeList[i] << endl;
    }
    cout << endl;

    // Input the filename of the map
    string filename;
    while (true) {
        cout << "Which maze you want to load? Please type the file name." << endl;
        cin >> filename;
        // Check if the input is in the map list
        for (int i = 0; i < MazeList.size(); i++) {
            if (filename == MazeList[i]) {
                return filename;
            }
        }
        cout << "Invalid file name." << endl;
    }
}