#include "Rabbids.hpp"

Rabbids::Rabbids()
{
    _x = 0;
    _y = 0;
    _z = Directions::Right;
    _objectSymbol = "R";
}

void Rabbids::setPositionX(int x)
{
    _x = x;
}

void Rabbids::setPositionY(int y)
{
    _y = y;
}

void Rabbids::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> Rabbids::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string Rabbids::getObjectSymbol()
{
    return _objectSymbol;
}

ICommand *Rabbids::setCommand(ICommand *command)
{
    if (_command.find(command->getEnum()) == _command.end())
    {
        _command[command->getEnum()] = command;
        return command;
    }
    return nullptr;
}

ICommand *Rabbids::getCommand(Commands command)
{
    return _command[command];
}

std::vector<std::string> Rabbids::getCommands()
{
    std::vector<std::string> commands;
    for (auto &command : _command)
    {
        commands.push_back(command.second->getCommandName());
    }
    return commands;
}

void Rabbids::setDirection(int direction)
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

Directions Rabbids::getDirection()
{
    return _z;
}