#pragma once
#include "../InteractableObject.hpp"

class ElectricFence : public IInteractable
{
private:
    std::string objectSymbol = "E";
    int _x;
    int _y;
    bool _isSucked;

public:
    ElectricFence();
    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> GetPosition();
    void react();
    bool isSucked();
    std::string GetObjectSymbol();
};