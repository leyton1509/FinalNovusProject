#include "../../Pokemon/PokemonType.h"
#include "../../Pokemon/Moves/MoveCategory.h"
#include <iostream>
#include <string>


class Move {

public:

	int moveID;
	std::string moveName;
	PokemonType::PokemonTypes pokemonTypeOfMove;
	MoveCategory::Categories typeOfMove;
	int powerpoints;
	int power;
	int accuracy;
	int hasSpecialEffect;
	int currentPowerPoints;

	Move(int _moveID, std::string _moveName, PokemonType::PokemonTypes _pokemonTypeOfMove, MoveCategory::Categories _typeOfMove, int _powerpoints, int _power, int _accuracy, int _hasSpecialEffect) {
		moveID = _moveID;
		moveName = _moveName;
		pokemonTypeOfMove = _pokemonTypeOfMove;;
		typeOfMove = _typeOfMove;
		powerpoints = _powerpoints;
		currentPowerPoints = _powerpoints;
		power = _power;
		accuracy = _accuracy;
		hasSpecialEffect = _hasSpecialEffect;
	}

	Move() {
		moveID = -1;
		moveName = "";
		typeOfMove = MoveCategory::Categories::Status;
		pokemonTypeOfMove = PokemonType::PokemonTypes::None;
		powerpoints = 0;
		power = 0;
		accuracy = 0;
		hasSpecialEffect = 0;
		currentPowerPoints = 0;
	}

	void resetPP() {
		currentPowerPoints = powerpoints;
	}

	void printMove() {
		std::cout << moveName << " " << pokemonTypeOfMove << " " << typeOfMove << " " << power << " " << accuracy << " \n";
	}

};