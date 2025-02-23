#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Settings.hpp"
#include "Laser.hpp"

enum Direction
{
	LEFT,
	RIGHT,
	NONE
};

class Player
{
private:
	int _posX, _posY;
	int _direction;

public:
	Player(int x, int y) : _posX(x), _posY(y), _direction(NONE) {}

	int getPositionX() { return _posX; }
	int getPositionY() { return _posY; }

	bool isPlayer(int x, int y) { return (x == _posX && y == _posY); }

	void setDirectionLeft() { _direction = LEFT; }
	void setDirectionRight() { _direction = RIGHT; }
	void move()
	{
		switch (_direction)
		{
		case LEFT:
			if (_posX > 1)
				_posX--;
			_direction = NONE;
			break;
		case RIGHT:
			if (_posX < width - 2)
				_posX++;
			_direction = NONE;
			break;
		}
	}
};

#endif