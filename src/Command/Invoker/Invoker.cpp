#include "Invoker.hpp"

Invoker::Invoker()
{
    _command = std::list<ICommand *>();
}

void Invoker::addCommand(ICommand *command)
{
    _command.push_back(command);
}

void Invoker::executeCommands()
{
    for (ICommand *command : _command)
    {
        command->execute();
    }
    _command.clear();
}