#pragma once

#include <iostream>
#include "../IInteractable.hpp"

class IdleRabbids : public IInteractable
{
public:
    IdleRabbids();

    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    void react() override;
    std::pair<int, int> getPosition() override;
    std::string getObjectSymbol() override;
};
