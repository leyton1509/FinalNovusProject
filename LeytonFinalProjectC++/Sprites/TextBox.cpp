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
	TextBox(std::list<std::string> textToDisplay, int _width, int _height, ALLEGRO_EVENT_QUEUE* queue) : Sprite (SpriteType::SpriteTypes::Button, 10, 330, _width, _height, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png"){
		originalSizeX = 256;
		originalSizeY = 96;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		bool finishedStrings = false;

		int stringCount = 0;
		int currentString = 0;


		for (const std::string& currentS : textToDisplay)
		{
			stringCount++;
		}

		int counter = 0;

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
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

				std::cout << "Current string : " << currentString << " Max : " << stringCount << "\n";
				if (counter == 0) {
					counter++;
				}
				else {
					if (currentString < stringCount) {
						currentString++;
					}
					else {
						done = true;
						finishedStrings = true;
						break;
					}
				}
				

			case ALLEGRO_EVENT_KEY_UP:	
				std::cout << "Current string : " << currentString << " Max : " << stringCount << "\n";
				if(counter == 0) {
					counter++;
				}
				else {
					if (currentString < stringCount) {
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
		al_draw_text(font, al_map_rgb(255, 255, 255), (xPosition + 20), (yPosition + 10), 0, (currentString).c_str());

	}

	// Destroys all the sprites 
	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
	}
};