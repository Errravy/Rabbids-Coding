#pragma once

#include <iostream>

#include "../Command.hpp"

using namespace std;

class Invoker
{
public:
    Command *commandList[20];
    int commandCount = 0;

    void storeCommand(Command *);
    void executeCommand();
};