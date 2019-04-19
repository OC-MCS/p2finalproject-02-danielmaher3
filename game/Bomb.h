#pragma once
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

//===========================================
// Class Bomb
// Creates a Bomb object
// A Bomb knows: It's Sprite
//               What it looks like
//===========================================
class Bomb
{
	private:
		Sprite bomb;			// Sprite Bomb
		Texture bombTexture;	// The bomb texture
	public:
		//===========================================
		// Constructor
		// Checks if the bomb texture gets loaded
		// Sets bomb texture
		//===========================================
		Bomb()
		{
			if (!bombTexture.loadFromFile("Bomb.png"))
			{
				cout << "Unable to load Bomb texture!" << endl;
				exit(EXIT_FAILURE);
			}

			bomb.setTexture(bombTexture);
		}

		//===========================================
		// Name: move
		// Parameters: None
		// Returns: None
		// Purpose: Move a bomb downward
		//===========================================
		void move()
		{
			bomb.move(0, 6);
		}

		//===========================================
		// Name: getBombPosition
		// Parameters: None
		// Returns: A Vector2f
		// Purpose: Get the missile's x and y location
		//===========================================
		Vector2f getBombPosition()
		{
			return bomb.getPosition();
		}

		//===========================================
		// Name: getGLobalBounds
		// Parameters: None
		// Returns: A FloatRect
		// Purpose: Get the bomb's bounds
		//===========================================
		FloatRect getGlobalBounds()
		{
			return bomb.getGlobalBounds();
		}

		//===========================================
		// Name: setBombPosition
		// Parameters: A Vector2f
		// Returns: None
		// Purpose: Set the bomb's position
		//===========================================
		void setBombPosition(Vector2f pos)
		{
			bomb.setPosition(pos);
		}

		//===========================================
		// Name: setBombosition
		// Parameters: Float, Float
		// Returns: None
		// Purpose: Set the bomb's position
		//===========================================
		void setBombPosition(float posX, float posY)
		{
			bomb.setPosition(posX, posY);
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display a bomb
		//===========================================
		void display(RenderWindow& win)
		{
			win.draw(bomb);
		}
};