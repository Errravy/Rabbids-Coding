#ifndef LEVEL_H
#define LEVEL_H

#include "../Grid/Grid.h"
#include "../../Command/Invoker/Invoker.h"
#include "../../Objects/Controlable/IControlable.h"

class Level
{
private:
    Grid grid;
    Invoker invoker;
    IControlable* controlable;
    bool isCompleted;

public:
    Level(Invoker invoker);
    Grid& GetGrid();
    Invoker& GetInvoker();
    void ShowAvailableMoves();
    bool IsCompleted();
    void SetControlable(IControlable* controlable);
    IControlable* GetControlable();
};

#endif // LEVEL_H
