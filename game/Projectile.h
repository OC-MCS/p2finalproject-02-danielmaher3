#pragma once

//==========================================
// Class Projectile
// Projectile is an abstract base class
// for Alien bombs and Player missiles
//==========================================
class Projectile
{
	private:
		int posY;	// X-position of the projectile
		int posX;	// Y-position of the projectile
	public:
		//===========================================
		// Constructor
		// Initializes variables to the base case
		// X is whatever is passed
		// Y is whatever is passed
		//===========================================
		Projectile(int x, int y)
		{
			posX = x;
			posY = y;
		}
		// A move function
		virtual void move() = 0;
		// A check for collision function
		virtual bool collision() = 0;
};