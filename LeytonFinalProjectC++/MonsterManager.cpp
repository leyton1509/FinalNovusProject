
#include <map>
#include <string>
#include "Monster.cpp"

using namespace std;

class MonsterManager
{

public:
    map<string, Monster> defaultMonsterStorage = {};

    Monster getDefaultMonster(string _monsterName) {

        auto getter = defaultMonsterStorage.find(_monsterName);
        
        if (getter == defaultMonsterStorage.end()) {
            return Monster();
        }
        else {
            return getter->second;
        }
    }

    MonsterManager() {
        defaultMonsterStorage.insert({ "Charizard", Monster("Charizard", 100, 110, 70, 140, 80, 100, 1) });
        defaultMonsterStorage.insert({ "Blastoise", Monster("Blastoise", 120, 70, 100, 120, 120, 70, 1) });
        defaultMonsterStorage.insert({ "Venasaur", Monster("Venasaur", 140, 50, 90, 100, 110, 60, 1) });
    }

};
