#pragma once
#include "Player.h"
#include "Squadron.h"
#include "Missile.h"
#include "Bomb.h"
#include "UserInterface.h"
using namespace std;

//===========================================
// Class Level
// Creates a Level object
// Allows manipulation of the game
// A Level knows: It's Number
//===========================================
class Level
{
	private:
		int level;			// The level number
		UI sweg;			// UI instance
		Squadron group;		// Squadron instance
		Alien alien;		// Alien instance
	public:
		//===========================================
		// Constructor
		// Sets the level to the default level
		//===========================================
		Level()
		{
			level = 1;
		}
		
		//===========================================
		// Constructor
		// Sets the level to the desired level
		//===========================================
		Level(int l)
		{
			level = l;
		}

		int getLevel()
		{
			return level;
		}

		void incrementLevel()
		{
			level++;
		}

		bool checkVictory()
		{
			if (level == 2)
			{
				level = 1;
				return true;
			}
			else
			{
				return false;
			}
		}

		void checkDefeat(Player& p, Alien& a)
		{
			if (a.getAlienPosition().y >= p.getShipPosition().y)
			{
				playerLives(p);

			}
			else if (p.getLife() == 0)
			{
				sweg.displayDefeat(p);
			}
		}

		bool levelEnd()
		{
			bool hold = false;
			if (group.getList()->size() < 1)
			{
				incrementLevel();
				hold = true;
			}
			
			return hold;
		}

		void playerLives(Player& lives)
		{
			resetLevel();
			lives.lifeCounter();
			if (lives.getLife() == 0)
			{
				sweg.displayDefeat(lives);
			}
		}

		void resetLevel()
		{
			group.clearScreen();
			group.fillList();
		}
};