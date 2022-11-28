/* 
Alternatives for saving and loading games
3 functions in the main.cpp
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include "player.h"

using namespace std;

void PrintSaveStatus() {
  ifstream fin("../templates/save.txt");

  string line;

  cout << setfill('-') << setw(40) << '-' << setfill(' ') << endl;  // Printing parting line

  // Printing one row of description and three save slots
  for (int i = 0; i < 4; ++i) {
    getline(fin, line);
    istringstream iss(line);
    string data;
    while (iss >> data) {
      cout << left << setw(7) << data << " ";
    }
    cout << endl;
  }

  cout << setfill('-') << setw(40) << '-' << setfill(' ') << endl;  // Printing parting line

  fin.close();
}

Player LoadSave() {
  system("clear");
  PrintSaveStatus();

  int choice;
  cout << "Which save you want to load? (1-3)" << endl;
  cin >> choice;

  string line;

  while (true) {
    if (choice > 0 && choice < 4) {
      ifstream fin("../templates/save.txt");

      // Proceed and get the save slot
      for (int i = 0; i < choice + 1; ++i) {
        getline(fin, line);
      }

      fin.close();

      // If the save slot is occupied, load the save
      if (line.length() > 2) {
        /* This block need change if data structure of player change*/
        istringstream iss(line);
        string slot, name; 
        int level, score, lives;
        iss >> slot >> name >> level >> score >> lives; 
        cout << "Successfully load save " << slot << endl;
        Player player(name, level, score, lives); // constructor of player class
        return player;
      } 
      else {
        // Retry if the save is empty
        system("clear");
        PrintSaveStatus();
        cout << "Empty save. Please try again (1-3)" << endl;
        cin >> choice;
      }
    }
    else {
      // Retry if the save is invalid
      system("clear");
      PrintSaveStatus();
      cout << "Invalid save. Please try again (1-3)" << endl;
      cin >> choice;
    }
  }
}

void BuildSave(Player player) {
  system("clear");
  PrintSaveStatus();

  int choice;
  cout << "Which slot you want to save? (1-3)" << endl;
  cin >> choice;
  // Ensure the choice is valid
  while (choice < 1 || choice > 3) {
    cout << "Invalid choice. Please try again (1-3)" << endl;
    cin >> choice;
  }

  vector<string> temp;
  string line;

  // Store the existing save file into a vector
  ifstream fin("../templates/save.txt");  
  while (getline(fin, line)) {
    temp.push_back(line);
  }
  fin.close();

  // Extract the information of the player and store them into a line
  /* This block need change if data structure of player change*/
  string save = to_string(choice) + " ";
  save += player.getName() + " ";
  save += to_string(player.getLevel()) + " ";
  save += to_string(player.getScore()) + " ";
  save += to_string(player.getLives()) + " ";

  // Overwrite the existing save file
  ofstream fout("../templates/save.txt");
  for (int i = 0; i < 5; ++i) {
    if (i != choice)
      fout << temp[i] << endl;
    else
      fout << save << endl;
  }
  fout.close();
}