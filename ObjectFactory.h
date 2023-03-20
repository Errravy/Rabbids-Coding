#include <iostream>
#include <InteractableObject.h>

using namespace std;

class ObjectFactory{
	public :
		static InteractableObject CreateObject(string ObjectName);
		
};
