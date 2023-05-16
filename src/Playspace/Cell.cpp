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

void Cell::CheckObject(IObjects* obj)
{
    if (obj->GetPosition().x == x && obj->GetPosition().y == y)
    {
        isWalkable = false;
        std::cout << "Cell " << x << " " << y << " is not walkable because " << obj << " inside it!" << std::endl;
        this->obj = obj;
        cellObj = obj->GetObjectSymbol();
    }
    else
    {
        isWalkable = true;
        this->obj = nullptr;
        cellObj = walkable;
    }
}

void Cell::SetToBlankCell()
{
    isWalkable = false;
    cellObj = blank;
}

std::string Cell::GetCellObj()
{
    return cellObj;
}

IObjects* Cell::GetObject()
{
    return obj;
}

bool Cell::IsWalkable()
{
    return isWalkable;
}

bool Cell::IsBlocked()
{
    return cellObj == blank;
}
