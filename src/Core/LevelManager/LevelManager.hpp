#pragma once

#include <vector>
#include <filesystem>

#include "../../FileSystem/FileHandler.hpp"

#include "../../Playspace/Level/Level.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Objects/Controlable/Rabbids/Rabbids.hpp"

#include "../../Command/MoveForward/MoveForward.hpp"
#include "../../Command/MoveBackward/MoveBackward.hpp"

#define LEVEL_FOLDER_PATH = "Levels"

namespace fs = std::filesystem;
namespace LD
{
    struct LevelData
    {
        struct GridSize
        {
            int _width;
            int _height;
        };

        struct Position
        {
            int _x;
            int _y;
        };

        struct Object
        {
            std::string _objectType;
            std::string _objectEnum;
            Position _position;
        };

        std::string _levelName;
        std::vector<std::string> _commands;
        std::vector<Object> _objects;
        std::vector<Position> _blankCells;
        GridSize _gridSize;
    };
};

class LevelManager
{
public:
    LevelManager();

    Level *getLevel();

private:
    std::vector<Level *> _levels;
    int _currentLevelIndex;

    void setupLevels();
    void createLevel(const std::string &);
    std::pair<IObjects *, bool> createNewObject();
    ICommand *createNewCommand(IControlable *, const std::string &);
    void setObjectPosition(IObjects *);
};