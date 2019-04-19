#pragma once
#include "Projectile.h"
#include "Alien.h"
#include <SFML/Graphics.hpp>

//===========================================
// Class Missile
// Creates a Missile object
// A Missile knows: It's Sprite
//                  What it looks like
//===========================================
class Missile
{
	private:
		Sprite missile;				// Sprite Missile
		Texture missileTexture;		// The missile texture
	public:
		//===========================================
		// Constructor
		// Checks if the missile texture gets loaded
		// Sets missile texture
		//===========================================
		Missile()
		{
			if (!missileTexture.loadFromFile("MyMissile.png"))
			{
				cout << "Unable to load MyMissile texture!" << endl;
				exit(EXIT_FAILURE);
			}

			missile.setTexture(missileTexture);
		}

		//===========================================
		// Name: move
		// Parameters: None
		// Returns: None
		// Purpose: Move a missile upward
		//===========================================
		void move()
		{
			missile.move(0, -6);
		}

		//===========================================
		// Name: getMissileBounds
		// Parameters: None
		// Returns: A FloatRect
		// Purpose: Get the missile's bounds
		//===========================================
		FloatRect getMissileBounds()
		{
			return missile.getGlobalBounds();
		}

		//===========================================
		// Name: getMissilePosition
		// Parameters: None
		// Returns: A Vector2f
		// Purpose: Get the missile's x and y location
		//===========================================
		Vector2f getMissilePosition()
		{
			return missile.getPosition();
		}

		//===========================================
		// Name: setMissilePosition
		// Parameters: A Vector2f
		// Returns: None
		// Purpose: Set the missile's position
		//===========================================
		void setMissilePosition(Vector2f pos)
		{
			 missile.setPosition(pos);
		}

		//===========================================
		// Name: setMissilePosition
		// Parameters: Float, Float
		// Returns: None
		// Purpose: Set the missile's position
		//===========================================
		void setMissilePosition(float posX, float posY)
		{
			missile.setPosition(posX, posY);
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display a missile
		//===========================================
		void display(RenderWindow& win)
		{
			win.draw(missile);
		}
};