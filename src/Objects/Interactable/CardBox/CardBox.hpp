#pragma once

#include "../IInteractable.hpp"

class CardBox : public IInteractable
{
public:
    CardBox();

    void setPositionX(int x);
    void setPositionY(int y);
    void setPosition(int x, int y);
    std::pair<int, int> getPosition();
    std::string getObjectSymbol();
    void react();
};