#ifndef TURNRIGHT_HPP
#define TURNRIGHT_HPP

#include "ICommand.hpp"
#include "IControlable.hpp"

class TurnRight : public ICommand {
private:
    void rotate();
    IControlable* _cObj;

public:
    TurnRight(IControlable* cObj);

    void Execute() override;
    Commands GetEnum() override;

};

#endif /* TURNRIGHT_HPP */
