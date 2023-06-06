#include "InputManager.hpp"

int InputManager::getMove()
{
    int move = 0;
    std::cout << "Enter move: ";
    std::cin >> move;
    std::cin.get();
    return move;
}

int InputManager::getLevelIndex(int maxLevelIndex)
{
    int levelIndex = 0;
    std::cout << "Enter level: ";
    std::cin >> levelIndex;
    std::cin.get();

    while (levelIndex < 1 || levelIndex > maxLevelIndex)
    {
        std::cout << "Invalid level index. Please try again: " << std::endl;
        std::cin >> levelIndex;
        std::cin.get();
    }

    return levelIndex;
}
