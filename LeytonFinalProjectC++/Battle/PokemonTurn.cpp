#include "../Pokemon/Pokemon.h"
#include "../Pokemon/Moves/MoveCategory.h"
#include "../Pokemon/PokemonTypeChart.h"
class PokemonTurn {
	
public:

	int calcDamageOfMove(Pokemon attackingPokemon, Pokemon DefendingPokemon, Move playerMoveUsed) {



		int attack = 0;
		int defence = 0;

		if (playerMoveUsed.typeOfMove == MoveCategory::Special) {
			attack = attackingPokemon.specialAttackActual;
			defence = DefendingPokemon.specialDefenceActual;
		}
		else if (playerMoveUsed.typeOfMove == MoveCategory::Physical) {
			attack = attackingPokemon.physcialAttackActual;
			defence = DefendingPokemon.physicalDefenceActual;
		}

		PokemonTypeChart ptc = PokemonTypeChart();
		int effectivenessOfMove = ptc.returnEffectivenessOfMove(playerMoveUsed.pokemonTypeOfMove, DefendingPokemon.pokemonTypeOne, DefendingPokemon.pokemonTypeTwo);

		int stab = 1;

		if (attackingPokemon.pokemonTypeOne == playerMoveUsed.pokemonTypeOfMove || attackingPokemon.pokemonTypeTwo == playerMoveUsed.pokemonTypeOfMove) {
			stab = 1.5;
		}
		//int ranModifier = ((rand()%85) + 100);
		int damage = (((2 * attackingPokemon.level) + 2) * playerMoveUsed.power * (attack / defence) / 50) * effectivenessOfMove * stab;
		cout << "\nPokemon Attacking : |"<< attackingPokemon.pokemonName << " Damage:" << damage << " Effectiveness:" << effectivenessOfMove << "\n";
		return damage;
	}

	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	Move getEnemyMoveUsed(Pokemon playersPokemon, Pokemon otherPokemon, int aiLevel) {

		if (aiLevel == 0) {
			int numberOfMoves = otherPokemon.numberOfMoves-1;
			int ran = random(0, (numberOfMoves-1));
			return otherPokemon.pokemonsMoves[ran];
		}
		else if (aiLevel == 1) {
			int highestDamage = 0;
			Move moveToReturn;
			int numberOfMoves = otherPokemon.numberOfMoves - 1;
			for (int i = 0; i <= numberOfMoves; i++)
			{
				if (otherPokemon.pokemonsMoves[i].typeOfMove != MoveCategory::Status) {
					int dam = calcDamageOfMove(otherPokemon, playersPokemon, otherPokemon.pokemonsMoves[i]);
					if (dam > highestDamage) {
						highestDamage = dam;
						moveToReturn = otherPokemon.pokemonsMoves[i];
					}
				}
				
			}
			return moveToReturn;
		}
		return otherPokemon.pokemonsMoves[0];

	}

	void statusMove(Pokemon& pokemonUsingMove, Pokemon& otherPokemon, Move statusMoveUsed) {

	}

	void enemyAttack(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		if (otherPokemon.level > 15) {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 1);
			if (enemyMove.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, enemyMove);
			}
			else {
				int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
				playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
			}
			
		}
		else {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 0);
			if (enemyMove.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, enemyMove);
			}
			else {
				cout << "\nUsed : " << enemyMove.moveName << "\n";
				int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
				playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
				cout << "\Player health : " << playersPokemon.currentHealth << " taken " << damageOfEnemyMove << "\n";
			}

			
		}
	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{
		// First of all, check who goes first

		playersPokemon.printMonsterDetails();
		otherPokemon.printMonsterDetails();

		if (playersPokemon.speedActual >= otherPokemon.speedActual) {
			if (playerMoveUsed.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, playerMoveUsed);
			}
			else {
				int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
				otherPokemon.decreasePokemonHealth(damageOfMove);
			}
			
			if (otherPokemon.currentHealth != 0) {
				enemyAttack(playersPokemon, otherPokemon);
			}
		}
		else {
			enemyAttack(playersPokemon, otherPokemon);

			if (playersPokemon.currentHealth != 0) {
				if (playerMoveUsed.typeOfMove == MoveCategory::Status) {
					statusMove(otherPokemon, playersPokemon, playerMoveUsed);
				}
				else {
					int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
					otherPokemon.decreasePokemonHealth(damageOfMove);
				}
			}
		}

	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		enemyAttack(playersPokemon, otherPokemon);
	}

};

	
