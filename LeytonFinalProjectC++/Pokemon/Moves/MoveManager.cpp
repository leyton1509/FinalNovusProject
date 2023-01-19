
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
        moveStorage.insert({ 25, Move(25,	"Mega Kick",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 5	,120	,80) });
        moveStorage.insert({ 26, Move(26,	"Jump Kick",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 10	,100	,95) });
        moveStorage.insert({ 27, Move(27,	"Rolling Kick",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 15	,60	,85) });
        moveStorage.insert({ 28, Move(28,	"Sand Attack",	PokemonType::PokemonTypes::Ground,	MoveCategory::Categories::Status, 15	,0	,100) });
        moveStorage.insert({ 29, Move(29,	"Headbutt",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 15	,70	,100) });
        moveStorage.insert({ 30, Move(30,	"Horn Attack",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 25	,65	,100) });
        moveStorage.insert({ 31, Move(31,	"Fury Attack",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,75	,85) });
        moveStorage.insert({ 32, Move(32,	"Horn Drill",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 5	,400	,30) });
        moveStorage.insert({ 33, Move(33,	"Tackle",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 35	,40	,100) });
        moveStorage.insert({ 34, Move(34,	"Body Slam",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 15	,85	,100) });
        moveStorage.insert({ 30, Move(30,	"Wrap",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 25	,15	,90) });
        moveStorage.insert({ 36, Move(36,	"Take Down",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,90	,85) });
        moveStorage.insert({ 37, Move(37,	"Thrash",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 10	,120	,100) });
        moveStorage.insert({ 38, Move(38,	"Double Edge",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 15	,120	,85) });
        moveStorage.insert({ 39, Move(39,	"Tail Whip",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 30	,0	,100) });
        moveStorage.insert({ 40, Move(40,	"Poison Sting",	PokemonType::PokemonTypes::Poison,	MoveCategory::Categories::Physical, 35	,15	,100) });
        moveStorage.insert({ 41, Move(41,	"Twin Needle",	PokemonType::PokemonTypes::Bug,	MoveCategory::Categories::Physical, 20	,50	,100) });
        moveStorage.insert({ 42, Move(42,	"Pin Missle",	PokemonType::PokemonTypes::Bug,	MoveCategory::Categories::Physical, 20	,75	,100) });
        moveStorage.insert({ 43, Move(43,	"Leer",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 30	,0	,100) });
        moveStorage.insert({ 44, Move(44,	"Bite",	PokemonType::PokemonTypes::Dark,	MoveCategory::Categories::Physical, 25	,60	,100) });
        moveStorage.insert({ 45, Move(45,	"Growl",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 40	,0	,100) });
        moveStorage.insert({ 46, Move(46,	"Roar",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 47, Move(47,	"Sing",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 15	,0	,55) });
        moveStorage.insert({ 48, Move(48,	"Supersonic",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 20	,0	,55) });
        moveStorage.insert({ 49, Move(49,	"Sonic Boom",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Special, 40	,40	,90) });
        moveStorage.insert({ 50, Move(50,	"Disable",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 51, Move(51,	"Acid",	PokemonType::PokemonTypes::Poison,	MoveCategory::Categories::Special, 30	,40	,100) });
        moveStorage.insert({ 52, Move(52,	"Ember",	PokemonType::PokemonTypes::Fire,	MoveCategory::Categories::Special, 25	,40	,100) });
        moveStorage.insert({ 53, Move(53,	"Flamethrower",	PokemonType::PokemonTypes::Fire,	MoveCategory::Categories::Special, 15	,90	,100) });
        moveStorage.insert({ 54, Move(54,	"Mist",	PokemonType::PokemonTypes::Ice,	MoveCategory::Categories::Status, 30	,0	,100) });
        moveStorage.insert({ 55, Move(55,	"Water Gun",	PokemonType::PokemonTypes::Water,	MoveCategory::Categories::Special, 25	,40	,100) });
        moveStorage.insert({ 56, Move(56,	"Hydro Pump",	PokemonType::PokemonTypes::Water,	MoveCategory::Categories::Special, 5	,110	,80) });
        moveStorage.insert({ 57, Move(57,	"Surf",	PokemonType::PokemonTypes::Water,	MoveCategory::Categories::Special, 15	,90	,100) });
        moveStorage.insert({ 58, Move(58,	"Ice Beam",	PokemonType::PokemonTypes::Ice,	MoveCategory::Categories::Special, 10	,90	,100) });
        moveStorage.insert({ 59, Move(59,	"Blizzard",	PokemonType::PokemonTypes::Ice,	MoveCategory::Categories::Special, 5	,110	,70) });
        moveStorage.insert({ 60, Move(60,	"Psybeam",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Special, 20	,65	,100) });
        moveStorage.insert({ 61, Move(61,	"Bubble Beam",	PokemonType::PokemonTypes::Water,	MoveCategory::Categories::Special, 20	,65	,100) });
        moveStorage.insert({ 62, Move(62,	"Aurora Beam",	PokemonType::PokemonTypes::Ice,	MoveCategory::Categories::Special, 20	,65	,100) });
        moveStorage.insert({ 63, Move(63,	"Hyper Beam",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Special, 5	,150	,100) });
        moveStorage.insert({ 64, Move(64,	"Peck",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Physical, 35	,35	,100) });
        moveStorage.insert({ 65, Move(65,	"Drill Peck",	PokemonType::PokemonTypes::Flying,	MoveCategory::Categories::Physical, 20	,80	,100) });
        moveStorage.insert({ 66, Move(66,	"Submission",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 20	,80	,80) });
        moveStorage.insert({ 67, Move(67,	"Low Kick",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 20	,80	,100) });
        moveStorage.insert({ 68, Move(68,	"Counter",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 20	,100	,100) });
        moveStorage.insert({ 69, Move(69,	"Seismic Toss",	PokemonType::PokemonTypes::Fighting,	MoveCategory::Categories::Physical, 20	,50	,100) });
        moveStorage.insert({ 70, Move(70,	"Strength",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,80	,100) });
        moveStorage.insert({ 71, Move(71,	"Absorb",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Special, 25	,20	,100) });
        moveStorage.insert({ 72, Move(72,	"Mega Drain",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Special, 25	,40	,100) });
        moveStorage.insert({ 73, Move(73,	"Leech Seed",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Status, 10	,0	,100) });
        moveStorage.insert({ 74, Move(74,	"Growth",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 75, Move(75,	"Razor Leaf",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Physical, 25	,55	,100) });
        moveStorage.insert({ 76, Move(76,	"Solar Beam",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Special, 5	,120	,100) });
        moveStorage.insert({ 77, Move(77,	"Poison Powder",	PokemonType::PokemonTypes::Poison,	MoveCategory::Categories::Status, 25	,0	,75) });
        moveStorage.insert({ 78, Move(78,	"Stun Spore",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Status, 25	,0	,75) });
        moveStorage.insert({ 79, Move(79,	"Sleep Powder",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 80, Move(80,	"Petal Dance",	PokemonType::PokemonTypes::Grass,	MoveCategory::Categories::Special, 10	,120	,100) });
        moveStorage.insert({ 81, Move(81,	"String Shot",	PokemonType::PokemonTypes::Bug,	MoveCategory::Categories::Status, 40	,0	,100) });
        moveStorage.insert({ 82, Move(82,	"Dragon Rage",	PokemonType::PokemonTypes::Dragon,	MoveCategory::Categories::Physical, 40	,0	,100) });
        moveStorage.insert({ 83, Move(83,	"Fire Spin",	PokemonType::PokemonTypes::Fire,	MoveCategory::Categories::Special, 15	,35	,85) });
        moveStorage.insert({ 84, Move(84,	"Thunder Shock",	PokemonType::PokemonTypes::Electric,	MoveCategory::Categories::Special, 30	,40	,100) });
        moveStorage.insert({ 85, Move(85,	"Thunderbolt",	PokemonType::PokemonTypes::Electric,	MoveCategory::Categories::Special, 15	,90	,100) });
        moveStorage.insert({ 86, Move(86,	"Thunder Wave",	PokemonType::PokemonTypes::Electric,	MoveCategory::Categories::Status, 20	,0	,90) });
        moveStorage.insert({ 87, Move(87,	"Thunder",	PokemonType::PokemonTypes::Electric,	MoveCategory::Categories::Physical, 10	,110	,70) });
        moveStorage.insert({ 88, Move(88,	"Rock Throw",	PokemonType::PokemonTypes::Rock,	MoveCategory::Categories::Special, 15	,50	,90) });
        moveStorage.insert({ 89, Move(89,	"Earthquake",	PokemonType::PokemonTypes::Ground,	MoveCategory::Categories::Special, 10	,100	,100) });
        moveStorage.insert({ 90, Move(90,	"Fissure",	PokemonType::PokemonTypes::Ground,	MoveCategory::Categories::Special, 5	,400	,30) });
        moveStorage.insert({ 91, Move(91,	"Dig",	PokemonType::PokemonTypes::Ground,	MoveCategory::Categories::Physical, 10	,80	,100) });
        moveStorage.insert({ 92, Move(92,	"Toxic",	PokemonType::PokemonTypes::Poison,	MoveCategory::Categories::Status, 10	,0	,90) });
        moveStorage.insert({ 93, Move(93,	"Confusion",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Special, 25	,50	,100) });
        moveStorage.insert({ 94, Move(94,	"Psychic",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Special, 10	,90	,100) });
        moveStorage.insert({ 95, Move(95,	"Hypnosis",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 96, Move(96,	"Meditate",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Status, 20	,0	,100) });
        moveStorage.insert({ 97, Move(97,	"Agillity",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Status, 10	,0	,100) });
        moveStorage.insert({ 98, Move(98,	"Quick Attack",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 20	,40	,100) });
        moveStorage.insert({ 99, Move(99,	"Rage",	PokemonType::PokemonTypes::Normal,	MoveCategory::Categories::Physical, 40	,40	,100) });
        moveStorage.insert({ 100, Move(100,	"Teleport",	PokemonType::PokemonTypes::Psychic,	MoveCategory::Categories::Status, 10	,0	,100) });

    }

};
