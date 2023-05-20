#include "LevelManager.hpp"

LevelManager::LevelManager()
{
    setupLevels();
}

Level *LevelManager::getLevel()
{
    return _levels[_currentLevelIndex];
}

void LevelManager::setupLevels()
{
    fs::path path = FileHandler::getRelativePath("Levels");
    createLevel("Level 1");
}

void LevelManager::createLevel(const std::string &levelName)
{
    Level *newLevel = new Level(levelName, 10, 10, new Invoker());
    IControlable *controlable = dynamic_cast<IControlable *>(new Rabbids());
    controlable->setPosition(5, 5);
    controlable->setCommand(new MoveForward(controlable));
    controlable->setCommand(new MoveBackward(controlable));

    newLevel->setControlable(controlable);
    newLevel->getGrid()->checkCell(controlable);

    _levels.push_back(newLevel);
}

std::pair<IObjects *, bool> LevelManager::createNewObject()
{
    return std::make_pair(nullptr, false);
}

ICommand *LevelManager::createNewCommand(IControlable *controlable, const std::string &command)
{
    return nullptr;
}

void LevelManager::setObjectPosition(IObjects *object)
{
}