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

		if (numberOfOptions < 6) {

			for (int i = 0; i < numberOfOptions; i++)
			{
				buttonOptions[i] = Button(128, 128, 10, 480, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png", i);

			}



		}
		
	}
};