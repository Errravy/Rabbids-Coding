#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "IObjects.h" // Assuming the header file for IObjects is included

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
    void CheckObject(IObjects* obj);
    void SetToBlankCell();
    std::string GetCellObj();
    IObjects* GetObject();
    bool IsWalkable();
    bool IsBlocked();
};

#endif // CELL_H
