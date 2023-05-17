#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <map>
#include "../Cell/Cell.hpp"
#include "../../Objects/IObjects.hpp"

class Grid {
private:
    int width;
    int height;
    std::string** grid;
    std::map<std::pair<int, int>, Cell*> cells;

    Cell* previousCell;
    IObjects* previousObject;

public:
    Grid(int width, int height);
    void InitializeGridAndCell(int width, int height);
    void GenerateGrid();
    void CheckCell(IObjects* obj);
    void CheckGridPos(int x, int y);
    int GetWidth();
    int GetHeight();
    std::map<std::pair<int, int>, Cell*> GetCells();
};

#endif // GRID_H
