#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/PokemonManager.h"
#include "../Sprites/Button.h"

class InitiateBattle {

public:

	InitiateBattle(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter player, int locationNumber, int battleType) {

		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		

		ALLEGRO_BITMAP * background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Graveyard.jpg");

		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);
		al_draw_bitmap(background, 0, 0, 0);

		ALLEGRO_BITMAP * otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
		ALLEGRO_BITMAP * trainsersPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/backSprites.png");

		PokemonManager pm = pm.instance();
		Pokemon otherPokemon = pm.getDefaultPokemon("Dialga");
		Pokemon playerPokemon = player.trainersParty[0];

		Button backBox = Button(256, 128, 5, 435, 445, 170, "../LeytonFinalProjectC++/Sprites/BattleSprites/BackBox.png");

		Button attackButton1 = Button(128, 64, 20, 520, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		Button attackButton2 = Button(128, 64, 20, 450, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		Button attackButton3 = Button(128, 64, 160, 520, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		Button attackButton4 = Button(128, 64, 160, 450, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");

		Button healPokemonButton = Button(64, 64, 300, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/HealingItemsButton.png");
		Button switchPokemonButton = Button(64, 64, 300, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/ChangePokemonButton.png");
		Button catchPokemonButton = Button(64, 64, 370, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokeballsButton.png");
		Button runPokemonButton = Button(64, 64, 370, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/RunButton.png");

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
					al_draw_scaled_bitmap(otherPokemonSprite, (80 * otherPokemon.xPositionOnSpriteSheet), (80 * otherPokemon.yPositionOnSpriteSheet),       80, 80,    screenWidth*0.6, screenHeight * 0.25, screenWidth * 0.3, screenWidth * 0.3, 0);
					al_draw_scaled_bitmap(trainsersPokemonSprite, (80 * playerPokemon.xPositionOnSpriteSheet), (80 * playerPokemon.yPositionOnSpriteSheet), 80, 80, screenWidth * 0.15, screenHeight*0.4, screenWidth * 0.25, screenWidth * 0.25, 0);

					backBox.drawSprite();
					attackButton1.drawSprite();
					attackButton2.drawSprite();
					attackButton3.drawSprite();
					attackButton4.drawSprite();
					healPokemonButton.drawSprite();
					switchPokemonButton.drawSprite();
					catchPokemonButton.drawSprite();
					runPokemonButton.drawSprite();
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