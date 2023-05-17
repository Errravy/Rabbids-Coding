#pragma once

#include <iostream>

#include "../IInteractable.hpp"

class IdleRabbids : public IInteractable
{
private:
    string objectSymbol = "I";
    int _x;
    int _y;
    bool _isSucked;

public:
    IdleRabbids();
    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    void react() override;
    std::pair<int, int> getPosition() override;
    bool isSucked() override;
    void std::string getObjectSymbol() override;
};
