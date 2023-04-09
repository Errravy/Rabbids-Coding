#include <iostream>
#include "./Objects/Factory/ObjectFactory.cpp"
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  Objects *button = ObjectFactory::CreateObject("Button");
  Objects *idleRabbids = ObjectFactory::CreateObject("IdleRabbids");
  button->Interact();
  idleRabbids->Interact();
  delete button;
  delete idleRabbids;
  return 0;
}
