#pragma once

#define WALKABLE "-"
#define BLANK " "

#include "../../Objects/IObjects.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class Cell
{
private:
    int _x;
    int _y;
    IObjects *_currentObject;
    IControlable *_currentControlableObject;
    std::string _cellObjectSymbol;

    bool _isWalkable = true;

public:
    Cell(int, int);

    void checkObject(IObjects *);
    void setToBlankCell();
    std::string getCellObjectSymbol();
    IObjects *getCurrentObject();
    IObjects *getCurrentControlableObject();
    bool isWalkable();
    bool isBlocked();
};