#pragma once
#include "ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class MoveBackward : public ICommand
{
private:
    IControlable *_cObj;
    void moveByDirection();

public:
    MoveBackward(IControlable *cObj);
    void execute();
    Commands getEnum();
};