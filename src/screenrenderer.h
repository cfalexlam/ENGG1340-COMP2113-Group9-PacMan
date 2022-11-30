#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>


class Player;

class ScreenRenderer{
    public:
        void keyboardModeOpen();
        void keyboardModeWB();
        void keyboardModeNB();
        void keyboardModeClose();
        void keyboardModePrint(std::string message);
        
        void printLoseScreen(Player pl);
        void printWinScreen(Player pl);
        void printRespawnCountdown();

        std::string takeCmdInput(std::string promptMessage);
};

#endif
