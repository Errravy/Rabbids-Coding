#pragma once
#include "../IInteractable.hpp"

class Button : public IInteractable
{
private:
    std::string objectSymbol = "E";
    int _x;
    int _y;
    bool _isSucked;

public:
    Button();
    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
    void react();
    bool isSucked();
    std::string getObjectSymbol();
};