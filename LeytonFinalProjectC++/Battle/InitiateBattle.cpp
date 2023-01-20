#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/PokemonManager.h"

class InitiateBattle {

public:

	InitiateBattle(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter player, int locationNumber, int battleType) {

		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		

		ALLEGRO_BITMAP * background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Plains.jpg");

		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);
		al_draw_bitmap(background, 0, 0, 0);

		ALLEGRO_BITMAP * otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
		ALLEGRO_BITMAP * trainsersPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/backSprites.png");

		PokemonManager pm = pm.instance();
		Pokemon otherPokemon = pm.getDefaultPokemon("Darkrai");

		bool battleFinished = false;

		if (battleType == 0) {
			// Wild encounter

			while (!battleFinished) {

				al_wait_for_event(queue, &event);

				switch (event.type)
				{
				case ALLEGRO_EVENT_TIMER:
					// game logic goes here.
					redraw = true;
					break;

				
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					done = true;
					battleFinished = true;
					break;
				}

				if (done)
					break;

				if (redraw && al_is_event_queue_empty(queue))
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_scaled_bitmap(background, 0, 0, 400, 225, 0, 0, screenWidth, screenHeight, 0);
					al_draw_scaled_bitmap(otherPokemonSprite, (80 * otherPokemon.xPositionOnSpriteSheet), (80 * otherPokemon.yPositionOnSpriteSheet), 80, 80, 100, 200, 240, 240, 0);

					al_flip_display();
					redraw = false;
				}

			}
		}

		
		else if (battleType == 1) {
			// Pokemon encounter

		}

		al_destroy_bitmap(background);
		al_destroy_bitmap(otherPokemonSprite);
		al_destroy_bitmap(trainsersPokemonSprite);
	}

};