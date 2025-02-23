#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Settings.hpp"

class AAlien
{
protected:
	int _posX, _posY;
	char _ascii;
	int _tick;
	int _health;

public:
	AAlien(int x, int y, char c, int health = 1) : _posX(x), _posY(y), _ascii(c), _tick(0), _health(health) {}
	virtual ~AAlien() {};

	int getPositionX() { return _posX; }
	int getPositionY() { return _posY; }

	char getAscii() { return _ascii; }

	bool isAlien(int x, int y) { return (x == _posX && y == _posY); }

	void move() { _posY++; }

	virtual void action() = 0;

	bool isDead() {
		_health--;
		if (_health == 0)
			return true;
		else
			return false;
	}
};


class Alien1 : public AAlien
{
public:
	Alien1( int x, int y ) : AAlien(x, y, '+') {}
	
	void action() {}
};

class Alien2 : public AAlien
{
public:
	Alien2( int x, int y ) : AAlien(x, y, 'M') {}

	void action() {
		switch (_tick % 4)
		{
			case 0:
				_posX++;
				break;
			case 1:
				_posX--;
				break;
			case 2:
				_posX--;
				break;
			case 3:
				_posX++;
				break;
		}
		_tick++;
	}
};

class Alien3 : public AAlien
{
public:
	Alien3(int x, int y): AAlien(x, y, 'E', 5) {}

	void action() {
		switch (_health)
		{
			case 5:
				_ascii = 'E';
				break;
			case 4:
				_ascii = 'D';
				break;
			case 3:
				_ascii = 'C';
				break;
			case 2:
				_ascii = 'B';
				break;
			case 1:
				_ascii = 'A';
				break;
		}
	}
};

#endif
