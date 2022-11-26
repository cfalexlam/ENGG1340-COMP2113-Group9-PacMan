#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>

using namespace std;

class ScreenRenderer{
    public:
        void printLinesToScreen(string s);
        void printFile(const string& fileName);
        void printStartMenu();
        void printPauseMenu();
        void printRespawnCountdown();
        void printPlayerStatus(Player pl);
        void printLoseScreen(Player pl);

        string takeCmdInput(string message);
        void KeyboardModeOpen();
        void KeyboardModeWB();
        void KeyboardModeNB();
        void KeyboardModeClose();
        void KeyboardModePrint(string message);
};

#endif
