#ifndef TURNLEFT_H
#define TURNLEFT_H

#include "ICommand.h"
#include "IControlable.h"

class TurnLeft : public ICommand {
private:
    void rotate();
    IControlable* _cObj;

public:
    TurnLeft(IControlable* cObj);

    void execute() override;
    Commands getEnum() override;

};

#endif // TURNLEFT_H
