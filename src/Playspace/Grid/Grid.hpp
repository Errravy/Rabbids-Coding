#pragma once

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "../Cell/Cell.hpp"
#include "../../Objects/IObjects.hpp" // Assuming the header file for IObjects is included

class Grid
{
private:
    int _temp = 0;
    int _width;
    int _height;
    std::string grid[10][10];
    std::unordered_map<std::pair<int, int>, Cell *> cells; // Assuming CellHash is a hash function for Cell's key

    Cell *previousCell;
    IObjects *previousObject;

    void initializeGridAndCell(int, int);
    void generateGrid();

public:
    Grid(int, int);
    void checkCell(IObjects *);
    void checkGridPos(int, int);
    int getWidth();
    int getHeight();
    std::unordered_map<std::pair<int, int>, Cell *> &getCells();
};

#endif
