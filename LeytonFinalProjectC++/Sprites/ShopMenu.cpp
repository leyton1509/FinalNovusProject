#include "../Sprites/PlayerCharacter.h"
#include "../Sprites/ItemPokeBallButton.h"
#include "../Sprites/ItemPotionButton.h"

// Menu for handling buying / selling items
class ShopMenu {


public:

	// Constructor for handling buying / selling items
	ShopMenu(bool buy, PlayerCharacter & player, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		int startXPositon = 10;
		int startYPosition = 10;
		int counter = 0;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;
		int xMousePosition = 0;
		int yMousePosition = 0;

		ItemPokeBallButton pokeballButtonOne = ItemPokeBallButton(1, 64, 64, 10, 90, 80, 80);
		ItemPokeBallButton pokeballButtonTwo = ItemPokeBallButton(2, 64, 64, 10, 180, 80, 80);
		ItemPokeBallButton pokeballButtonThree = ItemPokeBallButton(3, 64, 64, 10, 270, 80, 80);
		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 540, 360, 80, 80);
		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 630, 450, 80, 80);
		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 720, 540, 80, 80);

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

			if (done) {
				break;
			}
				

			if (redraw && al_is_event_queue_empty(queue))
			{
				pokeballButtonOne.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonOne.pokeball.inividualItemID));
				pokeballButtonTwo.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonTwo.pokeball.inividualItemID));
				pokeballButtonThree.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonThree.pokeball.inividualItemID));
				potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
				potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
				potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));
				
				al_flip_display();
			}


		}

		
		


	}
};