#include "Finishline.hpp"

Finishline::Finishline(std::pair<int, int> position, IControlable *player)
{
	_position = position;
	_player = player;
}

bool Finishline::checkCondition()
{
	if (_position == _player->getPosition())
		return true;
	else
		return false;
}

std::pair<int, int> Finishline::getCoordinates()
{
	return _position;
}