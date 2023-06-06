#include "Button.hpp"

Button::Button()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
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

std::pair<int, int> Button::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string Button::getObjectSymbol()
{
    return _objectSymbol;
}

void Button::react()
{
    std::cout << "Button activated!" << std::endl;
}