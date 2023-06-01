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
    IObjects *_obj;
    IControlable* _cobj;
    std::string _cellObj;

    bool _isWalkable = true;

public:
    Cell(int, int);

    void checkObject(IObjects *);
    void setToBlankCell();
    std::string getCellObj();
    IObjects *getObject();
    bool isWalkable();
    bool isBlocked();
};