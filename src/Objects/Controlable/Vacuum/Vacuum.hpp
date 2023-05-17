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
    std::unordered_map<Commands, ICommand *> _Command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    Vacuum();

    ICommand *SetCommand(ICommand *command);

    ICommand *GetCommand(Commands commands);

    void setPosition(int x, int y);

    void setPositionX(int x);

    void setPositionY(int y);

    std::pair<int, int> getPosition();

    void SetDirection(int direction);

    Directions GetDirection();

    bool isSucked();

    std::string getObjectSymbol();
};
