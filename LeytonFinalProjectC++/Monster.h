#include <string>
#include <SFML/Graphics.hpp>
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

	int level;
	float experience;
	float nextExperienceNeeded;

	Sprite monserSprite;

	Monster(string _monsterName, int _healthBase, int _physcialAttackBase, int _physicalDefenceBase, int _specialAttackBase, int _specialDefenceBase, int _speedBase, int _level) {
		monsterName = _monsterName;
		healthBase = _healthBase;
		physcialAttackBase = _physcialAttackBase;
		physicalDefenceBase = _physicalDefenceBase;
		specialAttackBase = _specialAttackBase;
		specialDefenceBase = _specialDefenceBase;
		speedBase = _speedBase;
		level = _level;
	}

	void calculateActualStats() {

	}

	


};

