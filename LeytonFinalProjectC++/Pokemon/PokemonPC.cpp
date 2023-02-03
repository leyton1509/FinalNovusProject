#include "../Sprites/PlayerCharacter.h"

#include "../Sprites/SwitchPokemonPCButton.h"
#include "../Sprites/Button.h"


class PokemonPC {

	SwitchPokemonPCButton boxButtons[30];
	SwitchPokemonPCButton currentPokemon[6];

public:

	void displaySprites(Pokemon box[], Pokemon playersParty[]) {

		for (int i = 0; i < 30; i++)
		{
			boxButtons[i].drawSprite(box[i]);
		}

		for (int i = 0; i < 6; i++)
		{
			currentPokemon[i].drawSprite(playersParty[i]);
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

		int startXCurrentPokemon = 600;
		int startYCurrentPokemon = 200;

		// BG sprite
		ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/Background.png");
		ALLEGRO_BITMAP* otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				boxButtons[counter] = SwitchPokemonPCButton(otherPokemonSprite, 128, 128, startXPositon + (i * 90), startYPosition + (j * 90), 80, 80);
				counter++;
			}

		}

		int playerCounter = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				currentPokemon[playerCounter] = SwitchPokemonPCButton(otherPokemonSprite, 128, 128, startXCurrentPokemon + (i * 90), startYCurrentPokemon + (j * 90), 80, 80);
				playerCounter++;
			}

		}


		Button exitButton = Button(128, 128, 10, 480, 80,80, "../LeytonFinalProjectC++/Sprites/PCSprites/Exit.png");
		Button binButton = Button(128, 128, 100, 480, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Bin.png");
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

		int highlightedPokemonPC = -1;
		int highlightedPokemonParty = -1;

		int swapPokemonPC = -1;
		int swapPokemonParty = -1;
		int binButtonClicked = -1;

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

				if (exitButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					done = true;
					finishedInPC = true;
				}else if (binButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					binButtonClicked = 1;
				}

				for (int i = 0; i < 30; i++)
				{
					bool hasBeenClicked = boxButtons[i].hasBeenClicked(xMousePosition, yMousePosition);
					if (hasBeenClicked) {
						if (highlightedPokemonPC == -1) {
							boxButtons[i].isHighlighted = true;
							highlightedPokemonPC = i;
						}
						else if (highlightedPokemonPC == i) {
							boxButtons[i].isHighlighted = false;
							highlightedPokemonPC = -1;
						}
						
						
						else if(highlightedPokemonPC != i){
							Pokemon tempPokemon = player.box[highlightedPokemonPC];
							boxButtons[highlightedPokemonPC].isHighlighted = false;
							player.box[highlightedPokemonPC] = player.box[i];
							player.box[i] = tempPokemon;

							highlightedPokemonPC = -1;
						}
						
					}
				}

				for (int i = 0; i < 6; i++)
				{
					bool hasBeenClicked = currentPokemon[i].hasBeenClicked(xMousePosition, yMousePosition);
					if (hasBeenClicked) {
						if (highlightedPokemonParty == -1) {
							currentPokemon[i].isHighlighted = true;
							highlightedPokemonParty = i;
						}
						else if (highlightedPokemonParty == i) {
							currentPokemon[i].isHighlighted = false;
							highlightedPokemonParty = -1;
						}
						else if (highlightedPokemonParty != i) {
							Pokemon tempPokemon = player.trainersParty[highlightedPokemonParty];
							currentPokemon[highlightedPokemonParty].isHighlighted = false;
							player.trainersParty[highlightedPokemonParty] = player.trainersParty[i];
							player.trainersParty[i] = tempPokemon;

							highlightedPokemonParty = -1;
						}
					}

				}

				if (highlightedPokemonParty != -1 && highlightedPokemonPC != -1) {
					currentPokemon[highlightedPokemonParty].isHighlighted = false;
					boxButtons[highlightedPokemonPC].isHighlighted = false;
					Pokemon tempPokemon = player.trainersParty[highlightedPokemonParty];
					player.trainersParty[highlightedPokemonParty] = player.box[highlightedPokemonPC];
					player.box[highlightedPokemonPC] = tempPokemon;
					highlightedPokemonParty = -1;
					highlightedPokemonPC = -1;
					player.recalcNumberOfPokemon();

				}


				break;
			}

			if (done)
				break;

			if (redraw && al_is_event_queue_empty(queue))
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_scaled_bitmap(background, 0, 0, 321, 240, 0, 0, screenWidth, screenHeight, 0);
				displaySprites(player.box, player.trainersParty);
				exitButton.drawSprite();
				binButton.drawSprite();
				al_flip_display();
			}


		}

	}
};