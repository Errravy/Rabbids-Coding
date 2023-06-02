#include "Invoker.hpp"

Invoker::Invoker()
{
    _command = std::list<ICommand *>();
}

void Invoker::addCommand(ICommand *command)
{
    _command.push_back(command);
}

bool Invoker::executeCommands()
{
    bool isObjectiveCompleted = false;

    for (ICommand *command : _command)
    {
        command->execute();

        if (_objective->checkCondition())
        {
            isObjectiveCompleted = true;
        }
    }

    _command.clear();

    return isObjectiveCompleted;
}

void Invoker::setObjective(IObjective *objective)
{
    _objective = objective;
}