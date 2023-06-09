#include "LevelManager.hpp"

LevelManager::LevelManager()
{
    setupLevels();
}

void LevelManager::showAvailableLevels()
{
    std::cout << "Select level: " << std::endl;
    for (int i = 0; i < getLevelNames().size(); i++)
    {
        std::cout << i + 1 << ". " << getLevelNames()[i] << std::endl;
    }
}

Level *LevelManager::getLevel(int levelIndex)
{
    return _levels[levelIndex];
}

std::vector<std::string> LevelManager::getLevelNames()
{
    std::vector<std::string> levelNames;
    for (auto &&level : _levels)
    {
        levelNames.push_back(level->getLevelName());
    }
    return levelNames;
}

void LevelManager::setupLevels()
{
    std::vector<fs::path> filePaths = FileHandler::getAllFilesInDirectory("Levels");
    for (auto &&file : filePaths)
    {
        std::string fileNameWithoutExtension = file.stem().string();
        createNewLevel(fileNameWithoutExtension);
    }
}

void LevelManager::createNewLevel(const std::string &levelName)
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
        std::pair<IObjects *, bool> objectPair = createNewObject(objectItem);

        IObjects *newObject = objectPair.first;
        bool isControlable = objectPair.second;

        if (isControlable)
        {
            for (const auto &command : levelData._commands)
            {
                ICommand *iCommand = createNewCommand(static_cast<IControlable *>(newObject), command, newLevel->getGrid());
                static_cast<IControlable *>(newObject)->setCommand(iCommand);
            }

            newLevel->setControlable(static_cast<IControlable *>(newObject));

            IObjective *objective = createNewObjective(static_cast<IControlable *>(newObject), levelData._objective);
            newLevel->setObjective(objective);
        }

        newLevel->getGrid()->checkCell(newObject);
    }

    _levels.push_back(newLevel);
}

std::pair<IObjects *, bool> LevelManager::createNewObject(const LevelManager::LevelData::Object &objectItem)
{
    IObjects *newObject = Factory::createObject(Converter::convertStringToObjects(objectItem._objectType));
    setObjectPosition(newObject, objectItem._position);

    if (objectItem._objectEnum == "Controlable")
        return std::make_pair(newObject, true);
    else
        return std::make_pair(newObject, false);
}

ICommand *LevelManager::createNewCommand(IControlable *controlable, const std::string &command, Grid *grid)
{
    ICommand *newCommand = Factory::createCommand(controlable, Converter::convertStringToCommands(command), grid);
    return newCommand;
    return nullptr;
}

IObjective *LevelManager::createNewObjective(IControlable *controlable, const LevelManager::LevelData::Objective &objective)
{
    IObjective *newObjective = Factory::createObjective(static_cast<IControlable *>(controlable), Converter::convertStringToObjectives(objective._objectiveEnum), objective._position._x, objective._position._y);
    return newObjective;
}

void LevelManager::setObjectPosition(IObjects *object, const LevelManager::LevelData::Position &position)
{
    object->setPosition(position._x, position._y);
}

void from_json(const json &j, LevelManager::LevelData &levelData)
{
    j.at("levelName").get_to(levelData._levelName);
    j.at("gridSize").at("width").get_to(levelData._gridSize._width);
    j.at("gridSize").at("height").get_to(levelData._gridSize._height);

    j.at("objective").at("objectiveEnum").get_to(levelData._objective._objectiveEnum);
    j.at("objective").at("position").at("x").get_to(levelData._objective._position._x);
    j.at("objective").at("position").at("y").get_to(levelData._objective._position._y);

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