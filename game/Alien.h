#pragma once
#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Bombs.h"

//===========================================
// Struct Position
// Two integers
// Holds the x and y position of an Alien object
//===========================================
struct Position
{
	int posX;
	int posY;
};

//===========================================
// Class Alien
// Creates an Alien object
// An Alien knows: It's x-y position
//				   What it looks like
//===========================================
class Alien
{
	private:
		Position pos;			// A structure variable holding the x-y position
		Sprite alien;			// A visual representation of an alien
		Texture alienTexture;	// The Alien texture
	public:
		//============================================
		// Constructor
		// Initializes variables to the base case
		// This will set the alien sprite
		// This will also determine the initial
		// position of an alien
		//============================================
		Alien()
		{
			alien.setPosition(200, 200);
			pos.posX = 200;
			pos.posY = 200;
			if (!alienTexture.loadFromFile("Alien.png"))
			{
				cout << "Unable to load Alien texture!" << endl;
				exit(EXIT_FAILURE);
			}

			alien.setTexture(alienTexture);
		}

		//===========================================
		// Name: fireBomb
		// Parameters: A FloatRect, A Sprite
		// Returns: None
		// Purpose: Show a bomb being fired
		//===========================================
		void fireBomb(FloatRect p, Bombs& mis)
		{
			Bomb *temp = nullptr;
			temp = new Bomb;
			temp->setBombPosition(getAlienPosition());
			mis.getList()->push_back((*temp));
			delete temp;
			mis.collision(p);
		}

		//===========================================
		// Name: getPositionX
		// Parameters: None
		// Returns: An integer
		// Purpose: Get the current x-position
		//===========================================
		int getPositionX()
		{
			return pos.posX;
		}

		//===========================================
		// Name: getPositionY
		// Parameters: None
		// Returns: An integer
		// Purpose: Get the current y-position
		//===========================================
		int getPositionY()
		{
			return pos.posY;
		}

		//===========================================
		// Name: getAlienPosition
		// Parameters: None
		// Returns: A Vector2f
		// Purpose: Get the alien's current position
		//===========================================
		Vector2f getAlienPosition()
		{
			return alien.getPosition();
		}

		//===========================================
		// Name: setAlienPosition
		// Parameters: Float, Float
		// Returns: A Vector2f
		// Purpose: Set the alien's position
		//===========================================
		Vector2f setAlienPosition(float x, float y)
		{
			alien.setPosition(x, y);
			return alien.getPosition();
		}

		//===========================================
		// Name: getAlienBounds
		// Parameters: None
		// Returns: FloatRect
		// Purpose: Get the alien's global bounds
		//===========================================
		FloatRect getAlienBounds()
		{
			return alien.getGlobalBounds();
		}

		//===========================================
		// Name: getSprite
		// Parameters: None
		// Returns: A Sprite
		// Purpose: Get the Alien sprite
		//===========================================
		Sprite& getSprite()
		{
			return alien;
		}

		//===========================================
		// Name: moveY
		// Parameters: None
		// Returns: None
		// Purpose: Move an Alien downward
		//===========================================
		void moveY()
		{
			float disY = .05;
			alien.move(0, disY);
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display an alien
		//===========================================
		void display(RenderWindow& win)
		{
			alien.setTexture(alienTexture);
			win.draw(alien);
		}
};



