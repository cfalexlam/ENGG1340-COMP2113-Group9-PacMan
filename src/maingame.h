#ifndef MAIN_GAME
#define MAIN_GAME

#include <string>
// Perform all main game-related functions
class MainGame{
    public:
        // Run the main game loop
        MainGame(std::string playername);
        std::string plname;
        bool mainLoop();
};

#endif
