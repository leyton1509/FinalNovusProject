#include "../Pokemon/Pokemon.h"
#include "../Pokemon/Moves/MoveCategory.h"
class PokemonTurn {
	
public:

	int calcDamageOfMove(Pokemon playersPokemon, Pokemon otherPokemon, Move playerMoveUsed) {

		int attack = 0;
		int defence = 0;

		if (playerMoveUsed.typeOfMove == MoveCategory::Special) {
			attack = playersPokemon.specialAttackActual;
			defence = otherPokemon.specialDefenceActual;
		}

		int damage = ((2 * playersPokemon.level) + 2) * playerMoveUsed.power * ()

	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{

		// First of all, check who goes first

		if (playersPokemon.speedActual >= otherPokemon.speedActual) {



		}
		else {

		}
	



	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {

	}

};

	

