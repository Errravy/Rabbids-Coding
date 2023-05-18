#pragma once

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
    Cell(int, int);

    void checkObject(IObjects *);
    void setToBlankCell();
    std::string getCellObj();
    IObjects *getObject();
    bool isWalkable();
    bool isBlocked();
};