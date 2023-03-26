#pragma once

#include "../../Command.hpp"

class MoveBackward : public Command
{
public:
    virtual void execute() override;
};