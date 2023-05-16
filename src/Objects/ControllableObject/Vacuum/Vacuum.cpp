#include "Vacuum.hpp"

using namespace std;

class Vacuum : public ControllableObject
{
private:
    std::string objectSymbol = "V";
    std::unordered_map<Commands, ICommand*> _command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    Vacuum()
    {
        _x = 0;
        _y = 0;
        _z = Directions::Right;
        _isSucked = false;
    }

    ICommand Vacuum:: SetCommand(ICommand* command)
    {
        if (_command.find(command->GetEnum()) == _command.end())
        {
            _command[command->GetEnum()] = command;
            return command;
        }
        return nullptr;
    }

    ICommand Vacuum::GetCommand (Commands commands)
    {
        return _command[commands];
    }

    void Vacuum::SetPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void Vacuum::SetPositionX(int x)
    {
        _x = x;
    }

    void Vacuum::SetPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> GetPosition()
    {
        return std::make_pair(_x, _y);
    }

    void Vacuum::SetDirection(int direction)
    {
        switch (direction)
        {
            case 0:
                _z = Directions::Right;
                break;
            case 90:
                _z = Directions::Down;
                break;
            case 180:
                _z = Directions::Left;
                break;
            case 270:
                _z = Directions::Up;
                break;
            default:
                std::cout << "Invalid direction!" << std::endl;
                break;
        }
    }

    Directions Vacuum ::GetDirection()
    {
        return _z;
    }

    bool Vacuum::IsSucked()
    {
        return _isSucked;
    }

    std::string GetObjectSymbol()
    {
        return objectSymbol;
    }
};
