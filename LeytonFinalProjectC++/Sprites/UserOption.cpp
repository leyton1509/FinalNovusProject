#include <allegro5/allegro_font.h>
#include "../Sprites/Button.h"

// A class which will allow the user to press an option
class UserOption {

public:

	// The buttons for the options. Max of 6 options
	Button buttonOptions[6];
	// The font to write with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

	UserOption(int numberOfOptions, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		if (numberOfOptions < 6) {

			for (int i = 0; i < numberOfOptions; i++)
			{
				buttonOptions[i] = Button(128, 128, 10, 480, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png", i);

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

				}

			}

		}
		
	}
};