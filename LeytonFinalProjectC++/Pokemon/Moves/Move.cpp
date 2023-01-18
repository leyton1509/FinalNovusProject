#include "../../Pokemon/PokemonType.h"
#include "../../Pokemon/Moves/MoveCategory.h"

class Move {

public:

	int moveID;
	const char* moveName;
	PokemonType::PokemonTypes pokemonTypeOfMove;
	MoveCategory::Categories typeOfMove;
	int powerpoints;
	int power;
	int accuracy;



};