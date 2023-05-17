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

    ICommand ClawRobot:: SetCommand(ICommand* command)
    {
        if (_command.find(command->GetEnum()) == _command.end())
        {
            _command[command->GetEnum()] = command;
            return command;
        }
        return nullptr;
    }

    ICommand ClawRobot::GetCommand (Commands commands)
    {
        return _command[commands];
    }

    void ClawRobot::setPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void ClawRobot::setPositionX(int x)
    {
        _x = x;
    }

    void ClawRobot::setPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> getPosition()
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

    bool ClawRobot::isSucked()
    {
        return _isSucked;
    }

    std::string getObjectSymbol()
    {
        return objectSymbol;
    }
};
