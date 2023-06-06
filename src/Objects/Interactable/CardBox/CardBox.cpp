#include "CardBox.hpp"

CardBox::CardBox()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void CardBox::setPositionX(int x)
{
    _x = x;
}

void CardBox::setPositionY(int y)
{
    _y = y;
}

void CardBox::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> CardBox::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string CardBox::getObjectSymbol()
{
    return _objectSymbol;
}

void CardBox::react()
{
    std::cout << "CardBox activated!" << std::endl;
}