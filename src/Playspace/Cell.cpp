#include "Cell.h"

const std::string Cell::walkable = "-";
const std::string Cell::blank = " ";

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
    obj = nullptr;
    cellObj = walkable;
}

void Cell::checkObject(IObjects* obj)
{
    if (obj->getPosition().x == x && obj->getPosition().y == y)
    {
        isWalkable = false;
        std::cout << "Cell " << x << " " << y << " is not walkable because " << obj << " inside it!" << std::endl;
        this->obj = obj;
        cellObj = obj->getObjectSymbol();
    }
    else
    {
        isWalkable = true;
        this->obj = nullptr;
        cellObj = walkable;
    }
}

void Cell::setToBlankCell()
{
    isWalkable = false;
    cellObj = blank;
}

std::string Cell::getCellObj()
{
    return cellObj;
}

IObjects* Cell::getObject()
{
    return obj;
}

bool Cell::isWalkable()
{
    return isWalkable;
}

bool Cell::isBlocked()
{
    return cellObj == blank;
}
