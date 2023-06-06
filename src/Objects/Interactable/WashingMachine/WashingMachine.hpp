#pragma once

#include "../IInteractable.hpp"

class WashingMachine : public IInteractable
{
public:
    WashingMachine();

    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
    std::string getObjectSymbol();
    void react();
};