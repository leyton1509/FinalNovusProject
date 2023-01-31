#include "../../Sprites/Items/Item.h"
#include <string>

using namespace std;

class PokeBall : Item{


public:

	string pokeballName;
	int catchRate;

	PokeBall(string _pokeballName) : Item(1) {

		pokeballName = _pokeballName;

		

	}

};