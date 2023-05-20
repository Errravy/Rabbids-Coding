#include "TurnRight.hpp"

TurnRight::TurnRight(IControlable *cObj)
{
    _cObj = cObj;
}

void TurnRight::execute()
{
    rotate();
}

Commands TurnRight::getEnum()
{
    return Commands::Right;
}

void TurnRight::rotate()
{
    switch (_cObj->getDirection())
    {
    case Directions::Up:
        _cObj->setDirection(0);
        break;
    case Directions::Down:
        _cObj->setDirection(180);
        break;
    case Directions::Left:
        _cObj->setDirection(270);
        break;
    case Directions::Right:
        _cObj->setDirection(90);
        break;
    default:
        break;
    }
};
