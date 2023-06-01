#pragma once

#include <iostream>
#include <map>

#include "../../Objects/IObjects.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../Cell/Cell.hpp"

class Grid
{
private:
    int _width;
    int _height;
    std::map<std::pair<int, int>, Cell *> _cells;
    Cell *_previousCell;
    IObjects *_previousObject;

    void initializeGridAndCell(int, int);
    void generateGrid();
    void checkControlableObject(IObjects* obj);

public:
    Grid(int, int);

    void checkCell(IObjects *);
    int getWidth();
    int getHeight();
    std::map<std::pair<int, int>, Cell *> getCells();
};