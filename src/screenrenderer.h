#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>

using namespace std;

class Player;

class ScreenRenderer {
    public:
        void keyboardModeOpen();
        void keyboardModeWB();
        void keyboardModeNB();
        void keyboardModeClose();
        void keyboardModePrint(string message);
        
        void printLoseScreen(Player player);
        void printWinScreen(Player player);
        void printRespawnCountdown();
};

#endif
