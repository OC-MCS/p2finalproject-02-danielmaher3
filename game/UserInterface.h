#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;
using namespace sf;

//===========================================
// Class UI (User Interface)
// Displays all menus
// Displays all labels
// Displays all text
// Handles mouse clicking
//===========================================
class UI
{
	private:
		RectangleShape rec;				// A rectangulat button
		RectangleShape hiddenButton;	// A rectangular button
		Text menu;						// Menu variable
		Text start;						// Word 'Start'
		Text level;						// Word 'Level'
		Text score;						// Word 'Score'
		Text lives;						// Word 'Lives'
		Text scoreCount;				// The score of the player
		Text lifeCount;					// The number of player lives
		Text levelCount;				// The current level
		Font font;						// The font
		Player count;					// An instance of Player
	public:
		//===========================================
		// Constructor
		// Load Font from file
		// Sets buttons
		// Sets labels
		// Sets text
		//===========================================
		UI()
		{
			font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
			rec.setFillColor(Color::Green);
			rec.setSize(Vector2f(30, 30));
			rec.setPosition(385, 285);
			hiddenButton.setFillColor(Color::Red);
			hiddenButton.setSize(Vector2f(20, 20));
			hiddenButton.setPosition(515, 0);
			menu.setFont(font);
			menu.setPosition(400, 0);
			menu.setString("MENU");
			start.setFont(font);
			start.setPosition(420, 320);
			start.setString("START");
			level.setFont(font);
			level.setPosition(0, 0);
			level.setString("LEVEL: ");
			score.setFont(font);
			score.setPosition(350, 0);
			score.setString("SCORE: ");
			lives.setFont(font);
			lives.setPosition(650, 0);
			lives.setString("LIVES: ");
			levelCount.setFont(font);
			levelCount.setPosition(115, 0);
			scoreCount.setFont(font);
			scoreCount.setPosition(465, 0);
			lifeCount.setFont(font);
			lifeCount.setPosition(765, 0);
		}

		//===========================================
		// Name: displayMenu
		// Parameters: A window
		// Returns: None
		// Purpose: Displays the main menu
		//===========================================
		void displayMenu(RenderWindow& win)
		{
			win.draw(rec);
			win.draw(hiddenButton);
			win.draw(menu);
			win.draw(start);
		}

		//===========================================
		// Name: displayLabels
		// Parameters: A window
		// Returns: None
		// Purpose: Displays the labels
		//===========================================
		void displayLabels(RenderWindow& win)
		{
			win.draw(level);
			win.draw(score);
			win.draw(lives);
		}

		//===========================================
		// Name: displayLives
		// Parameters: Int, window
		// Returns: None
		// Purpose: Displays the number of player lives remaining
		//===========================================
		void displayLives(int p, RenderWindow& win)
		{
			p = count.getLife();
			string s = to_string(p);
			lifeCount.setString(s);
			win.draw(lifeCount);
		}

		//===========================================
		// Name: displayLevel
		// Parameters: Int, window
		// Returns: None
		// Purpose: Displays the level counter
		//===========================================
		void displayLevel(int l, RenderWindow& win)
		{
			string s = to_string(l);
			levelCount.setString(s);
			win.draw(levelCount);
		}

		//===========================================
		// Name: displayScore
		// Parameters: A Player, window
		// Returns: None
		// Purpose: Displays the player's score
		//===========================================
		void displayScore(Player& p, RenderWindow& win)
		{
			
			int ps = p.getScore();
			string s = to_string(ps);
			scoreCount.setString(s);
			win.draw(scoreCount);
		}

		//===========================================
		// Name: displaydefeat
		// Parameters: A Player
		// Returns: None
		// Purpose: Displays the defeat screen
		//===========================================
		void displayDefeat(Player p)
		{
			cout << "Game over" << endl;
			cout << "Your score: " << p.getScore() << endl;
		}
		
		//===========================================
		// Name: displayEasterEgg
		// Parameters: A window
		// Returns: None
		// Purpose: Displays the easter egg message
		//===========================================
		void displayEaserEgg(RenderWindow& win)
		{
			Text name;
			Text cookieMessage;
			Text smileyFace;
			Text q;

			name.setFont(font);
			name.setString("My name is Daniel Maher and I created this cruddy game.");
			name.setPosition(233, 0);

			cookieMessage.setFont(font);
			cookieMessage.setString("I like cookies. Om nom nom.");
			cookieMessage.setPosition(233, 77);

			smileyFace.setFont(font);
			smileyFace.setString(":)");
			smileyFace.setPosition(777, 333);

			q.setFont(font);
			q.setString("Can you find the smiley face?");
			q.setPosition(233, 154);

			win.draw(name);
			win.draw(cookieMessage);
			win.draw(smileyFace);
			win.draw(q);
		}

		//===========================================
		// Name: handleMouseUp
		// Parameters: A Vector2f
		// Returns: A bool
		// Purpose: Check if the mouse clicked the start button
		//===========================================
		bool handleMouseUp(Vector2f mousePos)
		{
			return rec.getGlobalBounds().contains(mousePos);
		}

		//===========================================
		// Name: handleMouseUpForHiddenButton
		// Parameters: A Vector2f
		// Returns: A bool
		// Purpose: Check if the mouse clicked the hidden button
		//===========================================
		bool handleMouseUpForHiddenButton(Vector2f mousePos)
		{
			return hiddenButton.getGlobalBounds().contains(mousePos);
		}
};