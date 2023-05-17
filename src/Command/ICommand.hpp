#pragma once

#include "../Enum/Commands.hpp"

class ICommand
{
public:
    virtual Commands getEnum() = 0;
    virtual void execute() = 0;
};
