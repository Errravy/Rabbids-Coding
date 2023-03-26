#pragma once

#include "../../Command.hpp"

class MoveForward : public Command
{
public:
    virtual void execute() override;
};