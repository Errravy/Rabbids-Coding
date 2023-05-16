#include "Cell.hpp"

Cell::Cell(int x, int y)
{
    _x = x;
    _y = y;
    _obj = nullptr;
    _cellObj = _walkable;
}

void Cell::checkObject(IObjects *obj)
{
    if (obj->getPosition().first == _x && obj->getPosition().second == _y)
    {
        _isWalkable = false;
        std::cout << "Cell " << _x << " " << _y << " is not walkable because " << obj << " inside it!" << std::endl;
        _obj = obj;
        _cellObj = obj->getObjectSymbol();
    }
    else
    {
        _isWalkable = true;
        _obj = nullptr;
        _cellObj = _walkable;
    }
}

void Cell::setToBlankCell()
{
    _isWalkable = false;
    _cellObj = _blank;
}

std::string Cell::getCellObj()
{
    return _cellObj;
}

IObjects *Cell::getObject()
{
    return _obj;
}

bool Cell::isWalkable()
{
    return isWalkable;
}

bool Cell::isBlocked()
{
    return _cellObj == _blank;
}
