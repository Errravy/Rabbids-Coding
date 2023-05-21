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

    Invoker *invoker = new Invoker();
    Level *newLevel = new Level(levelData._levelName, levelData._gridSize._width, levelData._gridSize._height, invoker);

    for (const auto &cell : levelData._blankCells)
    {
        newLevel->getGrid()->getCells()[std::make_pair(cell._x, cell._y)]->setToBlankCell();
    }

    for (const auto &objectItem : levelData._objects)
    {
        // std::pair<IObjects *, bool> objectPair = createNewObject(objectItem);

        // IObjects *newObject = objectPair.first;
        // std::cout << "Created: " << newObject->getObjectSymbol() << std::endl;
        // bool isControlable = objectPair.second;

        // if (isControlable)
        // {
        //     for (const auto &command : levelData._commands)
        //     {
        //         // ICommand *iCommand = createNewCommand(static_cast<IControlable *>(newObject), command);
        //         // static_cast<IControlable *>(newObject)->setCommand(iCommand);
        //     }

        //     newLevel->setControlable(static_cast<IControlable *>(newObject));
        // }

        // newLevel->getGrid()->checkCell(newObject);
    }

    _levels.push_back(newLevel);
}

std::pair<IObjects *, bool> LevelManager::createNewObject(const LevelManager::LevelData::Object &objectItem)
{
    std::cout << "Created new object: " << objectItem._objectType << std::endl;
    IObjects *newObject = Factory::createObject(static_cast<Objects>(std::stoi(objectItem._objectType)));
    setObjectPosition(newObject, objectItem._position);

    if (objectItem._objectEnum == "Controlable")
        return std::make_pair(newObject, true);
    else
        return std::make_pair(newObject, false);
}

ICommand *LevelManager::createNewCommand(IControlable *controlable, const std::string &command)
{
    std::cout << "Created new command: " << command << std::endl;
    ICommand *newCommand = Factory::createCommand(controlable, static_cast<Commands>(std::stoi(command)));
    return newCommand;
    return nullptr;
}

void LevelManager::setObjectPosition(IObjects *object, const LevelManager::LevelData::Position &position)
{
    std::cout << "Set object position: " << position._x << " " << position._y << std::endl;
    object->setPosition(position._x, position._y);
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