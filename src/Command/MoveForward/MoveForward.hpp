#include "ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
class MoveForward : public ICommand {
private:
    IControlable* _cObj;
    void moveByDirection();

public:
    MoveForward(IControlable* cObj);
    void execute() override;
    Commands getEnum() override;
};