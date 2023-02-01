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
		//Trainer t1 = ;
		//trainerList.push_front();

		return trainerList;
	}

	TrainerManager() {
		// const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet, int _xTileForSpriteSheet, int _yTileForSpriteSheet
		trainers.insert({ 1, Trainer("Elm", 10, 10, trainerStyleSheet, 0, 0) });
	}

	Trainer getDefaultPokemon(int trainerNum) {

		auto getter = trainers.find(trainerNum);

		if (getter == trainers.end()) {
			return;
		}
		else {
			return getter->second;
		}
	}
};