#include "SedotWC.hpp"

using namespace std;

SedotWC::SedotWC()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void SedotWC::setPosition(int x)
{
    _x = x;
}

void SedotWC::setPosition(int y)
{
    _y = y;
}

void SedotWC::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void SedotWC::react()
{
    cout << "SedotWC activated!" << endl;
}

std::pair<int, int> SedotWC::GetPosition()
{
    return std::make_pair(_x, _y);
}

bool SedotWC::isSucked()
{
    return _isSucked;
}

void SedotWC::getObjectSymbol()
{
    return objectSymbol;
}