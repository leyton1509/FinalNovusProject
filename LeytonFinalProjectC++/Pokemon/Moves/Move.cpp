#include "../../Pokemon/PokemonType.h"
#include "../../Pokemon/Moves/MoveCategory.h"
#include <iostream>
#include <string>

// A class to represent a pokemon move
class Move {

public:
	// The id of the move
	int moveID;
	// The name of the move
	std::string moveName;
	// The pokemon type of the move
	PokemonType::PokemonTypes pokemonTypeOfMove;
	// The type of move
	MoveCategory::Categories typeOfMove;
	// How many times the move can be used
	int powerpoints;
	// The power of the move
	int power;
	// The accuracy of the move
	int accuracy;
	// If the move has a special effect
	int hasSpecialEffect;
	// How many times the move can be used left over
	int currentPowerPoints;

	// Constructor of move taking the reqiured info to create
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

	// Empty constructor
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

	// Method to call when move is used
	void useMove() {
		currentPowerPoints--;
	}

	// Resets the pp back to full
	void resetPP() {
		currentPowerPoints = powerpoints;
	}

	// Prints out the details of the move
	void printMove() {
		std::cout << moveName << " " << pokemonTypeOfMove << " " << typeOfMove << " " << power << " " << accuracy << " \n";
	}

};