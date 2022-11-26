#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>

using namespace std;

class Board;
class Player;

class ScreenRenderer{
    public:
        void printLinesToScreen(string s);
        void printFile(const string& fileName);
        void printStartMenu();
        void printPauseMenu();
        void printRespawnCountdown();
        void printMaze(Board b);
        void printPlayerStatus(Player p);

        string takeCmdInput(string message);
        void KeyboardModeOpen();
        void KeyboardModeWB();
        void KeyboardModeNB();
        void KeyboardModeClose();
        void KeyboardModePrint(string message);
};

#endif
