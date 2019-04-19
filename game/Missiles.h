#pragma once
#include "Missile.h"
#include "Squadron.h"
#include <list>

//===========================================
// Class Missiles
// Creates a list of Missiles
// Allows manipulation of a list of Missiles
//===========================================
class Missiles
{
	private:
		list <Missile> missiles;	// A list of missiles
		Squadron *red;				// A pointer to a Squadron
	public:
		//===========================================
		// Constructor
		// Requires a Squadron
		// Allows Missiles to interact with a Squadron
		//===========================================
		Missiles(Squadron* a)
		{
			red = a;
		}
		
		//===========================================
		// Name: move
		// Parameters: None
		// Returns: None
		// Purpose: Move an entire list of missiles
		//===========================================
		void move()
		{
			list<Missile>::iterator iter;
			for (iter = missiles.begin(); iter != missiles.end(); iter++)
			{
				(*iter).move();
			}
		}

		//===========================================
		// Name: collision
		// Parameters: None
		// Returns: An int
		// Purpose: Detect a collision between a
		//			missila and an alien
		//			Handle the collision
		//			Increase the player's score
		//===========================================
		int collision()
		{
			int score = 0;
			bool hold = false;
			list<Missile>::iterator iter;
			list <Alien>* point = red->getList();
			list<Alien>::iterator iter2;
			for (iter2 = point->begin(); iter2 != point->end();)
			{
				for (iter = missiles.begin(); iter != missiles.end();)
				{
					// Crashes on line 63 when no aliens are left in the list
					if ((*iter).getMissileBounds().intersects((*iter2).getAlienBounds())) // Crashes here
					{
						iter = missiles.erase(iter);
						iter2 = point->erase(iter2);
						score = 100;
						hold = true;
					}
					else
					{
						iter++;
					}
				}
				if (hold == false)
				{
					iter2++;
				}
				hold = false;
			}
			return score;
		}

		//===========================================
		// Name: checkBoundary
		// Parameters: None
		// Returns: None
		// Purpose: Check if a missile goes off screen
		//===========================================
		void checkBoundary()
		{
			list<Missile>::iterator iter;
			for (iter = missiles.begin(); iter != missiles.end();)
			{
				if ((*iter).getMissilePosition().y <= 0)
				{
					iter = missiles.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		//===========================================
		// Name: getList
		// Parameters: None
		// Returns: A pointer to a list of missiles
		// Purpose: Get a list of missiles
		//===========================================
		list <Missile>* getList()
		{
			return &missiles;
		}

		//===========================================
		// Name: getSizeOfList
		// Parameters: None
		// Returns: An int
		// Purpose: Get the size of the list of missiles
		//===========================================
		int getSizeOfList()
		{
			return missiles.size();
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display a missile in motion
		//===========================================
		void display(RenderWindow& win)
		{
			list<Missile>::iterator iter;
			for (iter = missiles.begin(); iter != missiles.end(); iter++)
			{
				((*iter).display(win));
				(*iter).move();
			}
		}
};