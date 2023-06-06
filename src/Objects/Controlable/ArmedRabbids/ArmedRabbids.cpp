#include "ArmedRabbids.hpp"

ArmedRabbids::ArmedRabbids()
{
    _x = 0;
    _y = 0;
    _z = Directions::Right;
    _objectSymbol = "C";
}

void ArmedRabbids::setPositionX(int x)
{
    _x = x;
}

void ArmedRabbids::setPositionY(int y)
{
    _y = y;
}

void ArmedRabbids::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> ArmedRabbids::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string ArmedRabbids::getObjectSymbol()
{
    return _objectSymbol;
}

ICommand *ArmedRabbids::setCommand(ICommand *command)
{
    if (_command.find(command->getEnum()) == _command.end())
    {
        _command[command->getEnum()] = command;
        return command;
    }
    return nullptr;
}

ICommand *ArmedRabbids::getCommand(Commands command)
{
    return _command[command];
}

std::vector<std::string> ArmedRabbids::getCommands()
{
    std::vector<std::string> commands;
    for (auto &command : _command)
    {
        commands.push_back(command.second->getCommandName());
    }
    return commands;
}

void ArmedRabbids::setDirection(int direction)
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

Directions ArmedRabbids::getDirection()
{
    return _z;
}