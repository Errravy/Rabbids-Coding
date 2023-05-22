#include "GameManager.hpp"

GameManager::GameManager()
{
    _levelManager = new LevelManager();
    _gameState = GameStates::NotStarted;
}

void GameManager::startGame()
{
    std::cout << "Select level: " << std::endl;
    for (int i = 0; i < _levelManager->getLevelNames().size(); i++)
    {
        std::cout << i + 1 << ". " << _levelManager->getLevelNames()[i] << std::endl;
    }

    int levelIndex = InputManager::getLevelIndex(_levelManager->getLevelNames().size());
    loadLevel(_levelManager->getLevel(levelIndex - 1));

    playGame();
}

void GameManager::playGame()
{
    _gameState = GameStates::Playing;

    while (_gameState == GameStates::Playing)
    {
        DisplayManager::renderLevel(_currentLevel);
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
