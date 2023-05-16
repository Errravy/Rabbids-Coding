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

    ICommand Vacuum:: setCommand(ICommand* command)
    {
        if (_command.find(command->GetEnum()) == _command.end())
        {
            _command[command->GetEnum()] = command;
            return command;
        }
        return nullptr;
    }

    ICommand Vacuum::getCommand (Commands commands)
    {
        return _command[commands];
    }

    void Vacuum::setPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void Vacuum::setPositionX(int x)
    {
        _x = x;
    }

    void Vacuum::setPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> getPosition()
    {
        return std::make_pair(_x, _y);
    }

    void Vacuum::setDirection(int direction)
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

    Directions Vacuum ::getDirection()
    {
        return _z;
    }

    bool Vacuum::isSucked()
    {
        return _isSucked;
    }

    std::string getObjectSymbol()
    {
        return objectSymbol;
    }
};
