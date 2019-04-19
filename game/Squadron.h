#pragma once
#include "Alien.h"
#include "Bombs.h"
#include <list>
#include <cstdlib>
#include <ctime>

//===========================================
// Class Squadron
// Creates a list of Aliens
// Allows manipulation of a list of Aliens
//===========================================
class Squadron
{
	private:
		list <Alien> aliens;		// A list of Aliens
		Bombs bombs;				// A bombs list
	public:
		//===========================================
		// Constructor
		// Fills the list of Aliens
		//===========================================
		Squadron()
		{
			fillList();
		}
		
		//===========================================
		// Name: fire
		// Parameters: FloatRect
		// Returns: None
		// Purpose: Show a bomb being fired
		//===========================================
		void fire(FloatRect p)
		{
			int f = random(aliens.size());
			list <Alien>::iterator it;
			it = aliens.begin();
			if (aliens.size() != 0)
			{
				advance(it, f);
				if (rand() % 10 == 0)
				{
					(*it).fireBomb(p, bombs);
				}
			}
		}

		//===========================================
		// Name: random
		// Parameters: Int
		// Returns: An int
		// Purpose: Get a random number
		//===========================================
		int random(int size)
		{
			int r;
			unsigned t = time(0);
			srand(t);
			if (size == 0)
			{
				r = 0;
			}
			else
			{
				r = rand() % size;
			}
			return r;
		}

		//===========================================
		// Name: moveGroup
		// Parameters: None
		// Returns: None
		// Purpose: Move a Squadron
		//===========================================
		void moveGroup()
		{
			bombs.move();
			list<Alien>::iterator iter;
			for (iter = aliens.begin(); iter != aliens.end(); iter++)
			{
				(*iter).moveY();
			}
		}

		//===========================================
		// Name: displaySquadron
		// Parameters: A window
		// Returns: None
		// Purpose: Display a Squadron in motion
		//===========================================
		void displaySquadron(RenderWindow& win)
		{
			bombs.display(win);
			list<Alien>::iterator iter;
			for (iter = aliens.begin(); iter != aliens.end(); iter++)
			{
				(*iter).display(win);
			}
		}

		//===========================================
		// Name: getList
		// Parameters: None
		// Returns: A pointer to a list of alien's addresses
		// Purpose: Get the aliens in the list
		//===========================================
		list <Alien>* getList()
		{
			return &aliens;
		}

		//===========================================
		// Name: fillList
		// Parameters: None
		// Returns: None
		// Purpose: Fill the Squadron
		//===========================================
		void fillList()
		{
			float x = 50;
			float y = 100;

			for (int i = 0; i < 10; i++)
			{
				Alien *temp = new Alien;
				(*temp).setAlienPosition(x, y);
				aliens.push_back(*temp);
				delete temp;
				x = x + 69;
			}
		}

		//===========================================
		// Name: clearScreen
		// Parameters: None
		// Returns: None
		// Purpose: Clear the currnet list
		//===========================================
		void clearScreen()
		{
			aliens.clear();
		}

};