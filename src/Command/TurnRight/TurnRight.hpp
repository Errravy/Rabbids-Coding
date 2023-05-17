#pragma once

#include "../ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class TurnRight : public ICommand
{
private:
    IControlable *_cObj;
    void rotate();

public:
    TurnRight(IControlable *);

    void execute() override;
    Commands getEnum() override;
};
