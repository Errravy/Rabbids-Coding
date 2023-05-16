#include "ArmedRabbids.hpp"

using namespace std;

class ArmedRabbids : public ControllableObject
{
private:
    std::string objectSymbol = "V";
    std::unordered_map<Commands, ICommand*> _command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    ArmedRabbids()
    {
        _x = 0;
        _y = 0;
        _z = Directions::Right;
        _isSucked = false;
    }

    ICommand* ArmedRabbids:: setCommand(ICommand* command)
    {
        if (_command.find(command->getEnum()) == _command.end())
        {
            _command[command->getEnum()] = command;
            return command;
        }
        return nullptr;
    }

    ICommand* ArmedRabbids::getCommand (Commands commands)
    {
        return _command[commands];
    }

    void ArmedRabbids::setPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void ArmedRabbids::setPositionX(int x)
    {
        _x = x;
    }

    void ArmedRabbids::setPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> getPosition()
    {
        return std::make_pair(_x, _y);
    }

    void ArmedRabbids::setDirection(int direction)
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

    Directions ArmedRabbids ::getDirection()
    {
        return _z;
    }

    bool ArmedRabbids::IsSucked()
    {
        return _isSucked;
    }

    std::string getObjectSymbol()
    {
        return objectSymbol;
    }
};
