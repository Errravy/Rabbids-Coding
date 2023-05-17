#include "GameManager.hpp"

GameManager *GameManager::Instance = nullptr;

GameManager::gameManager()
{
    if (Instance == nullptr)
    {
        Instance = this;
    }

    gameState = GameState::NotStarted;
    currentLevel = LevelManager::getLevel();
}

void GameManager::startGame()
{
    gameState = GameState::Playing;

    while (gameState == GameState::Playing)
    {
        DisplayManager::renderLevel(currentLevel);
        currentLevel->showAvailableMoves();
        int move = InputManager::getMove();

        if (move == 1)
        {
            currentLevel->getInvoker()->addCommand(currentLevel->getControlable()->getCommand(Commands::Left));
        }
        else if (move == 2)
        {
            currentLevel->getInvoker()->addCommand(currentLevel->getControlable()->getCommand(Commands::Right));
        }
        else if (move == 3)
        {
            currentLevel->getInvoker()->addCommand(currentLevel->getControlable()->getCommand(Commands::Forward));
        }
        else if (move == 4)
        {
            currentLevel->getInvoker()->addCommand(currentLevel->getControlable()->getCommand(Commands::Backward));
        }
        else if (move == 5)
        {
            currentLevel->getInvoker()->executeCommands();
        }

        if (currentLevel->isCompleted())
        {
            endGame();
        }
    }
}

void GameManager::endGame()
{
    gameState = GameState::NotStarted;
}

void GameManager::loadLevel(Level *level)
{
    currentLevel = level;
}
