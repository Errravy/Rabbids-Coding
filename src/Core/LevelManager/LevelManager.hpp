#pragma once

#include "../../Playspace/Level/Level.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Objects/Controlable/Rabbids/Rabbids.hpp"

#include "../../Command/MoveForward/MoveForward.hpp"
#include "../../Command/MoveBackward/MoveBackward.hpp"

class LevelManager
{
private:
    void setupLevels();

public:
    LevelManager();

    static Level *getLevel();
};