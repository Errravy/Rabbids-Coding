#include "Invoker.hpp"

void Invoker::storeCommand(Command *command)
{
    this->commandList[this->commandCount] = command;
    this->commandCount++;
}

void Invoker::executeCommand()
{
    int commandListLength = sizeof(this->commandList) / sizeof(int);
    for (int i = 0; i < commandListLength; i++)
    {
        this->commandList[i]->execute();
    }
}