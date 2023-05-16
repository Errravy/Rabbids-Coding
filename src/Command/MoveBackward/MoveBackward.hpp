#include "ICommand.hpp"

class MoveBackward : public ICommand
{
private:
    IControlable *_cObj;
    void MoveByDirection;

public:
    MoveBackward(IControlable *cObj);
    void Execute();
    Commands GetEnum();
};