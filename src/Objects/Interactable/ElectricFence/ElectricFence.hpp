#pragma once

#include "../IInteractable.hpp"

class ElectricFence : public IInteractable
{
public:
    ElectricFence();

    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
    std::string getObjectSymbol();
    void react();
};