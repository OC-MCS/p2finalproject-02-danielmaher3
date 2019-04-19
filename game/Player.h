#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "Missiles.h"

//===========================================
// Class Player
// Creates a Player object
// A Player knows: It's x-y position
//				   It's score
//                 The number of lives it has
//                 What it looks like
//===========================================
class Player
{
	private:
		int life;			// The number of lives the player has
		int score;			// The score of the player
		Sprite ship;		// A visual representation of the player
		Texture shipTexture;
	public:
		//===========================================
		// Constructor
		// Initializes variables to the base case
		// The player satrts with three lives
		// The player starts with a score of zero
		//===========================================
		Player()
		{
			life = 3;
			score = 0;
			setShipPosition();
			if (!shipTexture.loadFromFile("fighter.png"))
			{
				cout << "Unable to load fighter texture!" << endl;
				exit(EXIT_FAILURE);
			}

			ship.setTexture(shipTexture);
		}

		//===========================================
		// Name: getLife
		// Parameters: None
		// Returns: An integer
		// Purpose: Get the current number of lives
		//===========================================
		int getLife()
		{
			return life;
		}

		//===========================================
		// Name: getScore
		// Parameters: None
		// Returns: An integer
		// Purpose:  Get the current score
		//===========================================
		int getScore()
		{
			return score;
		}

		//===========================================
		// Name: geSprite
		// Parameters: None
		// Returns: A Sprite
		// Purpose: Get the player's sprite information
		//===========================================
		Sprite& getSprite()
		{
			return ship;
		}

		//===========================================
		// Name: getShipPosition
		// Parameters: None
		// Returns: A Vector2f
		// Purpose: Get the ship's x and y location
		//===========================================
		Vector2f getShipPosition()
		{
			return ship.getPosition();
		}

		//===========================================
		// Name: getShipBounds
		// Parameters: None
		// Returns: A FloatRect
		// Purpose: Get the ship's bounds
		//===========================================
		FloatRect getShipBounds()
		{
			return ship.getGlobalBounds();
		}

		//===========================================
		// Name: lifeCounter
		// Parameters: An integer
		// Returns: The number of lives remaining
		// Purpose: Decrement the number of lives
		//===========================================
		int lifeCounter()
		{
			life--;
			return life;
		}

		//===========================================
		// Name: scoreCounter
		// Parameters: An integer
		// Returns: The new score as an integer
		// Purpose: Increment the player's score
		//===========================================
		void scoreCounter(int s)
		{
			score += s;
		}

		//===========================================
		// Name: fireMissile
		// Parameters: A list of Missiles
		// Returns: None
		// Purpose: Show a missile being fired
		//===========================================
		void fireMissile(Missiles& hit)
		{
			Missile *temp = nullptr;
			temp = new Missile;
			temp->setMissilePosition(getShipPosition());
			hit.getList()->push_back((*temp));
			cout << hit.getSizeOfList() << endl;
			delete temp;
		}

		//===========================================
		// Name: moveX
		// Parameters: None
		// Returns: None
		// Purpose: Determine which way and how far
		//			to move the ship
		//===========================================
		void moveX()
		{
			const float DISTANCE = 5.0;

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
					getSprite().move(-DISTANCE, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				getSprite().move(DISTANCE, 0);
			}
		}

		//===========================================
		// Name: checkShipBounds
		// Parameters: None
		// Returns: None
		// Purpose: Ensure the ship satys fully on screen
		//===========================================
		void checkShipBounds()
		{
			Vector2f qwerty = getSprite().getPosition();
			if (qwerty.x < 0) 
			{
				qwerty.x = 0;
				getSprite().setPosition(qwerty);
			}
			else if (qwerty.x > 755)
			{
				qwerty.x = 755;
				getSprite().setPosition(qwerty);
			}
		}

		//===========================================
		// Name: setShipPosition
		// Parameters: None
		// Returns: None
		// Purpose: Set the ship's position in the
		//			middile of the bottom of the screen.
		//===========================================
		void setShipPosition()
		{
			float shipX = 800 / 2.0f;
			float shipY = 1100 / 2.0f;
			ship.setPosition(shipX, shipY);
		}

		//===========================================
		// Name: display
		// Parameters: A window
		// Returns: None
		// Purpose: Display the ship 
		//===========================================
		void display(RenderWindow& win)
		{

			win.draw(ship);
		}
		
};