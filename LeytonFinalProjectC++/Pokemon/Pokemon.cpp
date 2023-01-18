#include <string>
#include <iostream>
#include "../Pokemon/PokemonType.h"

using namespace std;


class Pokemon
{

public:

	string pokemonName;

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

	}


	Pokemon(string _pokemonName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level, int _xPositionOnSpriteSheet, int _yPositionOnSpriteSheet, PokemonType::PokemonTypes _pokemonTypeOne, PokemonType::PokemonTypes _pokemonTypeTwo)  {
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

	}

	void calculateNextLevelExperienceNeeded() {
		nextExperienceNeeded = ((6 / 5) * pow(level, 3)) - (15 * pow(level, 2)) + (100 * level) - 140;
	}

	

	void gainExperience(int _experiencedGained) {
		experience = experience + _experiencedGained;

		while(experience > nextExperienceNeeded){
			level += 1;
			// experience = 0;
			calculateNextLevelExperienceNeeded();
		}

	}
	int experienceUponKill() {
		return floor((2 * level / 7));
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
		std::cout << pokemonName << "";
		printf("| Level : %d | Health : %d | Attack : %d | Defence : %d | Special Attack : %d | Speed : %d |", level, healthActual, physcialAttackActual, physicalDefenceActual, specialDefenceActual, speedActual);
	}

	










};

