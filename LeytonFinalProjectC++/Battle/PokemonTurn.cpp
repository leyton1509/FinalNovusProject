#include "../Pokemon/Pokemon.h"
#include "../Pokemon/Moves/MoveCategory.h"
#include "../Pokemon/PokemonTypeChart.h"
class PokemonTurn {
	
public:

	int calcDamageOfMove(Pokemon playersPokemon, Pokemon otherPokemon, Move playerMoveUsed) {



		int attack = 0;
		int defence = 0;

		if (playerMoveUsed.typeOfMove == MoveCategory::Special) {
			attack = playersPokemon.specialAttackActual;
			defence = otherPokemon.specialDefenceActual;
		}
		else if (playerMoveUsed.typeOfMove == MoveCategory::Physical) {
			attack = playersPokemon.physcialAttackActual;
			defence = otherPokemon.physicalDefenceActual;
		}

		PokemonTypeChart ptc = PokemonTypeChart();
		int effectivenessOfMove = ptc.returnEffectivenessOfMove(playerMoveUsed.pokemonTypeOfMove, otherPokemon.pokemonTypeOne, otherPokemon.pokemonTypeTwo);

		int stab = 1;

		if (playersPokemon.pokemonTypeOne == playerMoveUsed.pokemonTypeOfMove || playersPokemon.pokemonTypeTwo == playerMoveUsed.pokemonTypeOfMove) {
			stab = 1.5;
		}

		int damage = (((2 * playersPokemon.level) + 2) * playerMoveUsed.power * (attack / defence) / 50) * effectivenessOfMove * stab;

	}

	Move getEnemyMoveUsed(Pokemon otherPokemon, int aiLevel) {

	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{

		// First of all, check who goes first

		if (playersPokemon.speedActual >= otherPokemon.speedActual) {
			int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
			otherPokemon.decreasePokemonHealth(damageOfMove);
			if (otherPokemon.currentHealth != 0) {

				if (otherPokemon.level > 15) {
					Move enemyMove = getEnemyMoveUsed(otherPokemon, 1);
				}
				else {
					Move enemyMove = getEnemyMoveUsed(otherPokemon, 0);
				}

				
			}


		}
		else {

		}
	



	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {

	}

};

	

