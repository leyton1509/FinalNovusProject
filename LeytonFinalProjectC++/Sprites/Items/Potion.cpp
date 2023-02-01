#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"
// #include "../../Pokemon/Pokemon.h"

using namespace std;
class Potion : public Item {

public:

	string potionName;
	int healPokemonBy;
	int inividualItemID;

	Potion() : Item(2, 0, 0, 0, 0) {
		healPokemonBy = 0;
		inividualItemID = 0;
	}

	Potion(int id): Item(2,0, 0, 0, 0){

		if (id == 4) {
			potionName = "Potion";
			healPokemonBy = 20;
			inividualItemID = 4;
			xTileForSpriteSheet = 15;
			yTileForSpriteSheet = 0;
		}
		else if (id == 5) {
			potionName = "Super Potion";
			healPokemonBy = 50;
			inividualItemID = 5;
			xTileForSpriteSheet = 24;
			yTileForSpriteSheet = 0;
		}
		else if (id == 6) {
			potionName = "Hyper Potion";
			healPokemonBy = 200;
			inividualItemID = 6;
			xTileForSpriteSheet = 23;
			yTileForSpriteSheet = 0;
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