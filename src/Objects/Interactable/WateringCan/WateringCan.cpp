#include "WateringCan.hpp"

WateringCan::WateringCan()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void WateringCan::setPositionX(int x)
{
    _x = x;
}

void WateringCan::setPositionY(int y)
{
    _y = y;
}

void WateringCan::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void WateringCan::react()
{
    std::cout << "Sucked" << std::endl;
}

std::pair<int, int> WateringCan::getPosition()
{
    return std::make_pair(_x, _y);
}

bool WateringCan::isSucked()
{
    return _isSucked;
}

std::string WateringCan::getObjectSymbol()
{
    return objectSymbol;
} 