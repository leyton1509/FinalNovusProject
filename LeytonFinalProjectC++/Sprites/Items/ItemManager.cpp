#include <map>
#include <string>
#include "../../Sprites/Items/Potion.h"
#include "../../Sprites/Items/PokeBall.h"
#include "../../Pokemon/Pokemon.h"

// A class to manage a players items
class ItemManager {

public:

	// Maps an item id to the amount
	std::map<int, int> itemAmounts = {};

	// Constructor for the items, sets the amount for each ID
	ItemManager(){
		// 1 Pokeball | 2 GreatBall | 3 UltraBall 
		// 4 Potion | 5 SuperPotion | 6 HyperPotion
		itemAmounts.insert({ 1, 1 });
		itemAmounts.insert({ 2, 1 });
		itemAmounts.insert({ 3, 1 });
		itemAmounts.insert({ 4, 1 });
		itemAmounts.insert({ 5, 1 });
		itemAmounts.insert({ 6, 1 });	
	}

	// Gets the amount of item from the id
	int getAmountOfItem(int individualID) {
		auto getter = itemAmounts.find(individualID);

		if (getter == itemAmounts.end()) {
			return 0;
		}
		else {
			return getter->second;
		}
	}

	// Sets the amount of the item to the new amount
	void setAmountOfItem(int individualID, int newAmount ) {
		auto getter = itemAmounts.find(individualID);

		if (getter != itemAmounts.end()) {
			getter->second = newAmount;
		}
		
	}

	

	
	
	
	// Uses the potion on the pokemon if the player has one to use
	void usePotion(Pokemon& pokemon, std::string potionName) {
		Potion potion = Potion(potionName);
		int cAmount = getAmountOfItem(potion.inividualItemID);
		if (cAmount > 0) {
			potion.useItem(pokemon);
			setAmountOfItem(potion.inividualItemID, (cAmount - 1));
		}
	}

	

	// Uses the pokeball if the player has a pokeball
	void usePokeball( Pokemon& pokemon, string pokeballName) {
		PokeBall pokeball = PokeBall(pokeballName);
		int cAmount = getAmountOfItem(pokeball.inividualItemID);
		if (cAmount > 0) {
			pokeball.catchPokemon(pokemon);
			setAmountOfItem(pokeball.inividualItemID, (cAmount - 1));
		}
	}
	


};