#include "MoveForward.hpp"

MoveForward::MoveForward(IControlable *cObj)
{
    _cObj = cObj;
}

void MoveForward::execute()
{
    std::cout << "MoveForward" << std::endl;
    moveByDirection();
}

Commands MoveForward::getEnum()
{
    return Commands::CommandForward;
}

void MoveForward::moveByDirection()
{
    switch (_cObj->getDirection())
    {
    case Directions::Up:
        _cObj->setPositionY(_cObj->getPosition().second - 1);
        break;
    case Directions::Down:
        _cObj->setPositionY(_cObj->getPosition().second + 1);
        break;
    case Directions::Left:
        _cObj->setPositionX(_cObj->getPosition().first - 1);
        break;
    case Directions::Right:
        _cObj->setPositionX(_cObj->getPosition().first + 1);
        break;
    default:
        break;
    }
}