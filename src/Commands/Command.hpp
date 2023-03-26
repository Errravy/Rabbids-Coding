#pragma once

#include <iostream>

using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};