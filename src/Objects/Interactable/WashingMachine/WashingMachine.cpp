#include "WashingMachine.hpp"

WashingMachine::WashingMachine()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void WashingMachine::setPositionX(int x)
{
    _x = x;
}

void WashingMachine::setPositionY(int y)
{
    _y = y;
}

void WashingMachine::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void WashingMachine::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> WashingMachine::getPosition()
{
    return std::make_pair(_x, _y);
}

bool WashingMachine::isSucked()
{
    return _isSucked;
}

std::string WashingMachine::getObjectSymbol()
{
    return objectSymbol;
}