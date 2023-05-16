#pragma once
#include "ICommand.hpp"
#include "ControllableObject.hpp"

class MoveBackward : public ICommand
{
private:
    ControllableObject *_cObj;
    void moveByDirection();

public:
    MoveBackward(ControllableObject *cObj);
    void execute();
    Commands getEnum();
};