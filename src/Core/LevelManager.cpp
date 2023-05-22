#include "LevelManager.hpp"
#include "Level.hpp"
#include "Factory.hpp"
#include "Invoker.hpp"

LevelManager::LevelManager() 
{
    SetupLevels();
}

Level LevelManager::GetLevel()
{
    return levelList[currentLevelIndex];
}

void LevelManager::SetupLevels()
{
    std::vector<fs::path> filePaths = FileHandler::GetAllLevelFiles(LEVEL_FOLDER_PATH);

    for (const auto& filePath : filePaths) {
        std::string levelName = filePath.filename().string();
        CreateLevel(levelName);
    }
}

void LevelManager::CreateLevel(const std::string& levelName)
{
    LevelItem levelItem = FileHandler::ReadFromJson<LevelItem>(LEVEL_FOLDER_PATH + "/" + levelName);

    Invoker invoker;
    Level newLevel(levelItem.levelName, levelItem.gridSize.width, levelItem.gridSize.height, invoker);

    for (const auto& cell : levelItem.blankCells) {
        newLevel.GetGrid().GetCells()[{cell.x, cell.y}].SetToBlankCell();
    }

    for (const auto& objectItem : levelItem.objects) {
        bool isControlable = false;
        IObjects* newObject = CreateNewObject(objectItem, isControlable);

        if (isControlable) {
            for (const auto& command : levelItem.commands) {
                ICommand* iCommand = CreateNewCommand(static_cast<IControlable*>(newObject), command);
                static_cast<IControlable*>(newObject)->SetCommand(iCommand);
            }

            newLevel.SetControlable(static_cast<IControlable*>(newObject));
        }

        newLevel.GetGrid().CheckCell(newObject);
    }

    levelList.push_back(newLevel);
}

IObjects* LevelManager::CreateNewObject(const LevelItem::Object& objectItem, bool& isControlable) 
{
    IObjects* newObject = Factory::CreateObject(static_cast<Objects>(std::stoi(objectItem.objectType)));
    SetObjectPosition(newObject, objectItem.position);

    if (objectItem.objectEnum == "Controlable") isControlable = true;
    else isControlable = false;
    
    return newObject;
}

ICommand* LevelManager::CreateNewCommand(IControlable* controlable, const std::string& command) 
{
    ICommand* newCommand = Factory::CreateCommands(controlable, static_cast<Commands>(std::stoi(command)));
    return newCommand;
}

void LevelManager::SetObjectPosition(IObjects* object, const LevelItem::Position& position) 
{
    object->SetPosition(position.x, position.y);
}

void LevelManager::NextLevel() 
{
    currentLevelIndex++;
}