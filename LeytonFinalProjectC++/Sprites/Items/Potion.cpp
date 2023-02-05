#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"

using namespace std;

// Class to represent a potion
// Extends item
class Potion : public Item {

public:

	// The name of the potion
	string potionName;
	// The value to heal the pokemon by
	int healPokemonBy;
	// The int id of the item
	int inividualItemID;

	// empty constructor
	Potion() : Item(2, 0, 0, 0, 0) {
		healPokemonBy = 0;
		inividualItemID = 0;
	}

	// Constructor with the id of the potion
	// The id changes the name of the potion and how much it heals by
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
	
	// Increases the pokemons health by potion val
	void useItem(Pokemon & pokemon) {
		pokemon.increasePokemonHealth(healPokemonBy);
		
	}
	
	
};