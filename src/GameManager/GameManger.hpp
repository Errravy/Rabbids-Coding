#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Enums/GameState.hpp"
#include "Level.h"
#include "LevelManager.h"
#include "../DisplayManager/DisplayManager.hpp"
#include "InputManager.h"

class GameManager {
public:
    static GameManager* Instance;
    GameState gameState;
    Level* currentLevel;

    GameManager();

    void startGame();

    void endGame();

    void loadLevel(Level* level);
};

#endif // GAME_MANAGER_H
