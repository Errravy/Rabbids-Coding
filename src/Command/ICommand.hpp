#include <iostream>
class Command {
public:
    virtual Commands getEnum() = 0;
    virtual void execute() = 0;
};