#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"

using namespace std;

// A pokeball item that is used to catch pokemon
// Extends item
class PokeBall : public Item{


public:

	// The name of the poke ball
	string pokeballName;
	// The catch rate of the pokeball
	int catchRate;
	// The individual item id
	int inividualItemID;

	// Constructor empty
	PokeBall() : Item(1,0,0,0,0){
		catchRate = 0;
		inividualItemID = 0;
	}


	// Constructor with the id of the pokeball
	PokeBall(int id) : Item(1, 0, 0,0,0) {

		if (id == 1) {
			pokeballName = "Poke Ball";
			catchRate = 255;
			inividualItemID = 1;
			xTileForSpriteSheet = 3;
			yTileForSpriteSheet = 0;
		}
		else if (id == 2) {
			pokeballName = "Great Ball";
			catchRate = 200;
			inividualItemID = 2;
			xTileForSpriteSheet =2;
			yTileForSpriteSheet = 0;

		}
		else if (id==3) {
			pokeballName = "Ultra Ball";
			catchRate = 150;
			inividualItemID = 3;
			xTileForSpriteSheet = 1;
			yTileForSpriteSheet = 0;
		}
		else {
			cout << "Test \n";
			catchRate = 255;
			inividualItemID = 0;
		}
	}

	// Generates a random number
	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	// Uses the pokeball with the pokemons details to determine true if it was caught
	bool useItem(Pokemon& pokemon) {
		int n = random(1, catchRate);
		int max = pokemon.healthActual + n;
		int min = pokemon.currentHealth;
		int willCatch = random(min, max);

		if (willCatch <= (max * 0.3) && willCatch > min) {
			return true;
		}
		return false;
		
	}
	
};