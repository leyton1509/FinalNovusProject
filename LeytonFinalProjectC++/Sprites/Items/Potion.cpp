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

	Potion(string _potionName): Item(2){
		potionName = _potionName;

		if (strcmp(potionName.c_str(), "Potion")) {
			healPokemonBy = 20;
			inividualItemID = 4;

		}
		else if (strcmp(potionName.c_str(), "SuperPotion")) {
			healPokemonBy = 50;
			inividualItemID = 5;
		}
		else if (strcmp(potionName.c_str(), "HyperPotion")) {
			healPokemonBy = 200;
			inividualItemID = 6;
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