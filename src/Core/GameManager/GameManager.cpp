#include "GameManager.hpp"

GameManager::GameManager()
{
    _levelManager = new LevelManager();
    _gameState = GameStates::NotStarted;
}

void GameManager::startGame()
{
    _levelManager->showAvailableLevels();
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
        _currentLevel->showAvailableMoves();
        int move = InputManager::getMove();

        if (move == 1)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Forward));
        }
        else if (move == 2)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Backward));
        }
        else if (move == 3)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Left));
        }
        else if (move == 4)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Right));
        }
        else if (move == 5)
        {
            _currentLevel->getInvoker()->addCommand(_currentLevel->getControlable()->getCommand(Commands::Interact));
        }
        else if (move == 9)
        {
            bool isObjectiveComplete = _currentLevel->getInvoker()->executeCommands();

            if (isObjectiveComplete)
            {
                DisplayManager::renderLevel(_currentLevel);
                std::this_thread::sleep_for(800ms);

                _currentLevel->setCompleted(true);
            }
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
    std::cout << "Congratulations! You have completed the level!" << std::endl;
    DataPersistence::getInstance()->saveGame(_currentLevel);
}

void GameManager::loadLevel(Level *level)
{
    _currentLevel = level;
}
