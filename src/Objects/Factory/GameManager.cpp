#include "GameManager.h"

GameManager* GameManager::Instance = nullptr;

GameManager::GameManager() {
    if (Instance == nullptr) {
        Instance = this;
    }

    gameState = GameState::NotStarted;
    currentLevel = LevelManager::GetLevel();
}

void GameManager::StartGame() {
    gameState = GameState::Playing;

    while (gameState == GameState::Playing) {
        DisplayManager::RenderLevel(currentLevel);
        currentLevel->ShowAvailableMoves();
        int move = InputManager::GetMove();

        if (move == 1) {
            currentLevel->GetInvoker()->AddCommand(currentLevel->GetControlable()->GetCommand(Commands::Left));
        }
        else if (move == 2) {
            currentLevel->GetInvoker()->AddCommand(currentLevel->GetControlable()->GetCommand(Commands::Right));
        }
        else if (move == 3) {
            currentLevel->GetInvoker()->AddCommand(currentLevel->GetControlable()->GetCommand(Commands::Forward));
        }
        else if (move == 4) {
            currentLevel->GetInvoker()->AddCommand(currentLevel->GetControlable()->GetCommand(Commands::Backward));
        }
        else if (move == 5) {
            currentLevel->GetInvoker()->ExecuteCommands();
        }

        if (currentLevel->IsCompleted()) {
            EndGame();
        }
    }
}

void GameManager::EndGame() {
    gameState = GameState::NotStarted;
}

void GameManager::LoadLevel(Level* level) {
    currentLevel = level;
}
