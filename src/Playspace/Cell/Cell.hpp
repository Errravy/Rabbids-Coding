#pragma once

#define WALKABLE "-"
#define BLANK " "

#include "../../Objects/IObjects.hpp"

class Cell
{
private:
    int _x;
    int _y;
    IObjects *_obj;
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