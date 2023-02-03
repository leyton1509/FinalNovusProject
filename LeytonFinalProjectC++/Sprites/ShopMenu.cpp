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

		ItemPokeBallButton pokeballButtonOne = ItemPokeBallButton(1, 64, 64, 540, 435, 80, 80);
		ItemPokeBallButton pokeballButtonTwo = ItemPokeBallButton(2, 64, 64, 630, 435, 80, 80);
		ItemPokeBallButton pokeballButtonThree = ItemPokeBallButton(3, 64, 64, 720, 435, 80, 80);
		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 540, 435, 80, 80);
		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 630, 435, 80, 80);
		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 720, 435, 80, 80);

		


	}
};