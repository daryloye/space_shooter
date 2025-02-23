#ifndef LEVELS_HPP
#define LEVELS_HPP

#include "Settings.hpp"
#include "Alien.hpp"

void Level0(std::list<AAlien*>&aliens)
{
	aliens.push_back( new Alien1(4, 1));
	aliens.push_back( new Alien1(6, 1));
	aliens.push_back( new Alien1(8, 1));
	aliens.push_back( new Alien1(11, 1));
	aliens.push_back( new Alien1(13, 1));
	aliens.push_back( new Alien1(15, 1));

	aliens.push_back( new Alien1(3, 2));
	aliens.push_back( new Alien1(5, 2));
	aliens.push_back( new Alien1(7, 2));
	aliens.push_back( new Alien1(12, 2));
	aliens.push_back( new Alien1(14, 2));
	aliens.push_back( new Alien1(16, 2));

	aliens.push_back( new Alien1(4, 3));
	aliens.push_back( new Alien1(6, 3));
	aliens.push_back( new Alien1(8, 3));
	aliens.push_back( new Alien1(11, 3));
	aliens.push_back( new Alien1(13, 3));
	aliens.push_back( new Alien1(15, 3));
}

void Level1(std::list<AAlien*>&aliens)
{
	aliens.push_back( new Alien2(5, 1));
	aliens.push_back( new Alien2(7, 1));
	aliens.push_back( new Alien2(12, 1));
	aliens.push_back( new Alien2(14, 1));
	
	aliens.push_back( new Alien2(4, 2));
	aliens.push_back( new Alien2(6, 2));
	aliens.push_back( new Alien2(8, 2));
	aliens.push_back( new Alien2(11, 2));
	aliens.push_back( new Alien2(13, 2));
	aliens.push_back( new Alien2(15, 2));
	
	aliens.push_back( new Alien2(5, 3));
	aliens.push_back( new Alien2(7, 3));
	aliens.push_back( new Alien2(12, 3));
	aliens.push_back( new Alien2(14, 3));
}

void Level2(std::list<AAlien*>&aliens)
{
	aliens.push_back( new Alien3(5, 1));
	aliens.push_back( new Alien3(14, 1));
}

void Level3(std::list<AAlien*>&aliens)
{
	aliens.push_back( new Alien1(3, 1));
	aliens.push_back( new Alien1(5, 1));
	aliens.push_back( new Alien1(7, 1));
	aliens.push_back( new Alien1(9, 1));
	aliens.push_back( new Alien1(10, 1));
	aliens.push_back( new Alien1(14, 1));
	aliens.push_back( new Alien1(16, 1));
	aliens.push_back( new Alien1(18, 1));

	aliens.push_back( new Alien2(4, 2));
	aliens.push_back( new Alien2(6, 2));
	aliens.push_back( new Alien2(8, 2));
	aliens.push_back( new Alien2(11, 2));
	aliens.push_back( new Alien2(13, 2));
	aliens.push_back( new Alien2(15, 2));

	aliens.push_back( new Alien3(5, 3));
	aliens.push_back( new Alien3(14, 3));

	aliens.push_back( new Alien2(4, 4));
	aliens.push_back( new Alien2(6, 4));
	aliens.push_back( new Alien2(8, 4));
	aliens.push_back( new Alien2(11, 4));
	aliens.push_back( new Alien2(13, 4));
	aliens.push_back( new Alien2(15, 4));

	aliens.push_back( new Alien1(3, 5));
	aliens.push_back( new Alien1(5, 5));
	aliens.push_back( new Alien1(7, 5));
	aliens.push_back( new Alien1(9, 5));
	aliens.push_back( new Alien1(10, 5));
	aliens.push_back( new Alien1(14, 5));
	aliens.push_back( new Alien1(16, 5));
	aliens.push_back( new Alien1(18, 5));
}

void Levels(std::list<AAlien *> &aliens)
{
	static int level = 0;

	if (aliens.size() == 0)
	{
		switch (level)
		{
		case 0:
			Level0(aliens);
			break;
		case 1:
			Level1(aliens);
			break;
		case 2:
			Level2(aliens);
			break;
		case 3:
			Level3(aliens);
			break;
		}
		level++;
	}
}

#endif