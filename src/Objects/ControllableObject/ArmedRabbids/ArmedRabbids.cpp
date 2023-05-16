#include "ArmedRabbids.hpp"

using namespace std;

int ArmedRabbids::getDirection()
{
     return direction;
}

void ArmedRabbids::setDirection(int newDirection)
{
    direction = newDirection;
}

void ArmedRabbids:: Interact(){  
    cout << "ArmedRabbids Berjalan";
}