#ifndef TURNLEFT_H
#define TURNLEFT_H

#include "ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

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
