#include <iostream>
#include "Objects/Factory/ObjectFactory.hpp"
#include "Objects/Interactable/IInteractable.hpp"
#include <typeinfo>
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  IObjects *button = ObjectFactory::createObject(Objects::button);
  if (IInteractable *interactableButton = static_cast<IInteractable *>(button))
  {
    interactableButton->react();
  }
  else
  {
    cout << "Not Interactable" << endl;
  }
  return 0;
}
