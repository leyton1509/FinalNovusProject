#include <string>
#include <iostream>
#include "../Pokemon/PokemonType.h"
#include "../Pokemon/Moves/Move.h"
#include "../Pokemon/Moves/MoveManager.h"
#include <map>


using namespace std;


class Pokemon
{

public:

	string pokemonName;

	int currentHealth;

	int healthBase;
	int physcialAttackBase;
	int physicalDefenceBase;
	int specialAttackBase;
	int specialDefenceBase;
	int speedBase;

	int healthActual;
	int physcialAttackActual;
	int physicalDefenceActual;
	int specialAttackActual;
	int specialDefenceActual;
	int speedActual;

	int iv;
	int level;
	double experience;
	double nextExperienceNeeded;

	int xPositionOnSpriteSheet; 
	int yPositionOnSpriteSheet;

	PokemonType::PokemonTypes pokemonTypeOne;
	PokemonType::PokemonTypes pokemonTypeTwo;

	int evolutionLevel;
	string evolutionName;

	int numberOfLastStoredMove = 0;
	int numberOfMoves = 0;

	Move pokemonsMoves[4];

	map<int, int> levelUpMoveSet;

	bool isPokemonDead = false;


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


	Pokemon(string _pokemonName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level, int _xPositionOnSpriteSheet, int _yPositionOnSpriteSheet, PokemonType::PokemonTypes _pokemonTypeOne, PokemonType::PokemonTypes _pokemonTypeTwo, map<int, int> _levelUpMoveSet, int _evolutionLevel, string _evolutionName)  {
		pokemonName = _pokemonName;
		healthBase = _healthBase;
		physcialAttackBase = _physcialAttackBase;
		physicalDefenceBase = _physicalDefenceBase;
		specialAttackBase = _specialAttackBase;
		specialDefenceBase = _specialDefenceBase;
		speedBase = _speedBase;
		level = _level;
		iv = generateRandomIV();
		experience = 0;
		calculateNextLevelExperienceNeeded();
		calculateActualStatistics();
		xPositionOnSpriteSheet = _xPositionOnSpriteSheet;
		yPositionOnSpriteSheet = _yPositionOnSpriteSheet;
		pokemonTypeOne = _pokemonTypeOne;
		pokemonTypeTwo = _pokemonTypeTwo;
		levelUpMoveSet = _levelUpMoveSet;
		updateMoveSet();
		currentHealth = healthActual;
		evolutionLevel = _evolutionLevel;
		evolutionName = _evolutionName;
	}

	void healPokemonToFull() {
		currentHealth = healthActual;
		for (int i = 0; i < numberOfMoves; i++)
		{
			pokemonsMoves[i].currentPowerPoints = pokemonsMoves[i].powerpoints;
		}
		isPokemonDead = false;
	}

	// returns true if pokemon is dead
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

	void increasePokemonHealth(int amountToIncreaseBy) {
		if (currentHealth + amountToIncreaseBy > healthActual) {
			currentHealth = healthActual;
		}
		else {
			currentHealth = currentHealth + amountToIncreaseBy;
		}
	}

	void updateMoveSet() {
		MoveManager mm = mm.instance();
		for (const pair<int, int>& p : levelUpMoveSet) {

			if (p.second != 0 ){
				if (p.second <= level){
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
	}

	void calculateNextLevelExperienceNeeded() {
		nextExperienceNeeded = pow(level, 3);
	}

	// This code should be used either for setting trainers or wild pokemon or testing
	void setPokemonsLevel(int newLevel) {
		level = newLevel;
		calculateActualStatistics();
		calculateNextLevelExperienceNeeded();
		currentHealth = healthActual;
		updateMoveSet();

	}
	

	pair<bool, pair<int, int>> gainExperience(int _experiencedGained, Pokemon p) {

		pair<int, int> pairReturn = { -1, -1 };
		bool shouldEvolve = false;
		experience = experience + _experiencedGained;
		cout << "\n\nGained:" << _experiencedGained  << "Experience Total:" << experience << " nextExperienceNeeded : " << nextExperienceNeeded << "\n\n";
		while(experience > nextExperienceNeeded){
			level += 1;
			if (level >= evolutionLevel && strcmp(evolutionName.c_str(), "No") !=0) {
				// 	Pokemon(string _pokemonName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level, int _xPositionOnSpriteSheet, int _yPositionOnSpriteSheet, PokemonType::PokemonTypes _pokemonTypeOne, PokemonType::PokemonTypes _pokemonTypeTwo, map<int, int> _levelUpMoveSet, int _evolutionLevel, string _evolutionName)  {
				shouldEvolve = true;
				

			}
		   

			for (const pair<int, int>& p : levelUpMoveSet) {

				
				if (p.second != 0) {
					if (p.second == level) {
						pairReturn = p;
					}
				}
			}


			calculateNextLevelExperienceNeeded();
		}
		calculateActualStatistics();
		pair<bool, pair<int, int>> returnPair = { shouldEvolve, pairReturn  };
		return returnPair;
	}
	int experienceUponKill() {
		return floor((pow(level, 3)) + 2);
	}


	void calculateActualStatistics() {
		healthActual = healthFormula(healthBase);
		physcialAttackActual = otherStatisticFormula(physcialAttackBase);
		physicalDefenceActual = otherStatisticFormula(physicalDefenceBase);
		specialAttackActual = otherStatisticFormula(specialAttackBase);
		specialDefenceActual = otherStatisticFormula(specialDefenceBase);
		speedActual = otherStatisticFormula(speedBase);
	}

	int healthFormula(int stat) {
		return floor(((((2* stat)+iv )* level) / 100) + level + 10);
	}

	int otherStatisticFormula(int stat) {
		return floor(((((2 * stat) + iv) * level) / 100) + 5);
	}

	int generateRandomIV() {
		return (rand() % 31) + 10;
	}

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

