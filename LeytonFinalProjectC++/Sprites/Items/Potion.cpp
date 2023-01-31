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

	}

	void useItem(Pokemon & pokemon) {
		
	}
};