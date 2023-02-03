#include "../Sprites/PlayerCharacter.h"
#include "../Sprites/ItemPokeBallButton.h"
#include "../Sprites/ItemPotionButton.h"

// Menu for handling buying / selling items
class ShopMenu {


public:

	// Constructor for handling buying / selling items
	ShopMenu(bool buy, PlayerCharacter & player, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		//Reset the camera
		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);

		int startXPositon = 10;
		int startYPosition = 10;
		int counter = 0;

		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;
		int xMousePosition = 0;
		int yMousePosition = 0;

		ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/Background.png");

		ItemPokeBallButton pokeballButtonOne = ItemPokeBallButton(1, 64, 64,10, 10, 80, 80);
		ItemPokeBallButton pokeballButtonTwo = ItemPokeBallButton(2, 64, 64, 10, 100, 80, 80);
		ItemPokeBallButton pokeballButtonThree = ItemPokeBallButton(3, 64, 64, 10, 190, 80, 80);
		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 10, 280, 80, 80);
		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 10, 370, 80, 80);
		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 10, 460, 80, 80);

		Button exitButton = Button(128, 128, 280, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Exit.png");

		Button buyButtonOne = Button(128, 128, 100, 10, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 200);
		Button buyButtonTwo = Button(128, 128, 100, 100, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 400);
		Button buyButtonThree = Button(128, 128, 100, 190, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 800);
		Button buyButtonFour = Button(128, 128, 100, 280, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 250);
		Button buyButtonFive = Button(128, 128, 100, 370, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 450);
		Button buyButtonSix = Button(128, 128, 100, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 850);

		Button sellButtonOne = Button(128, 128, 190, 10, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 200);
		Button sellButtonTwo = Button(128, 128, 190, 100, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 400);
		Button sellButtonThree = Button(128, 128, 190, 190, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 800);
		Button sellButtonFour = Button(128, 128, 190, 280, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 250);
		Button sellButtonFive = Button(128, 128, 190, 370, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 450);
		Button sellButtonSix = Button(128, 128, 190, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 850);

		bool finishedInShop = false;

		while (!finishedInShop) {

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
				finishedInShop = true;
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				if (exitButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					done = true;
					finishedInShop = true;
				}
				else if (buyButtonOne.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(pokeballButtonOne.pokeball.inividualItemID, buyButtonOne.buttonValue);
				}
				else if (buyButtonTwo.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(pokeballButtonTwo.pokeball.inividualItemID, buyButtonTwo.buttonValue);
				}
				else if (buyButtonThree.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(pokeballButtonThree.pokeball.inividualItemID, buyButtonThree.buttonValue);
				}

				else if (buyButtonFour.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(potionButtonOne.potion.inividualItemID, buyButtonFour.buttonValue);
				}
				else if (buyButtonFive.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(potionButtonTwo.potion.inividualItemID, buyButtonFive.buttonValue);
				}
				else if (buyButtonSix.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.buyItem(potionButtonThree.potion.inividualItemID, buyButtonSix.buttonValue);
				}


				else if (sellButtonOne.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(pokeballButtonOne.pokeball.inividualItemID, sellButtonOne.buttonValue);
				}
				else if (sellButtonTwo.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(pokeballButtonTwo.pokeball.inividualItemID, sellButtonTwo.buttonValue);
				}
				else if (sellButtonThree.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(pokeballButtonThree.pokeball.inividualItemID, sellButtonThree.buttonValue);
				}

				else if (sellButtonFour.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(potionButtonOne.potion.inividualItemID, sellButtonFour.buttonValue);
				}
				else if (sellButtonFive.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(potionButtonTwo.potion.inividualItemID, sellButtonFive.buttonValue);
				}
				else if (sellButtonSix.hasBeenClicked(xMousePosition, yMousePosition)) {
					player.sellItem(potionButtonThree.potion.inividualItemID, sellButtonSix.buttonValue);
				}


				break;
			}

			if (done) {
				break;
			}
				

			if (redraw && al_is_event_queue_empty(queue))
			{
				al_draw_scaled_bitmap(background, 0, 0, 800, 600, 0, 0, screenWidth, screenHeight, 0);
				pokeballButtonOne.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonOne.pokeball.inividualItemID));
				pokeballButtonTwo.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonTwo.pokeball.inividualItemID));
				pokeballButtonThree.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonThree.pokeball.inividualItemID));
				potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
				potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
				potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));
				exitButton.drawSprite();

				buyButtonOne.drawSprite();
				buyButtonTwo.drawSprite();
				buyButtonThree.drawSprite();
				buyButtonFour.drawSprite();
				buyButtonFive.drawSprite();
				buyButtonSix.drawSprite();

				sellButtonOne.drawSprite();
				sellButtonTwo.drawSprite();
				sellButtonThree.drawSprite();
				sellButtonFour.drawSprite();
				sellButtonFive.drawSprite();
				sellButtonSix.drawSprite();

				al_flip_display();
			}


		}

		
		


	}
};