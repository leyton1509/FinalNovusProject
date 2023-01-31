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

	PokeBall(string _pokeballName) : Item(1, 0, 0,0,0) {

		pokeballName = _pokeballName;

		if (strcmp(pokeballName.c_str(), "PokeBall")) {
			catchRate = 255;
			inividualItemID = 1;
			xTile = 3;
			yTile = 0;
		}
		else if (strcmp(pokeballName.c_str(), "GreatBall")) {
			catchRate = 200;
			inividualItemID = 2;
			xTile = 2;
			yTile = 0;

		}
		else if (strcmp(pokeballName.c_str(), "UltraBall")) {
			catchRate = 150;
			inividualItemID = 3;
			xTile = 1;
			yTile = 0;
		}
		else {
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