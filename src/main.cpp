#include <iostream>
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
      Maingame game(playername);
      game.mainloop();
    }
    if (command=="r") //show rule
      
  }
  while (command!="q");
  return 1;
}

void printStartMenu() {
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

string takeCmdInput(string message) {
    cout << message << endl;
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
