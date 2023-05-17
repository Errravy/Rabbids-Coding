#include "ClawRobot.hpp"

ClawRobot::ClawRobot()
{
    _x = 0;
    _y = 0;
    _z = Directions::Right;
}

void ClawRobot::setPositionX(int x)
{
    _x = x;
}

void ClawRobot::setPositionY(int y)
{
    _y = y;
}

void ClawRobot::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> ClawRobot::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string ClawRobot::getObjectSymbol()
{
    return _objectSymbol;
}

ICommand *ClawRobot::setCommand(ICommand *command)
{
    if (_command.find(command->getEnum()) == _command.end())
    {
        _command[command->getEnum()] = command;
        return command;
    }
    return nullptr;
}

ICommand *ClawRobot::getCommand(Commands command)
{
    return _command[command];
}

void ClawRobot::setDirection(int direction)
{
    switch (direction)
    {
    case 0:
        _z = Directions::Right;
        break;
    case 90:
        _z = Directions::Down;
        break;
    case 180:
        _z = Directions::Left;
        break;
    case 270:
        _z = Directions::Up;
        break;
    default:
        std::cout << "Invalid direction!" << std::endl;
        break;
    }
}

Directions ClawRobot::getDirection()
{
    return _z;
}