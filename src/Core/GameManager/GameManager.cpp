#include "GameManager.hpp"

GameManager::GameManager()
{
    _levelManager = new LevelManager();
    _gameState = GameStates::NotStarted;
    _currentLevel = _levelManager->getLevel();
}

void GameManager::startGame()
{
    _gameState = GameStates::Playing;

    while (_gameState == GameStates::Playing)
    {
        // DisplayManager::renderLevel(_currentLevel);
        // _currentLevel->showAvailableMoves();
        int move = InputManager::getMove();

        if (move == 1)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Left));
        }
        else if (move == 2)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Right));
        }
        else if (move == 3)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Forward));
        }
        else if (move == 4)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Backward));
        }
        else if (move == 5)
        {
            _currentLevel->getInvoker()->executeCommands();
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
