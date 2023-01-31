#include "../../Sprites/Items/Item.h"
#include <string>

using namespace std;

class PokeBall : Item{



public:

	string pokeballName;

	PokeBall(string _pokeballName) : Item(1) {

	}

};