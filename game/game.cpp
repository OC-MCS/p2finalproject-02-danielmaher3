//============================================================
// Daniel Maher
// Professor Harbert
// Project 8: Space Game
// Due: 4-19-2019
//============================================================
#include "Player.h"
#include "Alien.h"
#include "Squadron.h"
#include "Missile.h"
#include "Bomb.h"
#include "UserInterface.h"
#include "Level.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	Player player;				// INstance of Player
	Alien alien;				// Instance of Alien
	Squadron squad;				// Instance of Squadron
	Missiles ied(&squad);		// Instance of Missiles
	UI interact;				// User Interface object
	Level level;				// Level object
	bool game = false;			// Test for a button
	bool secret = false;		// :)
	int score = 0;				// Score of player
	int count = 0;				// Timer variable, incremented for every iteration of the animation loop

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// first time through set the player in the middle of the screen
	player.setShipPosition();

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;
		score = 0;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (game == false)
				{
					secret = interact.handleMouseUpForHiddenButton(mousePos);
					game = interact.handleMouseUp(mousePos);

					if (secret == true)
					{
						interact.displayEaserEgg(window);
					}
				}
			}
		}
		
		if (event.key.code == Keyboard::Space && count % 30 == 0)
		{
			player.fireMissile(ied);
		}
		
		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);
		if (!game)
		{
			interact.displayMenu(window);
		}
		// Run game
		else
		{
			player.display(window);
			squad.displaySquadron(window);
			player.moveX();
			player.checkShipBounds();
			squad.moveGroup();
			ied.display(window);
			if (count % 24 == 0)
			{
				squad.fire(player.getShipBounds());
			}
			score = ied.collision();
			player.scoreCounter(score);
			// bomb collision - can'tget it working
			interact.displayLabels(window);
			interact.displayLives(player.getLife(), window);
			interact.displayScore(player, window);
			interact.displayLevel(level.getLevel(), window);

			// level things
			// Not FUNCTIONAL
			if (level.levelEnd())
			{
				if (level.checkVictory())
				{
					cout << "Victory" << endl;
				}
				level.incrementLevel();
			}
			level.checkDefeat(player, alien);
		}

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		count++;
		window.display();
	} // end body of animation loop

	return 0;
}

