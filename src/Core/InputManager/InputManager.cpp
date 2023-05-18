#include "InputManager.hpp"

InputManager::InputManager()
{
}

int InputManager::getMove()
{
    int move = 0;
    std::cin >> move;
    std::cin.get();
    return move;
}