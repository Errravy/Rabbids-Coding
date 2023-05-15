#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GameState.h"
#include "Level.h"
#include "LevelManager.h"
#include "DisplayManager.h"
#include "InputManager.h"

class GameManager {
public:
    static GameManager* Instance;
    GameState gameState;
    Level* currentLevel;

    GameManager();

    void StartGame();

    void EndGame();

    void LoadLevel(Level* level);
};

#endif // GAME_MANAGER_H
