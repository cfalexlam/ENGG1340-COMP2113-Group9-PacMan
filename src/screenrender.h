#ifndef SCREENRENDERER_H
#define SCREENRENDERER_H

#include <string>

class Board;
class Player;

class ScreenRenderer{
    public:
        void printLinesToScreen(string s);
        void printStartMenu();
        void printPauseMenu();
        void printRespawnCountdown();
        void printMaze(Board b);
        void printPlayerStatus(Player p);

        void takeCmdInput(string s);
        void KeyboardMode();
        void CmdMode();
};

#endif
