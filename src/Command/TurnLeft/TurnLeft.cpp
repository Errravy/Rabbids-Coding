#include "TurnLeft.hpp"

TurnLeft::TurnLeft(IControlable *cObj)
{
    _cObj = cObj;
}

std::string TurnLeft::getCommandName()
{
    return "Turn Left";
}

void TurnLeft::execute()
{
    rotate();
}

Commands TurnLeft::getEnum()
{
    return Commands::Left;
}

void TurnLeft::rotate()
{
    switch (_cObj->getDirection())
    {
    case Directions::Up:
        _cObj->setDirection(180);
        break;
    case Directions::Down:
        _cObj->setDirection(0);
        break;
    case Directions::Left:
        _cObj->setDirection(90);
        break;
    case Directions::Right:
        _cObj->setDirection(270);
        break;
    default:
        break;
    }
};
