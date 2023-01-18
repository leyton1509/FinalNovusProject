
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
        moveStorage.insert({ 11, Move(11,	"Vise Grip",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 30	,55	,100) });
        moveStorage.insert({ 12, Move(12,	"Guillotine",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 5	,400	,30) });
        moveStorage.insert({ 13, Move(13,	"Razor Wind",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Special, 10	,80	,85) });
        moveStorage.insert({ 14, Move(14,	"Swords Dance",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 15, Move(15,	"Cut",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 30	,50	,100) });
        moveStorage.insert({ 16, Move(16,	"Gust",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Special, 35	,40	,100) });
        moveStorage.insert({ 17, Move(17,	"Wing Attack",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Physical, 35	,60	,100) });
        moveStorage.insert({ 18, Move(18,	"Whirlwind",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 19, Move(19,	"Fly",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Physical, 15	,90	,95) });
        moveStorage.insert({ 20, Move(20,	"Bind",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,15	,85) });
        moveStorage.insert({ 21, Move(21,	"Slam",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,80	,75) });
        moveStorage.insert({ 22, Move(22,	"Vine Whip",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Physical, 25	,45	,100) });
        moveStorage.insert({ 23, Move(23,	"Stomp",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,65	,100) });
        moveStorage.insert({ 24, Move(24,	"Double Kick",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 30	,60	,100) });
        moveStorage.insert({ 25, Move(25,	"Jump Kick",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 10	,100	,95) });
    }

};
