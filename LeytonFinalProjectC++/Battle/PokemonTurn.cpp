#include "../Pokemon/Pokemon.h"
#include "../Pokemon/Moves/MoveCategory.h"
#include "../Pokemon/PokemonTypeChart.h"
#include "../Sprites/Trainer.h"

// Class which represents a single pokemon turn
class PokemonTurn {
	
public:

	// An array of strings to display back what happened
	string textForTextBox[4] = { "", "", "", "" };

	// Strings for which attack were used
	int attackUsedOpponent;


	int getNextPokemonForOpponent(Trainer& trainer, int currentPokemon, Pokemon playersPokemon) {

		// Gets the pokemon type char
		PokemonTypeChart ptc = PokemonTypeChart();
		// The effectiveness of the pokemon againt the players pokemon
		double highestEffectiveness = -1;
		// Which pokemon number to choose
		int numberToChoose = 0;

		// Loops through the trainers party
		// Checks its not the current pokemon and if its valid
		// Works out the effectiveness and sets the number pokemon to the best effective pokemon
		for (int i = 0; i < trainer.numberOfPokemonInParty; i++)
		{
			if (i != currentPokemon) {
				if (strcmp(trainer.trainersTeam[i].pokemonName.c_str(), "") != 0) {
					if (trainer.trainersTeam[i].currentHealth > 0) {
						double effectiveness = ptc.returnEffectivenessOfMove(trainer.trainersTeam[i].pokemonTypeOne, playersPokemon.pokemonTypeOne, playersPokemon.pokemonTypeTwo);
						effectiveness = effectiveness * ptc.returnEffectivenessOfMove(trainer.trainersTeam[i].pokemonTypeTwo, playersPokemon.pokemonTypeOne, playersPokemon.pokemonTypeTwo);
						if (effectiveness > highestEffectiveness) {
							numberToChoose = i;
							highestEffectiveness = effectiveness;
						}
					}
				}
			}
			
		}
		return numberToChoose;
	}

	// Returns an int for the damage of the move on the defending pokemon from the attacking pokemoon
	int calcDamageOfMove(Pokemon attackingPokemon, Pokemon DefendingPokemon, Move playerMoveUsed) {

		// The attack and defence of pokemon
		int attack = 0;
		int defence = 0;

		// Gets the physical attack or the special attack depending on the move 
		if (playerMoveUsed.typeOfMove == MoveCategory::Special) {
			attack = attackingPokemon.specialAttackActual;
			defence = DefendingPokemon.specialDefenceActual;
		}
		else if (playerMoveUsed.typeOfMove == MoveCategory::Physical) {
			attack = attackingPokemon.physcialAttackActual;
			defence = DefendingPokemon.physicalDefenceActual;
		}

		// Gets the effectiveness of the move on the defending pokemon
		PokemonTypeChart ptc = PokemonTypeChart();
		double effectivenessOfMove = ptc.returnEffectivenessOfMove(playerMoveUsed.pokemonTypeOfMove, DefendingPokemon.pokemonTypeOne, DefendingPokemon.pokemonTypeTwo);

		// Same type attack bonus, 1.5 if the attacking pokemon ahs the same type as the attack
		int stab = 1;

		if (attackingPokemon.pokemonTypeOne == playerMoveUsed.pokemonTypeOfMove || attackingPokemon.pokemonTypeTwo == playerMoveUsed.pokemonTypeOfMove) {
			stab = 1.5;
		}
		//int ranModifier = ((rand()%85) + 100);
		// Works out the damagge
		float damage = ((((((static_cast<float>(2) * attackingPokemon.level) / 5) + 2) * playerMoveUsed.power * attack / defence) / 50) + 2) * stab * effectivenessOfMove;
		return damage;
	}

	// Generates a random number between range
	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	// There are currently 2 level of ai
	// level 0 which picks a random move
	// Level 1 which gets the highest damaging move
	Move getEnemyMoveUsed(Pokemon playersPokemon, Pokemon otherPokemon, int aiLevel) {

		// Pick a random move for the enemy
		if (aiLevel == 0) {
			int numberOfMoves = otherPokemon.numberOfMoves-1;
			int ran = random(0, (numberOfMoves-1));
			return otherPokemon.pokemonsMoves[ran];
		}
		// Work out the highest damaging move and return that move
		else if (aiLevel == 1) {
			int highestDamage = 0;
			Move moveToReturn;
			int numberOfMoves = otherPokemon.numberOfMoves - 1;
			for (int i = 0; i <= numberOfMoves; i++)
			{
				if (otherPokemon.pokemonsMoves[i].typeOfMove != MoveCategory::Status) {
					if (strcmp(otherPokemon.pokemonName.c_str(), "") != 0) {
						int dam = calcDamageOfMove(otherPokemon, playersPokemon, otherPokemon.pokemonsMoves[i]);
						if (dam > highestDamage) {
							highestDamage = dam;
							moveToReturn = otherPokemon.pokemonsMoves[i];
						}
					}
					
				}
				
			}
			return moveToReturn;
		}
		return otherPokemon.pokemonsMoves[0];

	}

