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

		// Sets the initial positions 
		int startXPositon = 10;
		int startYPosition = 10;
	
		// GUI info
		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		// The position of the mouse
		int xMousePosition = 0;
		int yMousePosition = 0;

		// background sprite
		ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/Background.png");

		// Sets up all the pokeball buttons 
		ItemPokeBallButton pokeballButtonOne = ItemPokeBallButton(1, 64, 64,10, 10, 80, 80);
		ItemPokeBallButton pokeballButtonTwo = ItemPokeBallButton(2, 64, 64, 10, 100, 80, 80);
		ItemPokeBallButton pokeballButtonThree = ItemPokeBallButton(3, 64, 64, 10, 190, 80, 80);
		// Sets up all the potion buttons
		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 10, 280, 80, 80);
		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 10, 370, 80, 80);
		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 10, 460, 80, 80);

		// Sets up the exit button
		Button exitButton = Button(128, 128, 280, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Exit.png");

		// Sets up a button for displaying the players money
		Button playersMoney = Button(128, 128, screenWidth - 90, 10, 80, 30, "../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png");

		// Sets up the buy buttons for the player
		Button buyButtonOne = Button(128, 128, 100, 10, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 200);
		Button buyButtonTwo = Button(128, 128, 100, 100, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 400);
		Button buyButtonThree = Button(128, 128, 100, 190, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 800);
		Button buyButtonFour = Button(128, 128, 100, 280, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 250);
		Button buyButtonFive = Button(128, 128, 100, 370, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 450);
		Button buyButtonSix = Button(128, 128, 100, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Buy.png", 850);

		// Sets up the sell buttons for the player
		Button sellButtonOne = Button(128, 128, 190, 10, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 200);
		Button sellButtonTwo = Button(128, 128, 190, 100, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 400);
		Button sellButtonThree = Button(128, 128, 190, 190, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 800);
		Button sellButtonFour = Button(128, 128, 190, 280, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 250);
		Button sellButtonFive = Button(128, 128, 190, 370, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 450);
		Button sellButtonSix = Button(128, 128, 190, 460, 80, 80, "../LeytonFinalProjectC++/Sprites/PCSprites/Sell.png", 850);

		// bool for if finished
		bool finishedInShop = false;

		while (!finishedInShop) {

			al_wait_for_event(queue, &event);

			switch (event.type)
			{
			case ALLEGRO_EVENT_MOUSE_AXES:
				// Updates mouse positions
				xMousePosition = event.mouse.x;
				yMousePosition = event.mouse.y;
				break;
			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				break;

			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				// when closed finish shop
				done = true;
				finishedInShop = true;
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				// Checks to see which buttons have been clicked
				// Checks to see if exit button has been clicked
				if (exitButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					done = true;
					finishedInShop = true;
				}
				// Checks for if the buy buttons have been clicked and calls the buy item in player
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
				// Checks for if the sell buttons have been clicked and calls the sell item in player
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

			// If done break
			if (done) {
				break;
			}
				
			// Drawing loop
			if (redraw && al_is_event_queue_empty(queue))
			{
				// Draws the background
				al_draw_scaled_bitmap(background, 0, 0, 800, 600, 0, 0, screenWidth, screenHeight, 0);
				// Draws the pookeball button sprites
				pokeballButtonOne.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonOne.pokeball.inividualItemID));
				pokeballButtonTwo.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonTwo.pokeball.inividualItemID));
				pokeballButtonThree.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonThree.pokeball.inividualItemID));
				// Draws the potion button sprites
				potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
				potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
				potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));
				// Draws exit button
				exitButton.drawSprite();

				// Draws the buy buttons
				buyButtonOne.drawSprite();
				buyButtonTwo.drawSprite();
				buyButtonThree.drawSprite();
				buyButtonFour.drawSprite();
				buyButtonFive.drawSprite();
				buyButtonSix.drawSprite();
				// Draws the sell buttons
				sellButtonOne.drawSprite();
				sellButtonTwo.drawSprite();
				sellButtonThree.drawSprite();
				sellButtonFour.drawSprite();
				sellButtonFive.drawSprite();
				sellButtonSix.drawSprite();
				// Draws the players money
				playersMoney.drawSprite(player.playersMoney);
				al_flip_display();
			}
		}
	}
};