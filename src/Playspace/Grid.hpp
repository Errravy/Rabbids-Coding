#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <string>
#include <unordered_map>
#include "Cell.hpp"
#include "IObjects.hpp" // Assuming the header file for IObjects is included

class Grid
{
private:
    int _temp = 0;
    int _width;
    int _height;
    std::string grid;
    std::unordered_map<std::pair<int, int>, Cell *, CellHash> cells; // Assuming CellHash is a hash function for Cell's key

    Cell *previousCell;
    IObjects *previousObject;

    void initializeGridAndCell(int width, int height);
    void generateGrid();

public:
    Grid(int width, int height);
    void checkCell(IObjects *obj);
    void checkGridPos(int x, int y);
    int getWidth();
    int getHeight();
    std::unordered_map<std::pair<int, int>, Cell *, CellHash> &getCells();
};

#endif /* Grid_h */
