#ifndef TURNRIGHT_HPP
#define TURNRIGHT_HPP

#include "ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class TurnRight : public ICommand {
private:
    void rotate();
    IControlable* _cObj;

public:
    TurnRight(IControlable* cObj);

    void execute() override;
    Commands getEnum() override;

};

#endif /* TURNRIGHT_HPP */
