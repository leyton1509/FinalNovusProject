#include <allegro5/allegro_font.h>
#include "../Sprites/Button.h"
#include <list>

// A class which will allow the user to press an option
class UserOption {

public:

	// The buttons for the options. Max of 6 options
	Button buttonOptions[6];
	// The font to write with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

	int valueOfResult;

	UserOption(std:: string headerText , std::list<std::string> onButtonString, int numberOfOptions, int buttonWidth, int buttonHeight , int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		valueOfResult = -1;

		if (numberOfOptions < 6) {

			int xStartPos = screenWidth - buttonWidth * 1.05;
			int yStartPos = screenHeight / 2 - (buttonHeight * numberOfOptions);


			Button header =  Button(128, 128, xStartPos, yStartPos - 10 - buttonHeight, buttonWidth, buttonHeight, "../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png", i);

			// GUI info
			bool done = false;
			bool redraw = true;
			ALLEGRO_EVENT event;

			// Position of moise
			double xMousePosition = 0;
			double yMousePosition = 0;

			for (int i = 0; i < numberOfOptions; i++)
			{
				buttonOptions[i] = Button(128, 128, xStartPos, yStartPos + (buttonHeight * i) + (i * 10), buttonWidth, buttonHeight, "../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png", i);

			}



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

				if (done)
					break;

				if (redraw && al_is_event_queue_empty(queue))
				{
					header.drawSprite(headerText);

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