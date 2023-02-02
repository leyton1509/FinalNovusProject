#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/Spriteheader.h"
#include <map>
#include "../Sprites/Trainer.h"
#include <list>

class TrainerManager{

public :

	ALLEGRO_BITMAP * trainerStyleSheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PlayerSprites/Trainers.png");

	std::map<int, Trainer> trainers = {};

	std::list<Trainer> getTrainersForMap(int mapNumber) {

		std::list<Trainer> trainerList = {};
		if (mapNumber==1) {
			Trainer t1 = getTrainer(11);
			t1.setPositions(15, 12, 0, 1);
			trainerList.push_front(t1);
		}
		

		return trainerList;
	}

	TrainerManager() {
		// const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet, int _xTileForSpriteSheet, int _yTileForSpriteSheet
		trainers.insert({ 1, Trainer("Elm", 1, 1, trainerStyleSheet, 0, 0) });
		trainers.insert({ 2, Trainer("Rival", 1, 1, trainerStyleSheet, 3, 0) });
		trainers.insert({ 3, Trainer("Steven", 1, 1, trainerStyleSheet, 6, 0) });
		trainers.insert({ 4, Trainer("Old Woman", 1, 1, trainerStyleSheet, 9, 0) });
		trainers.insert({ 5, Trainer("Old Woman", 1, 1, trainerStyleSheet, 12, 0) });
		trainers.insert({ 6, Trainer("Small Boy", 1, 1, trainerStyleSheet, 15, 0) });
		trainers.insert({ 7, Trainer("Small Girl", 1, 1, trainerStyleSheet, 18, 0) });
		trainers.insert({ 8, Trainer("Joey", 1, 1, trainerStyleSheet, 21, 0) });
		trainers.insert({ 9, Trainer("Bug Catcher", 1, 1, trainerStyleSheet, 24, 0) });
		trainers.insert({ 10, Trainer("Young Man", 1, 1, trainerStyleSheet, 27, 0) });

		trainers.insert({ 11, Trainer("Emma", 1, 1, trainerStyleSheet, 0, 4) });
		trainers.insert({ 12, Trainer("Jim", 1, 1, trainerStyleSheet, 3, 4) });
		trainers.insert({ 13, Trainer("John", 1, 1, trainerStyleSheet, 6, 4) });
		trainers.insert({ 14, Trainer("Max", 1, 1, trainerStyleSheet, 9, 4) });
		trainers.insert({ 15, Trainer("Ace", 1, 1, trainerStyleSheet, 12, 4) });
		trainers.insert({ 16, Trainer("Sammy", 1, 1, trainerStyleSheet, 15, 4) });
		trainers.insert({ 17, Trainer("Abi", 1, 1, trainerStyleSheet, 18, 4) });
		trainers.insert({ 18, Trainer("Female Ace", 1, 1, trainerStyleSheet, 21, 4) });
		trainers.insert({ 19, Trainer("Old Man Tom", 1, 1, trainerStyleSheet, 24, 4) });
		trainers.insert({ 20, Trainer("Cook Sammy", 1, 1, trainerStyleSheet, 27, 4) });

		trainers.insert({ 21, Trainer("Old Man Tom", 1, 1, trainerStyleSheet, 0, 8) });
		trainers.insert({ 22, Trainer("Old Woman Jannet", 1, 1, trainerStyleSheet, 3, 8) });
		trainers.insert({ 23, Trainer("Bob", 1, 1, trainerStyleSheet, 6, 8) });
		trainers.insert({ 24, Trainer("Uryu", 1, 1, trainerStyleSheet, 9, 8) });
		trainers.insert({ 25, Trainer("Looker", 1, 1, trainerStyleSheet, 12, 8) });
		trainers.insert({ 26, Trainer("Swimmer Geoff", 1, 1, trainerStyleSheet, 15, 8) });
		trainers.insert({ 27, Trainer("Swimmer Abi", 1, 1, trainerStyleSheet, 18, 8) });
		trainers.insert({ 28, Trainer("Ajay", 1, 1, trainerStyleSheet, 21, 8) });
		trainers.insert({ 29, Trainer("Blue", 1, 1, trainerStyleSheet, 24, 8) });
		trainers.insert({ 30, Trainer("Purple", 1, 1, trainerStyleSheet, 27, 8) });

		trainers.insert({ 31, Trainer("Whitney", 1, 1, trainerStyleSheet, 0, 12) });
		trainers.insert({ 32, Trainer("Lance", 1, 1, trainerStyleSheet, 3, 12) });
		trainers.insert({ 33, Trainer("Rock", 1, 1, trainerStyleSheet, 6, 12) });
		trainers.insert({ 34, Trainer("Jasmine", 1, 1, trainerStyleSheet, 9, 12) });
		trainers.insert({ 35, Trainer("Walrod", 1, 1, trainerStyleSheet, 12, 12) });
		trainers.insert({ 36, Trainer("J", 1, 1, trainerStyleSheet, 15, 12) });
		trainers.insert({ 37, Trainer("Phantom", 1, 1, trainerStyleSheet, 18, 12) });
		trainers.insert({ 38, Trainer("Ross", 1, 1, trainerStyleSheet, 21, 12) });
		trainers.insert({ 39, Trainer("Fighter Sam", 1, 1, trainerStyleSheet, 24, 12) });
		trainers.insert({ 40, Trainer("Gardiena", 1, 1, trainerStyleSheet, 27, 12) });
	}

	Trainer getTrainer(int trainerNum) {

		auto getter = trainers.find(trainerNum);

		if (getter == trainers.end()) {
			return Trainer();
		}
		else {
			return getter->second;
		}
	}
};