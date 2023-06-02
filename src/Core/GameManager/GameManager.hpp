#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include "../LevelManager/LevelManager.hpp"
#include "../InputManager/InputManager.hpp"

#include "../../Enum/GameStates.hpp"
#include "../../Enum/Commands.hpp"

#include "../../Playspace/Level/Level.hpp"
#include "../../UI/DisplayManager.hpp"

using namespace std::chrono_literals;

class GameManager
{
private:
    LevelManager *_levelManager;
    GameStates _gameState;
    Level *_currentLevel;

public:
    GameManager();

    void startGame();
    void playGame();
    void endGame();
    void loadLevel(Level *);
};
