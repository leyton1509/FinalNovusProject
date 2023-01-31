#include "../../Sprites/Items/Item.h"
#include <string>
#include "../../Pokemon/Pokemon.h"

using namespace std;

class PokeBall : Item{


public:

	string pokeballName;
	int catchRate;

	PokeBall(string _pokeballName) : Item(1) {

		pokeballName = _pokeballName;

		if (strcmp(pokeballName.c_str(), "PokeBall")) {
			catchRate = 255;
		}
		else if (strcmp(pokeballName.c_str(), "GreatBall")) {
			catchRate = 200;
		}
		else if (strcmp(pokeballName.c_str(), "UltraBall")) {
			catchRate = 150;
		}
		else {
			catchRate = 255;
		}
	}

	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	void catchPokemon(Pokemon & pokemon) {
		int n = random(0, catchRate);
	}

};