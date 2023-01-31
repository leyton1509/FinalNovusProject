#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"

using namespace std;
class Potion : Item {

public:

	string potionName;
	int healPokemonBy;
	Potion(string _potionName): Item(2){
		potionName = _potionName;

		if (strcmp(potionName.c_str(), "Potion")) {
			healPokemonBy = 20;
		}
		else if (strcmp(potionName.c_str(), "SuperPotion")) {
			healPokemonBy = 50;
		}
		else if (strcmp(potionName.c_str(), "HyperPotion")) {
			healPokemonBy = 200;
		}
		else {
			healPokemonBy = 0;
		}

	}

	void useItem(Pokemon & pokemon) {
		
	}
};