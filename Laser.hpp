#ifndef LASER_HPP
#define LASER_HPP

#include "Settings.hpp"

class Laser
{
private:
	int _posX, _posY;

public:
	Laser(int x, int y) : _posX(x), _posY(y) {}

	int getPositionX() { return _posX; }
	int getPositionY() { return _posY; }

	bool isLaser(int x, int y) { return (x == _posX && y == _posY); }

	// if move() returns false -> out of map, delete this.
	bool move()
	{
		if (_posY > 1)
		{
			_posY--;
			return true;
		}
		return false;
	}
};

#endif