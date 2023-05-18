#include "LevelManager.hpp"

LevelManager::LevelManager()
{
    setupLevels();
}

void LevelManager::setupLevels()
{
}

Level *LevelManager::getLevel()
{
    Level *newLevel = new Level("Level 1", 10, 10, new Invoker());
    IControlable *controlable = dynamic_cast<IControlable *>(new Rabbids());
    controlable->setPosition(5, 5);
    newLevel->setControlable(controlable);
    // newLevel->getGrid()->checkCell(controlable);
    return newLevel;
}