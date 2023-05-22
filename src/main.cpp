#include <iostream>

#include "Core/GameManager/GameManager.hpp"

int main()
{
	std::cout << "===== Welcome to Rabbids Coding lite =====" << std::endl;
	std::cout << "=====  Press any key to start game   =====" << std::endl;
	std::cin.get();

	GameManager *gameManager = new GameManager();
	gameManager->startGame();
}