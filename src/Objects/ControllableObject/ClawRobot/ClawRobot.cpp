#include "ClawRobot.hpp"

using namespace std;

class ClawRobot : public ControllableObject
{
private:
    std::string objectSymbol = "V";
    std::unordered_map<Commands, ICommand*> _command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    ClawRobot()
    {
        _x = 0;
        _y = 0;
        _z = Directions::Right;
        _isSucked = false;
    }

    ICommand* ClawRobot:: setCommand(ICommand* command)
    {
        if (_command.find(command->getEnum()) == _command.end())
        {
            _command[command->getEnum()] = command;
            return command;
        }
        return nullptr;
    }

    ICommand* ClawRobot::getCommand (Commands commands)
    {
        return _command[commands];
    }

    void ClawRobot::SetPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void ClawRobot::SetPositionX(int x)
    {
        _x = x;
    }

    void ClawRobot::SetPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> GetPosition()
    {
        return std::make_pair(_x, _y);
    }

    void ClawRobot::SetDirection(int direction)
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

    Directions ClawRobot ::GetDirection()
    {
        return _z;
    }

    bool ClawRobot::IsSucked()
    {
        return _isSucked;
    }

    std::string GetObjectSymbol()
    {
        return objectSymbol;
    }
};
