#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <list>

class ICommand {
public:
    virtual void execute() = 0;
};

class Invoker {
private:
    std::list<ICommand*> _command;
public:
    Invoker();
    void addCommand(ICommand* command);
    void executeCommands();
};

#endif // INVOKER_HPP
