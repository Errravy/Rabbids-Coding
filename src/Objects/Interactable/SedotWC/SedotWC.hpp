#pragma once

#include <iostream>
#include "../IInteractable.hpp"

class SedotWC : public IInteractable
{
public:
    SedotWC();

    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    void react() override;
    std::pair<int, int> getPosition() override;
    std::string getObjectSymbol() override;
};
