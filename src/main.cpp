#include <iostream>
#include <fstream>
#include "makemaze.h"
#include "maingame.h"
using namespace std;

void printStartMenu();
string takeCmdInput(string prompt);
void printFile(const string& fileName);

int main() {
    string command;
    do {
        printStartMenu();
        command = takeCmdInput("Input your choice");
        if (command=="p") // start game
        {
            system("ls ../map/ > ../map/maplist.txt");
            printFile("../map/maplist.txt");
            string filename;
            filename = takeCmdInput("Choose a map to play");
            MainGame game(filename);
            while(game.mainLoop());
        }
        else if (command=="r") // show rule form file
        {
            printFile("../templates/gamerule.txt");
            takeCmdInput("Press any key to quit");
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
