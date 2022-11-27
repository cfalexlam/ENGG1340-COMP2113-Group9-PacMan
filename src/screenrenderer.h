#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>

using namespace std;

class Player;

class ScreenRenderer{
    public:
        void KeyboardModeOpen();
        void KeyboardModeWB();
        void KeyboardModeNB();
        void KeyboardModeClose();
        void KeyboardModePrint(string message);
        
        void printLoseScreen(Player pl);
        void printWinScreen(Player pl);
        void printRespawnCountdown();
};

#endif
