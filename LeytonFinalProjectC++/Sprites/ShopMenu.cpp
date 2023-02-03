#include "../Sprites/PlayerCharacter.h"

// Menu for handling buying / selling items
class ShopMenu {


public:

	// Constructor for handling buying / selling items
	ShopMenu(bool buy, PlayerCharacter & player, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue) {

		int startXPositon = 10;
		int startYPosition = 10;
		int counter = 0;

		// Gets the number of items
		int nOfItems = player.itemManager.getNumberOfItems();
		// Work out how many columns to displau
		int nOfColumns = (nOfItems / 8) + 1;

		for (int i = 0; i < nOfColumns; i++)
		{

		}


	}
};