#ifndef TURNLEFT_H
#define TURNLEFT_H

#include "ICommand.h"
#include "IControlable.h"

class TurnLeft : public ICommand {
private:
    IControlable* _cObj;

public:
    TurnLeft(IControlable* cObj);

    void Execute() override;
    Commands GetEnum() override;

private:
    void Rotate();
};

#endif // TURNLEFT_H
