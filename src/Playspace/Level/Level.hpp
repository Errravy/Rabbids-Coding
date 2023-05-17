#ifndef LEVEL_H
#define LEVEL_H

#include "../Grid/Grid.hpp"
#include "../../Command/Invoker/Invoker.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class Level
{
private:
    Grid grid;
    Invoker invoker;
    IControlable* controlable;
    bool isCompleted;

public:
    Level(Invoker invoker);
    Grid& getGrid();
    Invoker& getInvoker();
    void showAvailableMoves();
    bool isCompleted();
    void setControlable(IControlable* controlable);
    IControlable* getControlable();
};

#endif // LEVEL_H
