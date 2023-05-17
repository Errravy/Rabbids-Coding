#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// #include "Level.h"
#include "../LevelManager/LevelManager.hpp"
#include "../InputManager/InputManager.hpp"
#include "../../Enums/GameState.hpp"
// #include "../../DisplayManager/DisplayManager.hpp"

class GameManager
{
private:
    GameState gameState;
    // Level *currentLevel;

public:
    static GameManager *Instance;

    GameManager();

    void startGame();

    void endGame();

    // void loadLevel(Level *level);
};

#endif // GAME_MANAGER_H
