#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Monster
{

public:

	string monsterName;

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
	float experience;
	float nextExperienceNeeded;

	Sprite monserSprite;

	Monster() {

	}

	Monster(string _monsterName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level) {
		monsterName = _monsterName;
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
	}

	void calculateNextLevelExperienceNeeded() {
		nextExperienceNeeded = ((6 / 5) * pow(level, 3)) - (15 * pow(level, 2)) + (100 * level) - 140;
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
		std::cout << monsterName << "";
		printf("| Level : %d | Health : %d | Attack : %d | Defence : %d | Special Attack : %d | Speed : %d |", level, healthActual, physcialAttackActual, physicalDefenceActual, specialDefenceActual, speedActual);
	}

	










};

