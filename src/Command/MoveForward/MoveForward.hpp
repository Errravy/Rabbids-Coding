#include "ICommand.hpp"

class MoveForward : public ICommand {
private:
    IControlable* _cObj;
    void moveByDirection();

public:
    MoveForward(IControlable* cObj);
    void execute() override;
    Commands getEnum() override;
};