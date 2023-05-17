#include "Button.hpp"

Button::Button()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void Button::setPositionX(int x)
{
    _x = x;
}

void Button::setPositionY(int y)
{
    _y = y;
}

void Button::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Button::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> Button::getPosition()
{
    return std::make_pair(_x, _y);
}

bool Button::isSucked()
{
    return _isSucked;
}

std::string Button::getObjectSymbol()
{
    return objectSymbol;
}