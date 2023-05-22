#pragma once
#include<list.h>
#include "Rabbids-Coding/src/Playspace/Level.h"
#include "Rabbids-Coding/src/Core/LevelManager.h"
#include "FileHandler.hpp"
#include "Level.hpp"
#include "Invoker.hpp"
#include "Factory.hpp"
#include <vector>
#include <string>

class LevelManager {
private:
    std::vector<Level> levelList;
    int currentLevelIndex = 0;
    const std::string LEVEL_FOLDER_PATH = "Levels";

    struct LevelItem {
        std::string levelName;
        std::vector<std::string> commands;
        std::vector<Object> objects;
        std::vector<Position> blankCells;
        GridSize gridSize;

        struct Object {
            std::string objectType;
            std::string objectEnum;
            Position position;
        };

        struct Position {
            int x;
            int y;
        };

        struct GridSize {
            int width;
            int height;
        };
    };

public:
    LevelManager();
    Level GetLevel();
    void SetupLevels();
    void NextLevel();

private:
    void CreateLevel(const std::string& levelName);
    IObjects* CreateNewObject(const LevelItem::Object& objectItem, bool& isControlable);
    ICommand* CreateNewCommand(IControlable* controlable, const std::string& command);
    void SetObjectPosition(IObjects* object, const LevelItem::Position& position);
};

#endif  // LEVELMANAGER_HPP