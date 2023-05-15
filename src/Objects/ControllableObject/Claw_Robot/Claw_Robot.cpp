#include "Claw_Robot.hpp"

using namespace std;

int Claw_Robot::getDirection()
{
     return direction;
}

void Claw_Robot::setDirection(int newDirection)
{
    direction = newDirection;
}

void Claw_Robot::Interact(){
    cout << "Claw Robot diinteraksi";
}