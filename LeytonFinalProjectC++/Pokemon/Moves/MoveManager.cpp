
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
        moveStorage.insert({ 2, Move(2,	"Karate Chop", PokemonType::PokemonTypes::Fighting ,MoveCategory::Categories::Physical,	25,	50, 100)});
        moveStorage.insert({ 3, Move(3,	"Double Slap",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,15	,85 )});
        moveStorage.insert({ 4, Move(4,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 5, Move(5,	"Mega Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,80	,85) });
        moveStorage.insert({ 6, Move(6,	"Pay Day",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,40	,100) });
        moveStorage.insert({ 7, Move(7,	"Fire Punch",	PokemonType::PokemonTypes::Fire,	MoveCategory::Categories::Physical, 15	,75	,100) });
        moveStorage.insert({ 8, Move(8,	"Ice Punch",	PokemonType::PokemonTypes::Ice,	MoveCategory::Categories::Physical, 15	,75	,100) });
        moveStorage.insert({ 9, Move(9,	"Thunder Punch",	PokemonType::PokemonTypes::Electric,	MoveCategory::Categories::Physical, 15	,75	,100) });
        moveStorage.insert({ 10, Move(10,	"Sratch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 35	,40	,100) });




        moveStorage.insert({ 11, Move(11,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 12, Move(12,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 13, Move(13,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 14, Move(14,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 15, Move(15,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 16, Move(16,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 17, Move(17,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 18, Move(18,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
        moveStorage.insert({ 19, Move(19,	"Comet Punch",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,18	,85) });
    }

};
