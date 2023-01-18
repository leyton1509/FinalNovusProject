
#include <map>
#include "Move.h"

using namespace std;

class MoveManager
{

public:

    map<int, Move> moveStorage = {};

    Move getMoveDetails(int moveID) {

        auto getter = moveStorage.find(moveID);

        if (getter == moveStorage.end()) {
            return Move();
        }
        else {
            return getter->second;
        }
    }

    MoveManager() {
        moveStorage.insert({ 1, Move(1,	"Pound", PokemonType::PokemonTypes::Normal ,MoveCategory::Categories::Physical,	35,	40, 100)});
        moveStorage.insert({ 2, Move(2,	"Karate Chop", PokemonType::PokemonTypes::Fighting ,MoveCategory::Categories::Physical,	25,	50, 100) });

    }

};
