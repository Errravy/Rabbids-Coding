#pragma once

#include "../ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class TurnLeft : public ICommand
{
private:
    IControlable *_cObj;
    void rotate();

public:
    TurnLeft(IControlable *);

    void execute() override;
    Commands getEnum() override;
};
