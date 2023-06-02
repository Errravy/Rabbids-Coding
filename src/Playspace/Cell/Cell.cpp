#include "Cell.hpp"

Cell::Cell(int x, int y)
{
    _x = x;
    _y = y;
    _currentObject = nullptr;
    _cellObjectSymbol = WALKABLE;
}

void Cell::checkObject(IObjects *obj)
{
    if (IControlable *controlable = dynamic_cast<IControlable *>(obj))
    {
        if (controlable->getPosition().first == _x && controlable->getPosition().second == _y)
        {
            _isWalkable = false;
            _currentControlableObject = controlable;
            _cellObjectSymbol = controlable->getObjectSymbol();
        }
        else
        {
            _isWalkable = true;
            _currentControlableObject = nullptr;
            _cellObjectSymbol = WALKABLE;
        }
    }
    else if (obj == nullptr)
        return;
    else
    {
        if (obj->getPosition().first == _x && obj->getPosition().second == _y)
        {
            _isWalkable = false;
            _currentObject = obj;
            _currentControlableObject = nullptr;
            _cellObjectSymbol = obj->getObjectSymbol();
        }
        else
        {
            _isWalkable = true;
            _currentObject = nullptr;
            _currentControlableObject = nullptr;
            _cellObjectSymbol = WALKABLE;
        }
    }
}

void Cell::setToBlankCell()
{
    _isWalkable = false;
    _cellObjectSymbol = BLANK;
}

void Cell::setToFinishLine()
{
    _cellObjectSymbol = FINISHLINE;
}

std::string Cell::getCellObjectSymbol()
{
    return _cellObjectSymbol;
}

IObjects *Cell::getCurrentObject()
{
    return _currentObject;
}

IObjects *Cell::getCurrentControlableObject()
{
    return _currentControlableObject;
}

bool Cell::isWalkable()
{
    return _isWalkable;
}

bool Cell::isBlocked()
{
    return _cellObjectSymbol == BLANK;
}

bool Cell::isFinishLine()
{
    return _cellObjectSymbol == FINISHLINE;
}
