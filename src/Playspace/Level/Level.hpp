#pragma once

#include "../Grid/Grid.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Command/Invoker/Invoker.hpp"

class Level
{
private:
    std::string _levelName;
    Grid *_grid;
    Invoker *_invoker;
    IControlable *_controlable;

    bool _isCompleted = false;

public:
    Level(std::string, int, int, Invoker *);

    Grid *getGrid();
    std::string getLevelName();
    Invoker *getInvoker();
    IControlable *getControlable();
    void setControlable(IControlable *);
    bool isCompleted();
};