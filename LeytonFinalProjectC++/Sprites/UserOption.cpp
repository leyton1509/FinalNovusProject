#include <allegro5/allegro_font.h>
#include "../Sprites/Button.h"
#include <list>

// A class which will allow the user to press an option
class UserOption {

public:

	// The buttons for the options. Max of 6 options
	Button buttonOptions[6];
	// The font to write with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 22, NULL);
	// The value of the result
	int valueOfResult;

	// The constructor for user option, takes a header text, the strings for the buttons, the number of opptions, dimensions and queue
	UserOption(std:: string headerText , std::list<std::string> onButtonString, int numberOfOptions, int buttonWidth, int buttonHeight , int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		valueOfResult = -1;

		// Checks to see if the n of options is less than 6
		if (numberOfOptions < 6) {

			// Starting position of options
			int xStartPos = 10;
			int yStartPos = screenHeight / 2 - (buttonHeight * numberOfOptions) + 10;

			// GUI info
			bool done = false;
			bool redraw = true;
			ALLEGRO_EVENT event;

			// Position of moise
			double xMousePosition = 0;
			double yMousePosition = 0;

			// Creates the buttons
			for (int i = 0; i < numberOfOptions; i++)
			{
				buttonOptions[i] = Button(256, 96, xStartPos, yStartPos + (buttonHeight * i) + (i * 10), buttonWidth, buttonHeight, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png", i);

			}

			// If the val has been selected
			// Creates the GUI controller
			bool selectedVal = false;

			while (!selectedVal) {

				al_wait_for_event(queue, &event);

				switch (event.type)
				{
				case ALLEGRO_EVENT_MOUSE_AXES:
					xMousePosition = event.mouse.x;
					yMousePosition = event.mouse.y;
					break;
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					break;

				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					done = true;
					selectedVal = true;
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
					// Checks through the buttons and returns the option clicked
					for (int i = 0; i < numberOfOptions; i++)
					{
						if (buttonOptions[i].hasBeenClicked(xMousePosition, yMousePosition)) {
							valueOfResult = i;
							done = true;
							selectedVal = true;
						}
					}
					break;
				}

				// Breaks the loop if done
				if (done)
					break;

				// Draws the screen
				if (redraw && al_is_event_queue_empty(queue))
				{
					// Draws the text
					al_draw_text(font, al_map_rgb(255, 255, 255), xStartPos, yStartPos - buttonHeight, 0, (headerText).c_str());

					// Draws the buttons with the correct string
					for (int i = 0; i < numberOfOptions; i++)
					{
						int cString = 0;
						for (const std::string& currentS : onButtonString)
						{
							if (cString == i) {
								buttonOptions[i].drawSprite(currentS);
								break;
							}
							cString++;
						}
						
					}
					al_flip_display();
				}

			}

		}
		
	}
};