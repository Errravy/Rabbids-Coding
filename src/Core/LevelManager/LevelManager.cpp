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
    std::vector<fs::path> filePaths = FileHandler::getAllFilesInDirectory("Levels");
    for (auto &&file : filePaths)
    {
        std::string fileNameWithoutExtension = file.stem().string();
        createLevel(fileNameWithoutExtension);
    }
}

void LevelManager::createLevel(const std::string &levelName)
{
    LevelManager::LevelData levelData = FileHandler::readFromJson<LevelManager::LevelData>("Levels/" + levelName + ".json");
    std::cout << levelData._levelName << std::endl;

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

void to_json(json &j, const LevelManager::LevelData &levelData)
{
    j = json{
        {"levelName", levelData._levelName},
    };
}

void from_json(const json &j, LevelManager::LevelData &levelData)
{
    j.at("levelName").get_to(levelData._levelName);
    j.at("gridSize").at("width").get_to(levelData._gridSize._width);
    j.at("gridSize").at("height").get_to(levelData._gridSize._height);

    std::cout << levelData._levelName << std::endl;

    for (const auto &command : j.at("commands"))
    {
        levelData._commands.push_back(command);
    }

    for (const auto &object : j.at("objects"))
    {
        LevelManager::LevelData::Object newObject;
        object.at("objectType").get_to(newObject._objectType);
        object.at("objectEnum").get_to(newObject._objectEnum);
        object.at("position").at("x").get_to(newObject._position._x);
        object.at("position").at("y").get_to(newObject._position._y);
        levelData._objects.push_back(newObject);
    }

    for (const auto &blankCell : j.at("blankCells"))
    {
        LevelManager::LevelData::Position newPosition;
        blankCell.at("x").get_to(newPosition._x);
        blankCell.at("y").get_to(newPosition._y);
        levelData._blankCells.push_back(newPosition);
    }
}