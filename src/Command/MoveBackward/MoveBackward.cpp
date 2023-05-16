#include "MoveBackward.hpp"
#include "ControllableObject.hpp"
#include <iostream>

MoveBackward::MoveBackward(ControllableObject *cObj)
{
    _cObj = cObj;
}

void MoveBackward::execute()
{
    moveByDirection();
}

Commands MoveBackward::getEnum()
{
    return Commands::Backward;
}

void MoveBackward::moveByDirection()
{
    switch (_cObj->GetDirection())
    {
    case Directions::Up:
        _cObj->setPositionY(_cObj->GetPosition().y + 1);
        break;
    case Directions::Down:
        _cObj->setPositionY(_cObj->GetPosition().y - 1);
        break;
    case Directions::Left:
        _cObj->setPositionX(_cObj->GetPosition().x + 1);
        break;
    case Directions::Right:
        _cObj->setPositionX(_cObj->GetPosition().x - 1);
        break;
    default:
        break;
    }
}