#pragma once
#include <iostream>
#include "../IInteractable.hpp"

class WashingMachine : public IInteractable
{
private:
    std::string objectSymbol = "I";
    int _x;
    int _y;
    bool _isSucked;

public:
    WashingMachine();
    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    void react() override;
    std::pair<int, int> getPosition() override;
    bool isSucked() override;
    std::string getObjectSymbol() override;
};
