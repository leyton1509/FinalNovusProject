#include <allegro5/allegro_font.h>
#include <list>
#include <string>
#include "../Sprites/Spriteheader.h"
#include <iostream>

// Class to display text to the user in the over world
class TextBox : public Sprite {

public: 

	// Original X Size of image
	int originalSizeX;
	// Original Y Size of image
	int originalSizeY;
	// The font to display with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);


	// Constructor for text box
	TextBox(std::list<std::string> textToDisplay, int _width, int _height, ALLEGRO_EVENT_QUEUE* queue) : Sprite (SpriteType::SpriteTypes::Button, 10, 360, _width, _height, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png"){
			
		// The size of sprite
		
		originalSizeX = 256;
		originalSizeY = 96;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		// Whether the loop has finihed
		bool finishedStrings = false;

		// The number of strings in the list
		int stringCount = 0;
		// The current string
		int currentString = 0;

		// Calcs the num of strings
		for (const std::string& currentS : textToDisplay)
		{
			stringCount++;
		}

		// Counter for how many clicks
		int counter = 0;

		// ALLEGRO control loop
		while (!finishedStrings) {

			al_wait_for_event(queue, &event);
		
			switch (event.type)
			{

			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				break;

			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				finishedStrings = true;
				break;
				

			case ALLEGRO_EVENT_KEY_UP:	
				// The counter var, need to interact once before it increases the string 
				if(counter == 0) {
					counter++;
				}
				else {
					if (currentString < stringCount-1) {
						currentString++;
					}
					else {
						// Finishes when it gets to the end of the strings
						done = true;
						finishedStrings = true;
						break;
					}
				}
			}

			if (done)
				break;

			if (redraw && al_is_event_queue_empty(queue))
			{
				// Draws a text box with the current string
				int cString = 0;
				for (const std::string& currentS : textToDisplay)
				{
					if (cString == currentString) {
						drawSprite(currentS);
						break;
					}
					cString++;
				}
				al_flip_display();
			}
		}
	}

	// Works the exact same as the other but specifies the x and y pos
	// Constructor for text box with the specified x and y pos
	TextBox(int _xPosition, int _yPosition, std::list<std::string> textToDisplay, int _width, int _height, ALLEGRO_EVENT_QUEUE* queue) : Sprite(SpriteType::SpriteTypes::Button, 10, 360, _width, _height, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png") {
		originalSizeX = 256;
		originalSizeY = 96;
		xPosition = _xPosition;
		yPosition = _yPosition;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		// If all strings have been displayed or not
		bool finishedStrings = false;

		// Current string and string count
		int stringCount = 0;
		int currentString = 0;


		for (const std::string& currentS : textToDisplay)
		{
			stringCount++;
		}

		int counter = 0;

		// Basic allegro control loop
		while (!finishedStrings) {

			al_wait_for_event(queue, &event);

			switch (event.type)
			{

			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				break;

			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				// Finish the loop
				done = true;
				finishedStrings = true;
				break;


			case ALLEGRO_EVENT_KEY_UP:
				// Checks to see if to progress in current string or finish the loop
				if (counter == 0) {
					counter++;
				}
				else {
					if (currentString < stringCount - 1) {
						currentString++;
					}
					else {
						done = true;
						finishedStrings = true;
						break;
					}
				}
			}

			if (done)
				break;

			// Draws the srites
			// Draws the correct string in the textbox
			if (redraw && al_is_event_queue_empty(queue))
			{
				int cString = 0;
				for (const std::string& currentS : textToDisplay)
				{
					if (cString == currentString) {
						drawSprite(currentS);
						break;
					}
					cString++;
				}
				al_flip_display();
			}
		}
	}

	// Draws the sprite with the string
	void drawSprite(std::string currentString) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), (xPosition + 17), (yPosition + 15), 0, (currentString).c_str());

	}

	// Destroys all the sprites 
	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
	}
};