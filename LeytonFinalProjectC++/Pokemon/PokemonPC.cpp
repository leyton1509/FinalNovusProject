#include "../Sprites/PlayerCharacter.h"

#include "../Sprites/SwitchPokemonPCButton.h"

class PokemonPC {

	SwitchPokemonPCButton boxButtons[30];

public:

	void displaySprites(Pokemon box[]) {

		for (int i = 0; i < 30; i++)
		{
			boxButtons[i].drawSprite(box[i]);
		}
	}

	void destroySprites() {


		for (int i = 0; i < 30; i++)
		{			
			boxButtons[i].destroySprite();
		}
	}

	PokemonPC(PlayerCharacter & player, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		int startXPositon = 10;
		int startYPosition = 10;
		int counter = 0;

		// BG sprite
		ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/Background.png");

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				boxButtons[counter] = SwitchPokemonPCButton(64, 64, startXPositon + (i * 90), startYPosition + (j * 90), 80, 80);
				counter++;
			}

		}

		double xMousePosition = 0;
		double yMousePosition = 0;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		

	}
};