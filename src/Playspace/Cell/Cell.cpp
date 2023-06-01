 #include "Cell.hpp"


Cell::Cell(int x, int y)
{
    _x = x;
    _y = y;
    _obj = nullptr;
    _cellObj = WALKABLE;
}

void Cell::checkObject(IObjects *obj)
{
    if (IControlable* cobj = dynamic_cast<IControlable*>(obj))
    {
        if (obj->getPosition().first == _x && obj->getPosition().second == _y)
        {
            std::cout << "cobj bukan obj" << std::endl;
            _isWalkable = false;
            _cobj = dynamic_cast<IControlable*>(obj);
            _cellObj = obj->getObjectSymbol();
        }
        else
        {
            _isWalkable = true;
            _cobj = nullptr;
            _cellObj = WALKABLE;
        }
    }
    else
    {
        if (obj->getPosition().first == _x && obj->getPosition().second == _y)
        {
            _isWalkable = false;
            _obj = obj;
            _cellObj = obj->getObjectSymbol();
        }
        else
        {
            _isWalkable = true;
            _obj = nullptr;
            _cellObj = WALKABLE;
        }
    }
    
}

void Cell::setToBlankCell()
{
    _isWalkable = false;
    _cellObj = BLANK;
}

std::string Cell::getCellObj()
{
    return _cellObj;
}

IObjects *Cell::getObject()
{
    return _obj;
}

IObjects* Cell::getCobj()
{
    return _cobj;
}

bool Cell::isWalkable()
{
    return _isWalkable;
}

bool Cell::isBlocked()
{
    return _cellObj == BLANK;
}
