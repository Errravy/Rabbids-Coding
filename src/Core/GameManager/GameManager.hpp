#pragma once

#include <iostream>

#include "../LevelManager/LevelManager.hpp"
#include "../InputManager/InputManager.hpp"

#include "../../Enum/GameStates.hpp"
#include "../../Enum/Commands.hpp"

#include "../../Playspace/Level/Level.hpp"
#include "../../UI/DisplayManager.hpp"

class GameManager
{
private:
    GameStates _gameState;
    Level *_currentLevel;

public:
    GameManager();

    void startGame();
    void endGame();
    void loadLevel(Level *);
};
