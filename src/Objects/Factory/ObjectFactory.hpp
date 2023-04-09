#pragma once
#include "../Objects.hpp"

using namespace std;

class ObjectFactory
{
public:
	static Objects *CreateObject(string ObjectName);
};
