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

		//Reset the camera
		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);

		bool finishedInPC = false;

		while (!finishedInPC) {

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
				finishedInPC = true;
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

				break;
			}

			if (done)
				break;

			if (redraw && al_is_event_queue_empty(queue))
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_scaled_bitmap(background, 0, 0, 321, 240, 0, 0, screenWidth, screenHeight, 0);
				al_flip_display();
			}


		}

	}
};