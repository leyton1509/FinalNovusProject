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

	Move getEnemyMoveUsed(Pokemon playersPokemon, Pokemon otherPokemon, int aiLevel) {

		if (aiLevel == 0) {
			int numberOfMoves = otherPokemon.numberOfMoves-1;
			int ran = ((rand()) + numberOfMoves-1);
			return otherPokemon.pokemonsMoves[ran];
		}
		else if (aiLevel == 1) {
			int highestDamage = 0;
			Move moveToReturn;
			int numberOfMoves = otherPokemon.numberOfMoves - 1;
			for (int i = 0; i <= numberOfMoves; i++)
			{
				int dam = calcDamageOfMove(otherPokemon, playersPokemon, otherPokemon.pokemonsMoves[i]);
				if (dam > highestDamage) {
					highestDamage = dam;
					moveToReturn = otherPokemon.pokemonsMoves[i];
				}
			}
			return moveToReturn;
		}
		return otherPokemon.pokemonsMoves[0];

	}

	void enemyAttack(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		if (otherPokemon.level > 15) {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 1);
			int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
			playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
		}
		else {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 0);
			int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
			playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
		}
	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{
		// First of all, check who goes first

		if (playersPokemon.speedActual >= otherPokemon.speedActual) {
			int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
			otherPokemon.decreasePokemonHealth(damageOfMove);
			if (otherPokemon.currentHealth != 0) {
				enemyAttack(playersPokemon, otherPokemon);
			}
		}
		else {
			enemyAttack(playersPokemon, otherPokemon);

			if (playersPokemon.currentHealth != 0) {
				int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
				otherPokemon.decreasePokemonHealth(damageOfMove);
			}
		}

	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		enemyAttack(playersPokemon, otherPokemon);
	}

};

	

