#ifndef TURNRIGHT_HPP
#define TURNRIGHT_HPP

#include "ICommand.hpp"
#include "IControlable.hpp"

class TurnRight : public ICommand {
private:
    IControlable* _cObj;

public:
    TurnRight(IControlable* cObj);

    void Execute() override;

    Commands GetEnum() override;

private:
    void Rotate();
};

#endif /* TURNRIGHT_HPP */
