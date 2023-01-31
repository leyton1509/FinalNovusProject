#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"
// #include "../../Pokemon/Pokemon.h"

using namespace std;
class Potion : Item {

public:

	string potionName;
	int healPokemonBy;
	int inividualItemID;

	Potion(string _potionName): Item(2,0, 0, 0, 0){
		potionName = _potionName;

		if (strcmp(potionName.c_str(), "Potion")) {
			healPokemonBy = 20;
			inividualItemID = 4;
			xTile = 3;
			yTile = 0;
		}
		else if (strcmp(potionName.c_str(), "SuperPotion")) {
			healPokemonBy = 50;
			inividualItemID = 5;
			xTile = 12;
			yTile = 1;
		}
		else if (strcmp(potionName.c_str(), "HyperPotion")) {
			healPokemonBy = 200;
			inividualItemID = 6;
			xTile = 11;
			yTile = 1;
		}
		else {
			healPokemonBy = 0;
			inividualItemID = 0;
		}

	}
	
	
	
	
	void useItem(Pokemon & pokemon) {
		pokemon.increasePokemonHealth(healPokemonBy);
		
	}
	
	
};