#include "MoveBackward.hpp"

MoveBackward::MoveBackward(IControlable *cObj)
{
    _cObj = cObj;
}

void MoveBackward::execute()
{
    std::cout << "Move Backward" << std::endl;
    moveByDirection();
}

Commands MoveBackward::getEnum()
{
    return Commands::Backward;
}

void MoveBackward::moveByDirection()
{
    switch (_cObj->getDirection())
    {
    case Directions::Up:
        _cObj->setPositionY(_cObj->getPosition().second + 1);
        break;
    case Directions::Down:
        _cObj->setPositionY(_cObj->getPosition().second - 1);
        break;
    case Directions::Left:
        _cObj->setPositionX(_cObj->getPosition().first + 1);
        break;
    case Directions::Right:
        _cObj->setPositionX(_cObj->getPosition().first - 1);
        break;
    default:
        break;
    }
}