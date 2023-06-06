#include "Grid.hpp"

Grid::Grid(int width, int height)
{
    initializeGridAndCell(width, height);
    generateGrid();
}

void Grid::initializeGridAndCell(int width, int height)
{
    _width = width;
    _height = height;
    _cells = std::map<std::pair<int, int>, Cell *>();
}

void Grid::generateGrid()
{
    for (int x = 0; x < _width; x++)
    {
        for (int y = 0; y < _height; y++)
        {
            _cells.insert(std::make_pair(std::make_pair(x, y), new Cell(x, y)));
        }
    }
}

void Grid::checkCell(IObjects *obj)
{
    if (IControlable *controlable = dynamic_cast<IControlable *>(obj))
    {
        checkControlableObject(controlable);
    }

    if (obj->getPosition().first < _width && obj->getPosition().second < _height)
    {
        _cells[obj->getPosition()]->checkObject(obj);
    }
    else
    {
        std::cout << "Object is out of grid!" << std::endl;
    }
}

void Grid::checkControlableObject(IObjects *obj)
{
    if (_previousCell == nullptr)
    {
        _previousCell = _cells[obj->getPosition()];
        _previousObject = obj;
    }
    else
    {
        if (_previousCell->getCurrentObject() != nullptr)
            _previousCell->checkObject(_previousCell->getCurrentObject());
        else
            _previousCell->checkObject(_previousObject);

        _previousCell = _cells[obj->getPosition()];
        _previousObject = obj;
    }
}
int Grid::getWidth()
{
    return _width;
}

int Grid::getHeight()
{
    return _height;
}

std::map<std::pair<int, int>, Cell *> Grid::getCells()
{
    return _cells;
}