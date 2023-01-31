#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"
// #include "../../Pokemon/Pokemon.h"
// #include "../../Sprites/PlayerCharacter.h"

using namespace std;

class PokeBall : public Item{


public:

	string pokeballName;
	int catchRate;
	int inividualItemID;

	PokeBall() : Item(1,0,0,0,0){
		catchRate = 0;
		inividualItemID = 0;
	}

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

	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}



	
	
	
	bool catchPokemon(Pokemon& pokemon) {
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