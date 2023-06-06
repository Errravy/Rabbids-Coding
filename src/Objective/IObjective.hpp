#pragma once

#include <iostream>

class IObjective
{
public:
	virtual bool checkCondition() = 0;
	virtual std::pair<int, int> getCoordinates() = 0;
};