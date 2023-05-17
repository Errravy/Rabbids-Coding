#include "IdleRabbids.hpp"

using namespace std;

IdleRabbids::IdleRabbids()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void IdleRabbids::setPositionX(int x)
{
    _x = x;
}

void IdleRabbids::setPositionY(int y)
{
    _y = y;
}

void IdleRabbids::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void IdleRabbids::react()
{
    cout << "IdleRabbid activated!" << endl;
}

std::pair<int, int> IdleRabbids::getPosition()
{
    return std::make_pair(_x, _y);
}

bool IdleRabbids::isSucked()
{
    return _isSucked;
}

std::string IdleRabbids::getObjectSymbol()
{
    return objectSymbol;
}