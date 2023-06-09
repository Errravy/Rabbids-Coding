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

    int _score = 0;
    bool _isCompleted = false;

public:
    Level(std::string, int, int, Invoker *);

    void showAvailableMoves();
    Grid *getGrid();
    std::string getLevelName();
    int getScore();
    Invoker *getInvoker();
    IControlable *getControlable();
    void setControlable(IControlable *);
    void setObjective(IObjective *);
    bool isCompleted();
    void setCompleted(bool);
};