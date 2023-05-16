#include "Invoker.hpp"

Invoker::Invoker() {}

void Invoker::addCommand(ICommand* command) {
    _command.push_back(command);
}

void Invoker::executeCommands() {
    for (auto command : _command) {
        command->Execute();
    }
    _command.clear();
}