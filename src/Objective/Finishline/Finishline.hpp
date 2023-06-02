#pragma once

#include "../IObjective.hpp"
#include "../../Objects/Controlable/IControlable.hpp"

class Finishline : public IObjective
{
public:
	Finishline(std::pair<int,int> position, IControlable* player);
	bool getCondition() override;

private:
	IControlable* _player;
	std::pair<int, int> _position;
};