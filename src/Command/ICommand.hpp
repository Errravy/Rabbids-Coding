#pragma once

#include <iostream>

#include "../Enum/Commands.hpp"

class ICommand
{
public:
    virtual Commands getEnum() = 0;
    virtual std::string getCommandName() = 0;
    virtual void execute() = 0;
};
