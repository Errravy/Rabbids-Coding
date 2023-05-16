#pragma once
#include <iostream>
#include "../InteractableObject.hpp"

using namespace std;

class IdleRabbids : public InteractableObject
{
private:
    string objectSymbol = "I";
    int _x;
    int _y;
    bool _isSucked;

public:
    IdleRabbids();
    void setPosition(int) override;
    void setPosition(int) override;
    void setPosition(int, int) override;
    void react() override;
    std::pair<int, int> GetPosition() override;
    bool isSucked() override;
    void string getObjectSymbol() override;
};
