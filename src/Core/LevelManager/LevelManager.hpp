#pragma once

#include <vector>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "../../FileSystem/FileHandler.hpp"

#include "../../Playspace/Grid/Grid.hpp"

#include "../../Factory/Factory.hpp"
#include "../../Enum/Converter/Converter.hpp"

#include "../../Playspace/Level/Level.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Objects/Controlable/Rabbids/Rabbids.hpp"

#include "../../Command/MoveForward/MoveForward.hpp"
#include "../../Command/MoveBackward/MoveBackward.hpp"

#include "../../Objective/IObjective.hpp"

#define LEVEL_FOLDER_PATH = "Levels"

using json = nlohmann::json;
namespace fs = std::filesystem;

class LevelManager
{
public:
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

        struct Objective
        {
            std::string _objectiveEnum;
            Position _position;
        };

        std::string _levelName;
        std::vector<std::string> _commands;
        std::vector<Object> _objects;
        std::vector<Position> _blankCells;
        GridSize _gridSize;
        Objective _objective;

        friend void from_json(const json &, LevelData &);
    };

    LevelManager();

    Level *getLevel(int);
    std::vector<std::string> getLevelNames();
    void showAvailableLevels();

private:
    std::vector<Level *> _levels;
    int _currentLevelIndex;

    void setupLevels();
    void createNewLevel(const std::string &);
    std::pair<IObjects *, bool> createNewObject(const LevelManager::LevelData::Object &);
    ICommand *createNewCommand(IControlable *, const std::string &, Grid *);
    IObjective *createNewObjective(IControlable *, const LevelManager::LevelData::Objective &);
    void setObjectPosition(IObjects *, const LevelManager::LevelData::Position &);
};