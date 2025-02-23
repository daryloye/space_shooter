#include "Player.hpp"
#include "Laser.hpp"
#include "Alien.hpp"
#include "Levels.hpp"
#include "Settings.hpp"

bool gameOver = false;
int gameTick = 0;

Player *p1 = new Player(width / 2, height - 2);
std::list<Laser*> lasers;
std::list<AAlien*> aliens;

void Setup()
{
	initscr();			   // initialise screen
	cbreak();			   // disable line buffering, player don't need to press ENTER to input
	noecho();			   // don't echo input
	keypad(stdscr, TRUE);  // enable special keys
	nodelay(stdscr, TRUE); // getch() won't wait for player input
	
	srand(time(NULL));
}

void Draw()
{
	clear();

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			mvaddch(y, x, SPACE);

			// draw walls
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
				mvaddch(y, x, WALL);

			// draw player
			if (p1->isPlayer(x, y))
				mvaddch(y, x, PLAYER);

			// draw Laser
			for (std::list<Laser*>::const_iterator iter = lasers.begin(); iter != lasers.end(); ++iter)
			{
				if ((*iter)->isLaser(x, y))
					mvaddch(y, x, LASER);
			}

			// draw Aliens
			for (std::list<AAlien*>::const_iterator iter = aliens.begin(); iter != aliens.end(); ++iter)
			{
				if ((*iter)->isAlien(x, y))
					mvaddch(y, x, (*iter)->getAscii());
			}
		}
	}
}

void End()
{
	printw("\n\nGAME OVER");
	refresh();
	gameOver = true;
	napms(2000);
}

void Logic()
{
	// check if alien has reached the bottom
	for (std::list<AAlien*>::const_iterator iterA = aliens.begin(); iterA != aliens.end();)
	{
		int alienX = (*iterA)->getPositionX();
		int alienY = (*iterA)->getPositionY();

		if ( alienY == height - 1)
		{
			End();
			return;
		}

		for (std::list<Laser*>::const_iterator iterL = lasers.begin(); iterL != lasers.end();)
		{
			if ( alienX == (*iterL)->getPositionX() && alienY == (*iterL)->getPositionY() )
			{

				delete *iterL;
				iterL = lasers.erase(iterL);
				if ((*iterA)->isDead())
				{
					delete *iterA;
					iterA = aliens.erase(iterA);
				}
			}
			else
				++iterL;
		}
		++iterA;
	}
}

void Input()
{
	int ch = getch();
	if (ch == ERR)
		return;

	switch (ch) // get ascii char of key
	{
	case 'a':
		p1->setDirectionLeft();
		break;
	case 'd':
		p1->setDirectionRight();
		break;
	case ' ':
		lasers.push_back(new Laser(p1->getPositionX(), p1->getPositionY()));
		break;
	}
}

void Move()
{
	gameTick = (gameTick + 1) % 10;
	
	// move player
	p1->move();

	// move laser
	for (std::list<Laser*>::const_iterator iter = lasers.begin(); iter != lasers.end();)
	{
		if (!(*iter)->move())
		{
			delete *iter;
			iter = lasers.erase(iter);
		}
		else
			++iter;
	}

	// move aliens
	if (gameTick == 1)
	{
		for (std::list<AAlien*>::const_iterator iter = aliens.begin(); iter != aliens.end(); iter++)
		{
			(*iter)->move();
			(*iter)->action();
		}
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Move();
		Logic();
		Levels(aliens);
		napms(refreshRate);
		refresh();
	}
	endwin();

	delete p1;

	return 0;
}
