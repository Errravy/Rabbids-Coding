#pragma once
#include "../IControlable.hpp"
#include "../../../Enums/Commands.hpp"
#include "../../../Enums/Directions.hpp"
#include "../../../Command/ICommand.hpp"
#include <iostream>
#include <unordered_map>
#include <utility>
class Rabbids : public IControlable
{
private:
    std::string objectSymbol = "A";
    std::unordered_map<Commands, ICommand *> _Command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    Rabbids();

    void setCommand(ICommand *command);

    ICommand *getCommand(Commands commands);

    void setPosition(int x, int y);

    void setPositionX(int x);

    void setPositionY(int y);

    std::pair<int, int> getPosition();

    void setDirection(int direction);

    Directions getDirection();

    bool isSucked();

    std::string getObjectSymbol();
};
