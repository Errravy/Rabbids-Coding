#pragma once
#include "Grid.h"
#include "Rabbids-Coding/Command/Invoker.h"
#include "Rabbids-Coding/Object/ControllableObject.h"

class Level {
    Grid grid;
    Invoker invoker;
    ControllableObject controllable;

public :
    Level(Invoker& const);

    Grid GetGrid();

    Invoker GetInvoker();

    void ShowAvailableMoves();

    bool isCompleted();

    void SetControllable(ControllableObject& const controllable);

    ControllableObject GetControllable();

}
