#pragma once

#include <vector>

#include "../../Playspace/Level/Level.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Objects/Controlable/Rabbids/Rabbids.hpp"

#include "../../Command/MoveForward/MoveForward.hpp"
#include "../../Command/MoveBackward/MoveBackward.hpp"

#define LEVEL_FOLDER_PATH = "Levels"

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