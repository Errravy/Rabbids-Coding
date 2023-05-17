#include <iostream>
#include "Objects/Factory/ObjectFactory.hpp"
#include "Objects/Interactable/InteractableObject.hpp"
#include <typeinfo>
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  Objects *button = ObjectFactory::createObject("Button");
  if (InteractableObject *interactableButton = static_cast<InteractableObject *>(button))
  {
    interactableButton->Interact();
  }
  else
  {
    cout << "Not Interactable" << endl;
  }
  return 0;
}
