#include <map>
#include <string>
#include "../../Sprites/Items/Potion.h"
#include "../../Sprites/Items/PokeBall.h"
#include "../../Pokemon/Pokemon.h"

class ItemManager {

public:

	// Maps an item id to the amount
	std::map<int, int> itemAmounts = {};

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

	int getAmountOfItem(int individualID) {
		auto getter = itemAmounts.find(individualID);

		if (getter == itemAmounts.end()) {
			return 0;
		}
		else {
			return getter->second;
		}
	}

	void setAmountOfItem(int individualID, int newAmount ) {
		auto getter = itemAmounts.find(individualID);

		if (getter != itemAmounts.end()) {
			getter->second = newAmount;
		}
		
	}

	void usePotion(Pokemon & pokemon, std::string potionName) {
		Potion potion = Potion(potionName);
		int cAmount = getAmountOfItem(potion.inividualItemID);
		if (cAmount > 0) {
			potion.useItem(pokemon);
			setAmountOfItem(potion.inividualItemID, (cAmount - 1));
		}
	}

	void usePokeball() {

	}




};