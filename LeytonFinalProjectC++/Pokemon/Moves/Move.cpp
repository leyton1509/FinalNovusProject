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

	Move(int _moveID, const char* _moveName, PokemonType::PokemonTypes _pokemonTypeOfMove, MoveCategory::Categories _typeOfMove, int _powerpoints, int _power, int _accuracy) {
		moveID = _moveID;
		moveName = _moveName;
		pokemonTypeOfMove = _pokemonTypeOfMove;
		typeOfMove = _typeOfMove;
		powerpoints = _powerpoints;
		power = _power;
		accuracy = _accuracy;
	}

	Move() {

	}

};