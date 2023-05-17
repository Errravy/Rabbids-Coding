#pragma once

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "../../Objects/IObjects.hpp"

class Cell
{
private:
    int _x;
    int _y;
    IObjects *_obj;
    std::string _cellObj;

    bool _isWalkable = true;
    const std::string _walkable = "-";
    const std::string _blank = " ";

public:
    Cell(int x, int y);
    void checkObject(IObjects *obj);
    void setToBlankCell();
    std::string getCellObj();
    IObjects *getObject();
    bool isWalkable();
    bool isBlocked();
};

#endif
