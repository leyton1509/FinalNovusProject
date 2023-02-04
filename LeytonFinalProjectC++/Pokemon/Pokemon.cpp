#include <string>
#include <iostream>
#include "../Pokemon/PokemonType.h"
#include "../Pokemon/Moves/Move.h"
#include "../Pokemon/Moves/MoveManager.h"
#include <map>


using namespace std;

// Class to repreesnt a Pokemon
class Pokemon
{

public:

	// The name of the pokemon 
	string pokemonName;
	// The current health of program
	int currentHealth;
	
	// The base stats of the pokemon
	int healthBase;
	int physcialAttackBase;
	int physicalDefenceBase;
	int specialAttackBase;
	int specialDefenceBase;
	int speedBase;

	// The actual stats of the pokemon calculated from the base stats
	int healthActual;
	int physcialAttackActual;
	int physicalDefenceActual;
	int specialAttackActual;
	int specialDefenceActual;
	int speedActual;

	// A random number to determine how good the pokemon is
	int iv;
	// The level of pokwmon
	int level;
	// The current experience
	double experience;
	// How much experience is needed for the next level
	double nextExperienceNeeded;

	// The x and y position on the sprite sheet
	int xPositionOnSpriteSheet; 
	int yPositionOnSpriteSheet;

	// The type of pokemon
	PokemonType::PokemonTypes pokemonTypeOne;
	PokemonType::PokemonTypes pokemonTypeTwo;

	// The level and name of evolution
	int evolutionLevel;
	string evolutionName;

	// The number of last stored move and the number of moves the pokemon has
	int numberOfLastStoredMove = 0;
	int numberOfMoves = 0;

	// A list of pokemon moves
	Move pokemonsMoves[4];

	// THe pokemons move set
	map<int, int> levelUpMoveSet;

	// If the pokemon is dead
	bool isPokemonDead = false;

	// Empty Constructor
	// Needed for not returned in map
	Pokemon(){
		pokemonName = "";
		healthBase = 0;
		physcialAttackBase = 0;
		physicalDefenceBase = 0;
		specialAttackBase = 0;
		specialDefenceBase = 0;
		speedBase = 0;
		level = 0;
		iv = generateRandomIV();
		experience = 0;
		calculateNextLevelExperienceNeeded();
		calculateActualStatistics();
		xPositionOnSpriteSheet = 0;
		yPositionOnSpriteSheet = 0;
		pokemonTypeOne = PokemonType::PokemonTypes::Normal;
		pokemonTypeTwo = PokemonType::PokemonTypes::None;
		Move pokemonsMoves[4] = {Move()};
		currentHealth = healthActual;
		evolutionLevel = 0;
		evolutionName = "";
	}

	// Constructor that takes the pokemon info to store
	// Name, base stats, level, style sheet locs, types, moves and evolution info
	Pokemon(string _pokemonName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level, int _xPositionOnSpriteSheet, int _yPositionOnSpriteSheet, PokemonType::PokemonTypes _pokemonTypeOne, PokemonType::PokemonTypes _pokemonTypeTwo, map<int, int> _levelUpMoveSet, int _evolutionLevel, string _evolutionName)  {
		pokemonName = _pokemonName;
		healthBase = _healthBase;
		physcialAttackBase = _physcialAttackBase;
		physicalDefenceBase = _physicalDefenceBase;
		specialAttackBase = _specialAttackBase;
		specialDefenceBase = _specialDefenceBase;
		speedBase = _speedBase;
		level = _level;
		// Generates a randon iv
		iv = generateRandomIV();
		experience = 0;
		// Calculates the next experience needed from the level
		calculateNextLevelExperienceNeeded();
		// Calculates the actual stats from the base stats
		calculateActualStatistics();
		xPositionOnSpriteSheet = _xPositionOnSpriteSheet;
		yPositionOnSpriteSheet = _yPositionOnSpriteSheet;
		pokemonTypeOne = _pokemonTypeOne;
		pokemonTypeTwo = _pokemonTypeTwo;
		levelUpMoveSet = _levelUpMoveSet;
		// Updates the pokemons move set
		updateMoveSet();
		currentHealth = healthActual;
		evolutionLevel = _evolutionLevel;
		evolutionName = _evolutionName;
	}

	// Heals the pokemon to full
	// Puts health to full and sets the powerpoints to full
	// Sets dead to full
	void healPokemonToFull() {
		currentHealth = healthActual;
		for (int i = 0; i < numberOfMoves; i++)
		{
			pokemonsMoves[i].currentPowerPoints = pokemonsMoves[i].powerpoints;
		}
		isPokemonDead = false;
	}

	// returns true if pokemon is dead
	// Decreases the pokemon health
	// Will set health to zero, no lower
	bool decreasePokemonHealth(int amountToDecreaseBy) {
		if (currentHealth - amountToDecreaseBy > 0) {
			currentHealth = currentHealth - amountToDecreaseBy;
			return false;
		}
		else {
			currentHealth = 0;
			isPokemonDead = true;
			return true;
		}
	}

	// Will set health to + the increased amount
	// Wont set higher than actual health
	void increasePokemonHealth(int amountToIncreaseBy) {
		if (currentHealth + amountToIncreaseBy > healthActual) {
			currentHealth = healthActual;
		}
		else {
			currentHealth = currentHealth + amountToIncreaseBy;
		}
	}

