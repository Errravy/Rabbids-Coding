#pragma once

#include "../ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class MoveForward : public ICommand
{
private:
    IControlable *_cObj;
    void moveByDirection();

public:
    MoveForward(IControlable *);

    void execute() override;
    Commands getEnum() override;
    std::string getCommandName() override;
};