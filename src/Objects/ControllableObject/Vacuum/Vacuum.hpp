#pragma once
#include "../ControllableObject.hpp"
#include "../ICommand.hpp"
#include <iostream>
#include <unordered_map>
#include <utility>
class Vacuum : public ControllableObject
{
private:
    std::string objectSymbol = "V";
    std::unordered_map<Commands, ICommand*> _Command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    Vacuum();

    ICommand* SetCommand(ICommand* command);

    ICommand* GetCommand(Commands commands);

    void SetPosition(int x, int y);

    void SetPositionX(int x);

    void SetPositionY(int y);

    std::pair<int, int> GetPosition();

    void SetDirection(int direction);

    Directions GetDirection();

    bool IsSucked();

    std::string GetObjectSymbol();
};
