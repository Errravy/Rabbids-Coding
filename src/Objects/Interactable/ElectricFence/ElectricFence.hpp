#pragma once
#include <iostream>
#include "../IInteractable.hpp"

class ElectricFence : public IInteractable
{
private:
    std::string objectSymbol = "E";
    int _x;
    int _y;
    bool _isSucked;

public:
    ElectricFence();
    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    std::pair<int, int> getPosition() override;
    void react() override;
    bool isSucked() override;
    std::string getObjectSymbol() override;
};