	// Method for status move
	// Takes the pokemon using move, the other pokemon and the status move
	void statusMove(Pokemon& pokemonUsingMove, Pokemon& otherPokemon, Move statusMoveUsed) {
		cout << "\n" << pokemonUsingMove.pokemonName << " used : " << statusMoveUsed.moveName << "\n";

	}

	// The enemies attack
	// Takes the playerspokemon
	// And the other pokemon
	// The ai is dependent on the pokemons level
	// Sets the text in the textbox
	// Either uses a status move or the attacking move
	void enemyAttack(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		if (otherPokemon.level > 15) {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 1);
			attackUsedOpponent = enemyMove.moveID;
			if (strcmp(textForTextBox[1].c_str(), "")) {
				textForTextBox[0] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "!";
			}
			else {
				textForTextBox[1] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "!";
			}

			if (enemyMove.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, enemyMove);
			}
			else {
				if (doesAttackHit(enemyMove.accuracy)) {
					int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
					playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
				}
				else {
					if (strcmp(textForTextBox[1].c_str(), "")) {
						textForTextBox[0] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "! It missed!";
					}
					else {
						textForTextBox[1] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "! It missed!";
					}
				}
			}
			
		}
		else {
			Move enemyMove = getEnemyMoveUsed(playersPokemon, otherPokemon, 0);
			attackUsedOpponent = enemyMove.moveID;
			if (strcmp(textForTextBox[1].c_str(), "")) {
				textForTextBox[0] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "!";
			}
			else {
				textForTextBox[1] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "!";
			}

			if (enemyMove.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, enemyMove);
			}
			else {
				if (doesAttackHit(enemyMove.accuracy)) {
					int damageOfEnemyMove = calcDamageOfMove(otherPokemon, playersPokemon, enemyMove);
					playersPokemon.decreasePokemonHealth(damageOfEnemyMove);
				}
				else {
					if (strcmp(textForTextBox[1].c_str(), "")) {
						textForTextBox[0] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "! It missed!";
					}
					else {
						textForTextBox[1] = otherPokemon.pokemonName + " used " + enemyMove.moveName + "! It missed!";
					}
				}
				
			}

			
		}
	}

	// The pokemon turn when the player has an attack
	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{
		// First of all, check who goes first

		playersPokemon.printMonsterDetails();
		otherPokemon.printMonsterDetails();

		// Player goes first
		if (playersPokemon.speedActual >= otherPokemon.speedActual) {
			textForTextBox[0] = playersPokemon.pokemonName + " used " + playerMoveUsed.moveName + "!";
			// Checks to see if its a status move
			// Otherwise works the damage out and decreases the enemy healt
			if (playerMoveUsed.typeOfMove == MoveCategory::Status) {
				statusMove(otherPokemon, playersPokemon, playerMoveUsed);
			}
			else {
				if (doesAttackHit(playerMoveUsed.accuracy)) {
					int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
					otherPokemon.decreasePokemonHealth(damageOfMove);
				}
				else {
					textForTextBox[0] = playersPokemon.pokemonName + " used " + playerMoveUsed.moveName + "! It missed!";
				}
			}
			
			if (otherPokemon.currentHealth != 0) {
				enemyAttack(playersPokemon, otherPokemon);
			}
			else {
				textForTextBox[1] = otherPokemon.pokemonName + " fainted!";
			}
		}
		// Enemy goes first
		else {
			// Does the enemy attack
			enemyAttack(playersPokemon, otherPokemon);

			// if the players pokemon doesnt die, do their move
			if (playersPokemon.currentHealth != 0) {
				textForTextBox[1] = playersPokemon.pokemonName + " used " + playerMoveUsed.moveName + "!";
				if (playerMoveUsed.typeOfMove == MoveCategory::Status) {
					statusMove(otherPokemon, playersPokemon, playerMoveUsed);
				}
				else {
					if (doesAttackHit(playerMoveUsed.accuracy)) {
						int damageOfMove = calcDamageOfMove(playersPokemon, otherPokemon, playerMoveUsed);
						otherPokemon.decreasePokemonHealth(damageOfMove);
					}
					else {
						textForTextBox[1] = playersPokemon.pokemonName + " used " + playerMoveUsed.moveName + "! It missed!";
					}
					
				}
			}
			else {
				textForTextBox[1] = playersPokemon.pokemonName + " fainted!";
			}
		}

	}

	// Generates a random number
	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	bool doesAttackHit(int accuracyOfMove) {
		int ranN = random(0, 100);
		if (ranN <= accuracyOfMove) {
			return true;
		}
		return false;
	}

	// A turn when only the opponents pokemon has their attack
	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {
		enemyAttack(playersPokemon, otherPokemon);
	}

};

	

