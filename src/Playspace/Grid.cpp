#include "Grid.h"

// Constructor
Grid::Grid(int width, int height)
{
    initializeGridAndCell(width, height);
    generateGrid();
}

// Private methods
void Grid::initializeGridAndCell(int width, int height)
{
    this->width = width;
    this->height = height;
    grid = new std::string*[width];
    for (int x = 0; x < width; x++)
    {
        grid[x] = new std::string[height];
    }
}

void Grid::generateGrid()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            temp++;
            grid[x][y] = std::to_string(temp);
            cells[std::make_pair(x, y)] = new Cell(x, y);
        }
    }
}

// Public methods
void Grid::checkCell(IObjects* obj)
{
    if (previousCell == nullptr)
    {
        previousCell = cells[obj->getPosition()];
        previousObject = obj;
    }
    else
    {
        previousCell->checkObject(previousObject);
        previousCell = cells[obj->getPosition()];
        previousObject = obj;
    }

    std::pair<int, int> position = obj->getPosition();
    if (position.first < width && position.second < height)
    {
        cells[position]->checkObject(obj);
    }
    else
    {
        std::cout << "Object is out of grid!" << std::endl;
    }
}

void Grid::checkGridPos(int x, int y)
{
    std::cout << grid[x][y] << std::endl;
}

int Grid::getWidth()
{
    return width;
}

int Grid::getHeight()
{
    return height;
}

std::unordered_map<std::pair<int, int>, Cell*, CellHash>& Grid::getCells()
{
    return cells;
}
