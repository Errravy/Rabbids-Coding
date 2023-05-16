#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "IObjects.h"

class Cell
{
private:
    int x;
    int y;
    IObjects* obj;
    std::string cellObj;

    bool isWalkable = true;
    static const std::string walkable;
    static const std::string blank;

public:
    Cell(int x, int y);
    void checkObject(IObjects* obj);
    void setToBlankCell();
    std::string getCellObj();
    IObjects* getObject();
    bool isWalkable();
    bool isBlocked();
};

#endif // CELL_H
