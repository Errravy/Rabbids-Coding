#include "MoveBackward.hpp"

MoveBackward(IControlable *cObj)
{
    _cObj = cObj;
}

void Execute()
{
    MoveByDirection();
}

Commands GetEnum()
{
    return Commands::Backward;
}

void MoveByDirection()
{
    switch (_cObj->GetDirection())
    {
    case Directions::Up:
        _cObj->SetPositionY(_cObj->GetPosition().y + 1);
        break;
    case Directions::Down:
        _cObj->SetPositionY(_cObj->GetPosition().y - 1);
        break;
    case Directions::Left:
        _cObj->SetPositionX(_cObj->GetPosition().x + 1);
        break;
    case Directions::Right:
        _cObj->SetPositionX(_cObj->GetPosition().x - 1);
        break;
    default:
        break;
    }
}