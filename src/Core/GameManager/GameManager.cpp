#include "GameManager.hpp"

GameManager *GameManager::Instance = nullptr;

GameManager::GameManager()
{
    if (Instance == nullptr)
    {
        Instance = this;
    }

    _gameState = GameStates::NotStarted;
    _currentLevel = LevelManager::getLevel();
}

void GameManager::startGame()
{
    _gameState = GameStates::Playing;

    DisplayManager::renderLevel(_currentLevel);
    while (_gameState == GameStates::Playing)
    {
        // _currentLevel->showAvailableMoves();
        int move = InputManager::getMove();

        if (move == 1)
        {
            // _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::CommandLeft));
        }
        else if (move == 2)
        {
            // _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::CommandRight));
        }
        else if (move == 3)
        {
            // _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::CommandForward));
        }
        else if (move == 4)
        {
            // _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::CommandBackward));
        }
        else if (move == 5)
        {
            // _currentLevel->getInvoker()->executeCommands();
        }

        if (_currentLevel->isCompleted())
        {
            endGame();
        }
    }
}

void GameManager::endGame()
{
    _gameState = GameStates::NotStarted;
}

void GameManager::loadLevel(Level *level)
{
    _currentLevel = level;
}
