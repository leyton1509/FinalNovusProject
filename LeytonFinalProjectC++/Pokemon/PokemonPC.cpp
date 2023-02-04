#include "../Sprites/PlayerCharacter.h"

#include "../Sprites/SwitchPokemonPCButton.h"
#include "../Sprites/Button.h"

// Class to represent a pokemon pc to switch about Pokemon
class PokemonPC {

	// Buttons to display box 
	SwitchPokemonPCButton boxButtons[30];
	// Buttons to display party
	SwitchPokemonPCButton currentPokemon[6];

public:

	// Displays the current box and party sprites
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
	
	// Destroys the sprites
	void destroySprites() {


		for (int i = 0; i < 30; i++)
		{
			boxButtons[i].destroySprite();
		}

		for (int i = 0; i < 6; i++)
		{
			currentPokemon[i].destroySprite();
		}

	}

	// Constructor for pc, takes the player and dimensions of screen with event queue
	PokemonPC(PlayerCharacter& player, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		// Starting position of buttons
		int startXPositon = 10;
		int startYPosition = 10;
		// A counter of which button
		int counter = 0;

		// Starting x and of party
		int startXCurrentPokemon = 600;
		int startYCurrentPokemon = 200;

		// BG sprite
		ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/Background.png");
		// Front sprites of pokemon
		ALLEGRO_BITMAP* otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");

		// Loops through and creates the box buttons
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				boxButtons[counter] = SwitchPokemonPCButton(otherPokemonSprite, 128, 128, startXPositon + (i * 90), startYPosition + (j * 90), 80, 80);
				counter++;
			}

		}

		// Loops through and creates the pokemon buttons
		int playerCounter = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				currentPokemon[playerCounter] = SwitchPokemonPCButton(otherPokemonSprite, 128, 128, startXCurrentPokemon + (i * 90), startYCurrentPokemon + (j * 90), 80, 80);
				playerCounter++;
			}

		}


		// The button to exit 
		Button exitButton = Button(128, 128, 10, 480, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Exit.png");
		// The button to destroy a pokemon
		Button binButton = Button(128, 128, 100, 480, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Bin.png");
		// X and y mouse positions
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

		// Ints for if the pc / pokemon has been selected
		int highlightedPokemonPC = -1;
		int highlightedPokemonParty = -1;

		// Ints for the swap pokemon either pc or party
		int swapPokemonPC = -1;
		int swapPokemonParty = -1;

		// Bool for if the pc is finished
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

				// If the exit button has been clicked finish loop
				if (exitButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					done = true;
					finishedInPC = true;
				}
				// If the bin button has been clicked
				// If a pokemon is highlighted either in pc or party
				// And the bin is clicked
				// Then destroy the pokemon
				else if (binButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					if(highlightedPokemonPC != -1){
						player.box[highlightedPokemonPC] = Pokemon();
						boxButtons[highlightedPokemonPC].isHighlighted = false;
						highlightedPokemonPC = -1;
						player.recalcNumberOfPokemon();
					}else if (highlightedPokemonParty != -1) {
						player.recalcNumberOfPokemon();
						if (player.numberOfPokemonInParty > 1) {
							player.trainersParty[highlightedPokemonParty] = Pokemon();
							currentPokemon[highlightedPokemonParty].isHighlighted = false;
							highlightedPokemonParty = -1;
						}
						player.recalcNumberOfPokemon();
					}
				}

				// Loops through each pokemon in box
				// Checks to see if it has been clicked
				// If its clicked again unhilight it
				// If a pokemon is selected and another pokemon in the pc is selected, switch them
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
				// Loops through each pokemon in party
				// Checks to see if it has been clicked
				// If its clicked again unhilight it
				// If a pokemon is selected and another pokemon in the party is selected, switch them
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

				// If they are both selected, that means a pokemon in the party and pc is seleceted
				if (highlightedPokemonParty != -1 && highlightedPokemonPC != -1) {
					// Checks to see if the pokemon selected is valid
					// if not then it can swap with the pc freely
					if (strcmp(player.trainersParty[highlightedPokemonParty].pokemonName.c_str(), "") == 0) {
						currentPokemon[highlightedPokemonParty].isHighlighted = false;
						boxButtons[highlightedPokemonPC].isHighlighted = false;
						Pokemon tempPokemon = player.trainersParty[highlightedPokemonParty];
						player.trainersParty[highlightedPokemonParty] = player.box[highlightedPokemonPC];
						player.box[highlightedPokemonPC] = tempPokemon;
						highlightedPokemonParty = -1;
						highlightedPokemonPC = -1;
						player.recalcNumberOfPokemon();
					}
					else {
						// If it is a valid pokemon needs to check one pokemon is still in the party
						player.recalcNumberOfPokemon();
						if (player.numberOfPokemonInParty > 1) {
							currentPokemon[highlightedPokemonParty].isHighlighted = false;
							boxButtons[highlightedPokemonPC].isHighlighted = false;
							Pokemon tempPokemon = player.trainersParty[highlightedPokemonParty];
							player.trainersParty[highlightedPokemonParty] = player.box[highlightedPokemonPC];
							player.box[highlightedPokemonPC] = tempPokemon;
							highlightedPokemonParty = -1;
							highlightedPokemonPC = -1;
							player.recalcNumberOfPokemon();
						}
					}
					

				}


				break;
			}
			// Breaks if done
			if (done)
				break;
			// Draws the bacgkround, box and party sprites, the bin and exit button
			if (redraw && al_is_event_queue_empty(queue))
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_scaled_bitmap(background, 0, 0, 800, 600, 0, 0, screenWidth, screenHeight, 0);
				displaySprites(player.box, player.trainersParty);
				exitButton.drawSprite();
				binButton.drawSprite();
				al_flip_display();
			}


		}

	}
};