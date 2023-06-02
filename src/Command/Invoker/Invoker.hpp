#pragma once

#include <list>

#include "../ICommand.hpp"
#include "../../Objective/IObjective.hpp"

class Invoker
{
private:
    std::list<ICommand *> _command;
    IObjective *_objective;

public:
    Invoker();

    void addCommand(ICommand *);
    bool executeCommands();
    void setObjective(IObjective *);
};