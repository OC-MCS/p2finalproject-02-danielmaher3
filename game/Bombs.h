#pragma once
#include "Bomb.h"
#include <list>

//===========================================
// Class Bombs
// Creates a list of Bombs
// Allows manipulation of a list of Bombs
//===========================================
class Bombs
{
	private:
		list <Bomb> bombs;	// A list og bombs
	public:
		//===========================================
		// Name: move
		// Parameters: None
		// Returns: None
		// Purpose: Move an entire list of bombs
		//===========================================
		void move()
		{
			list<Bomb>::iterator iter;
			for (iter = bombs.begin(); iter != bombs.end();)
			{
				(*iter).move();
				if ((*iter).getBombPosition().y >= 600)
				{
					iter = bombs.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		//===========================================
		// Name: collision
		// Parameters: FlaotRect
		// Returns: None
		// Purpose: Detect a collision between a
		//			bomb and the player
		//			Handle the collision
		//===========================================
		void collision(FloatRect p)
		{
			bool hold = false;
			list<Bomb>::iterator iter;
			for (iter = bombs.begin(); iter != bombs.end(); )
			{
				
				if ((*iter).getGlobalBounds().intersects(p))
				{
					iter = bombs.erase(iter);
					hold = true;
				}
				else if (hold == false)
				{
					iter++;
				}
				else
				{
					hold = false;
				}
			}

		}

		//===========================================
		// Name: getList
		// Parameters: None
		// Returns: A pointer to a list of bombs
		// Purpose: Get a list of bombs
		//===========================================
		list <Bomb>* getList()
		{
			return &bombs;
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display a bomb in motion
		//===========================================
		void display(RenderWindow& win)
		{
			list<Bomb>::iterator iter;
			for (iter = bombs.begin(); iter != bombs.end(); iter++)
			{
				(*iter).display(win);
			}
		}

};