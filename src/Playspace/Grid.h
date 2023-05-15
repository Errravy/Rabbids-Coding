#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Cell.h"
#include "IObjects.h" // Assuming the header file for IObjects is included

class Grid
{
private:
    int temp = 0;
    int width;
    int height;
    std::string** grid;
    std::unordered_map<std::pair<int, int>, Cell*, CellHash> cells; // Assuming CellHash is a hash function for Cell's key

    Cell* previousCell;
    IObjects* previousObject;

    void InitializeGridAndCell(int width, int height);
    void GenerateGrid();

public:
    Grid(int width, int height);
    void CheckCell(IObjects* obj);
    void CheckGridPos(int x, int y);
    int GetWidth();
    int GetHeight();
    std::unordered_map<std::pair<int, int>, Cell*, CellHash>& GetCells();
};

#endif // GRID_H