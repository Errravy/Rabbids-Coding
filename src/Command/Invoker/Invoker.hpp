#pragma once

#include <list>

#include "../ICommand.hpp"

class Invoker
{
private:
    std::list<ICommand *> _command;

public:
    Invoker();

    void addCommand(ICommand *);
    void executeCommands();
};