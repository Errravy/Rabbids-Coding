#pragma once

#include "../ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class MoveBackward : public ICommand
{
private:
    IControlable *_cObj;
    void moveByDirection();

public:
    MoveBackward(IControlable *);

    void execute() override;
    Commands getEnum() override;
    std::string getCommandName() override;
};