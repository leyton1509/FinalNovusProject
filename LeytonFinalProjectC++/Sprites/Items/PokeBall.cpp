#include "../../Sprites/Items/Item.h"
#include <string>

using namespace std;

class PokeBall : Item{


public:

	string pokeballName;
	int catchRate;

	PokeBall(string _pokeballName) : Item(1) {

		pokeballName = _pokeballName;

		if (strcmp(pokeballName.c_str(), "PokeBall")) {
			catchRate = 5;
		}
		else if (strcmp(pokeballName.c_str(), "GreatBall")) {
			catchRate = 10;
		}
		else if (strcmp(pokeballName.c_str(), "UltraBall")) {
			catchRate = 15;
		}
		else {
			catchRate = 0;
		}
	}


	void catchPokemon() {

	}

};