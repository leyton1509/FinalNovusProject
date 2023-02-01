#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/Spriteheader.h"
#include <map>
#include "../Sprites/Trainer.h"

class TrainerManager{

public :

	ALLEGRO_BITMAP * trainerStyleSheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PlayerSprites/Trainers.png");

	std::map<int, Trainer> trainers = {};

	TrainerManager() {

	}
};