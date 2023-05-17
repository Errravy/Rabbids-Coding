#include "CardBox.hpp"

CardBox::CardBox()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
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

void CardBox::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> CardBox::getPosition()
{
    return std::make_pair(_x, _y);
}

bool CardBox::isSucked()
{
    return _isSucked;
}

std::string CardBox::getObjectSymbol()
{
    return objectSymbol;
}