	// Updates the move set of the pokemon
	// Loops through the pairs
	// If the pokemon level is above learned levels
	// Loops through the moves in order 0-> 4 -> 0 when setting
	void updateMoveSet() {
		MoveManager mm = mm.instance();
		for (const pair<int, int>& p : levelUpMoveSet) {

			if (p.second <= level && p.first != 0){
				if (numberOfLastStoredMove < 4) {
					pokemonsMoves[numberOfLastStoredMove] = mm.getMoveDetails(p.first);
					numberOfLastStoredMove++;
					if (numberOfMoves < 4) {
						numberOfMoves++;
					}
				}
				else {
					numberOfLastStoredMove = 0;
					pokemonsMoves[numberOfLastStoredMove] = mm.getMoveDetails(p.first);
				}
			}
			
		}
	}

	// Calculates the next experience level needed
	void calculateNextLevelExperienceNeeded() {
		nextExperienceNeeded = pow(level, 3);
	}

	// This code should be used either for setting trainers or wild pokemon or testing
	// Sets the lvel abd calcualtes the stats and experience needed and updates move set
	void setPokemonsLevel(int newLevel) {
		level = newLevel;
		calculateActualStatistics();
		calculateNextLevelExperienceNeeded();
		currentHealth = healthActual;
		updateMoveSet();

	}
	
	//  Increases the pokemon experience
	// Returns a pair of if the pokemon needs to evolve, and the moveID / level
	pair<bool, pair<int, int>> gainExperience(int _experiencedGained) {

		pair<int, int> pairReturn = { -1, -1 };
		bool shouldEvolve = false;
		experience = experience + _experiencedGained;
		// Checks to see if the pokemon should level
		while(experience > nextExperienceNeeded){
			level += 1;
			// If the level is above the evolution name and the name != no
			if (level >= evolutionLevel && strcmp(evolutionName.c_str(), "No") !=0) {
				shouldEvolve = true;
			}
		   
			// Loops through the moveset to see if there is a new move at thus level
			for (const pair<int, int>& p : levelUpMoveSet) {
				if (p.second != 0) {
					if (p.second == level) {
						pairReturn = p;
					}
				}
			}

			// Calc the new experience
			calculateNextLevelExperienceNeeded();
		}
		// Calculate the new stats
		calculateActualStatistics();
		pair<bool, pair<int, int>> returnPair = { shouldEvolve, pairReturn  };
		return returnPair;
	}

	// Returns the amount exp on kill
	int experienceUponKill() {
		return floor((pow(level, 3)) + 2);
	}

	// Calculates the actual statistic of each stat from the formulas
	void calculateActualStatistics() {
		healthActual = healthFormula(healthBase);
		physcialAttackActual = otherStatisticFormula(physcialAttackBase);
		physicalDefenceActual = otherStatisticFormula(physicalDefenceBase);
		specialAttackActual = otherStatisticFormula(specialAttackBase);
		specialDefenceActual = otherStatisticFormula(specialDefenceBase);
		speedActual = otherStatisticFormula(speedBase);
	}

	// The formula for health, takes a stat
	int healthFormula(int stat) {
		return floor(((((2* stat)+iv )* level) / 100) + level + 10);
	}
	
	// The fornula for the other stat
	int otherStatisticFormula(int stat) {
		return floor(((((2 * stat) + iv) * level) / 100) + 5);
	}

	// Generates a random iv fron 10 to 31
	int generateRandomIV() {
		return (rand() % 31) + 10;
	}


	// Prints out all the details of the pokemon
	void printMonsterDetails() {
		PokemonType pt = PokemonType();
		std::cout << "|---------------------------------------------------------------------------------;\n";
		std::cout << "| Pokemon Name :" << pokemonName << " |\n";
		std::cout << "| Health :" << healthActual << " |\n";
		std::cout << "| Attack :" << physcialAttackActual << " |\n";
		std::cout << "| Defence :" << physicalDefenceActual << " |\n";
		std::cout << "| Special Attack :" << specialAttackActual << " |\n";
		std::cout << "| Special Defence :" << specialDefenceActual << " |\n";
		std::cout << "| Speed :" << speedActual << " |\n";
		std::cout << "| level :" << level << " |\n";
		std::cout << "| Type :" << pt.getStringFromEnumType(pokemonTypeOne) << " " << pt.getStringFromEnumType(pokemonTypeTwo) << " |\n";
		int counter = 0;
		std::cout << "| MoveSet : \n|";
		for (const pair<int, int>& p : levelUpMoveSet) {
			if (counter == 7) {
				std::cout << p.first << " " << p.second << "|\n|";
				counter = 0;
			}
			else {
				std::cout << p.first << " " << p.second << "  ";
				counter++;
			}
			
		}
		std::cout << " |\n";
		std::cout << "| Current Moves : " << pokemonsMoves[0].moveName << " | " << pokemonsMoves[1].moveName << " | " << pokemonsMoves[2].moveName << " | " << pokemonsMoves[3].moveName << " |\n";
		std::cout << "|---------------------------------------------------------------------------------;";

	}

};

