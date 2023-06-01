#pragma once

#include "../IInteractable.hpp"

class Plunger : public IInteractable
{
public:
    Plunger();

    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
    std::string getObjectSymbol();
    void react();
};