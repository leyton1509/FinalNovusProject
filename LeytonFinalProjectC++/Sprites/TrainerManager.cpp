#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/Spriteheader.h"
#include <map>
#include "../Sprites/Trainer.h"
#include <list>
#include "../Pokemon/PokemonManager.h"

// Handles all the creating and getting of trainers
class TrainerManager{

public :

	// The style sheet of trainers
	ALLEGRO_BITMAP * trainerStyleSheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PlayerSprites/Trainers.png");

	// A map of trainers
	std::map<int, Trainer> trainers = {};

	// Gets the trainers for the map number
	std::list<Trainer> getTrainersForMap(int mapNumber) {

		PokemonManager pm = pm.instance();

		std::list<Trainer> trainerList = {};
		if (mapNumber==1) {

			std::list<string> strings = {};
			strings.push_back("I hope you choose a good starter!");

			Trainer t1 = getTrainer(8);
			t1.strings = strings;
			strings.pop_front();

			Pokemon p1 = pm.getDefaultPokemon("Starly");
			p1.setPokemonsLevel(4);

			t1.addPokemon(p1);
			t1.setPositions(14, 44, 1, 0, 5);
			trainerList.push_front(t1);

			Trainer t2 = getTrainer(9);

			strings.push_back("The power of the bug knows no bounds!");
			t2.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Weedle");
			p1.setPokemonsLevel(6);
			t2.addPokemon(p1);

			Pokemon p2 = pm.getDefaultPokemon("Caterpie");
			p2.setPokemonsLevel(6);
			t2.addPokemon(p2);

			t2.setPositions(30, 49, -1, 0, 8);
			trainerList.push_front(t2);


			Trainer t3 = getTrainer(11);

			strings.push_back("This route is beautiful!");
			t3.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Murkrow");
			p1.setPokemonsLevel(8);
			t3.addPokemon(p1);

			p2 = pm.getDefaultPokemon("Budew");
			p2.setPokemonsLevel(9);
			t3.addPokemon(p2);

			Pokemon p3 = pm.getDefaultPokemon("Numel");
			p3.setPokemonsLevel(9);
			t3.addPokemon(p3);

			t3.setPositions(15, 58, 1, 0, 5);
			trainerList.push_front(t3);


			Trainer t4 = getTrainer(28);

			strings.push_back("Lets see whose stronger!");
			t4.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Corphish");
			p1.setPokemonsLevel(9);
			t4.addPokemon(p1);

			p2 = pm.getDefaultPokemon("Ralts");
			p2.setPokemonsLevel(10);
			t4.addPokemon(p2);

			p3 = pm.getDefaultPokemon("Larvitar");
			p3.setPokemonsLevel(9);
			t4.addPokemon(p3);

			t4.setPositions(40, 62, -1, 0, 5);
			trainerList.push_front(t4);


			Trainer t5 = getTrainer(15);

			strings.push_back("Lets see how you candle some dragons!");
			t5.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Dratini");
			p1.setPokemonsLevel(11);
			t5.addPokemon(p1);

			p2 = pm.getDefaultPokemon("Bagon");
			p2.setPokemonsLevel(12);
			t5.addPokemon(p2);

			t5.setPositions(23, 70, 0,1, 1);
			trainerList.push_front(t5);


			Trainer t6 = getTrainer(29);

			strings.push_back("My steel pokemon never lose!");
			t6.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Aron");
			p1.setPokemonsLevel(11);
			t6.addPokemon(p1);

			p2 = pm.getDefaultPokemon("Beldum");
			p2.setPokemonsLevel(12);
			t6.addPokemon(p2);

			t6.setPositions(32, 70, 0, 1, 1);
			trainerList.push_front(t6);
		}
		else if (mapNumber == 13) {
			std::list<string> strings = {};
			strings.push_back("Good luck getting passed me!");

			Trainer t1 = getTrainer(42);
			t1.strings = strings;
			strings.pop_front();

			Pokemon p1 = pm.getDefaultPokemon("Staryu");
			p1.setPokemonsLevel(11);

			Pokemon p2 = pm.getDefaultPokemon("Dewgong");
			p2.setPokemonsLevel(12);

			t1.addPokemon(p1);
			t1.addPokemon(p2);
			t1.setPositions(7, 14, 1, 0, 12);
			trainerList.push_front(t1);


			Trainer t2 = getTrainer(17);
			strings.push_back("This gym is for water pokemon only!");
			t2.strings = strings;
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Piplup");
			p1.setPokemonsLevel(13);

			p2 = pm.getDefaultPokemon("Horsea");
			p2.setPokemonsLevel(14);

			t2.addPokemon(p1);
			t2.addPokemon(p2);
			t2.setPositions(11, 9, -1, 0, 12);
			trainerList.push_front(t2);

			Trainer t3 = getTrainer(3);
			t3.shouldFightWithSight = false;
			strings.push_back("Welcome to the Water Gym!");
			strings.push_back("My name is Gail, and i'm excited to be your first gym leader!");
			strings.push_back("Good luck!");
			t3.strings = strings;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();

			p1 = pm.getDefaultPokemon("Buizel");
			p1.setPokemonsLevel(15);

			p2 = pm.getDefaultPokemon("Lombre");
			p2.setPokemonsLevel(15);

			Pokemon p3 = pm.getDefaultPokemon("Gyarados");
			p3.setPokemonsLevel(17);

			t3.addPokemon(p1);
			t3.addPokemon(p2);
			t3.addPokemon(p3);
			t3.setPositions(8, 2, 0, -1, 12);
			trainerList.push_front(t3);


		}
		else if (mapNumber == 20) {
			std::list<string> strings = {};
			strings.push_back("I heard you're new around here.");
			strings.push_back("You should be careful, this region is cursed.");
			strings.push_back("The time god Dialga cursed this region when cultists tried to summon it.");
			strings.push_back("Leave, while you can.");
			Trainer t1 = getTrainer(19);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(9, 8, 0, 1, 1);
			trainerList.push_front(t1);
		}
		else if (mapNumber == 21) {
			std::list<string> strings = {};
			strings.push_back("You look young, i don't know if you should be here.");
			strings.push_back("Get strong.");
			strings.push_back("Quick.");
			Trainer t1 = getTrainer(23);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(2, 8, 1, 0, 1);
			trainerList.push_front(t1);
		}
		else if (mapNumber == 22) {
			std::list<string> strings = {};
			strings.push_back("I heard the first battle leader Gale is a water trainer.");
			strings.push_back("I'd catch something along the way to help.");
			Trainer t1 = getTrainer(13);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(8, 5, 0, 1, 1);
			trainerList.push_front(t1);
		}
		else if (mapNumber == 23) {
			std::list<string> strings = {};
			strings.push_back("Pokemon can evolve and learn new moves at certain levels.");
			strings.push_back("There are some very strong pokemon in this region, be careful.");
			strings.push_back("Though the pokemon are the least of your concerns.");
			Trainer t1 = getTrainer(13);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(3, 2, 0, -1, 1);
			trainerList.push_front(t1);
		}

		else if (mapNumber == 24) {
			std::list<string> strings = {};
			strings.push_back("Welcome to our town Avalon!.");
			strings.push_back("Its named after the Athurian legend.");
			strings.push_back("A place trapped away from reach.");
			strings.push_back("Just like us.");
			Trainer t1 = getTrainer(41);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(5, 9, 0, -1, 2);
			trainerList.push_front(t1);
		}

		else if (mapNumber == 25) {
			std::list<string> strings = {};
			strings.push_back("There were once two Pokemon.");
			strings.push_back("Created from god itself");
			strings.push_back("Beings able to control time and space");
			strings.push_back("The cultists attempted to control that power.");
			strings.push_back("And now we suffer.");
			Trainer t1 = getTrainer(62);
			t1.strings = strings;
			t1.isBattlingTrainer = false;
			t1.shouldFightWithSight = false;
			strings.pop_front();
			strings.pop_front();
			strings.pop_front();
			t1.setPositions(9, 6, 0, -1, 2);
			trainerList.push_front(t1);
		}

		return trainerList;
	}

	// Inserts all the trainers into the trainers map
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

		trainers.insert({ 41, Trainer("Lancelot", 1, 1, trainerStyleSheet, 0, 16) });
		trainers.insert({ 42, Trainer("Jenny", 1, 1, trainerStyleSheet, 3, 16) });
		trainers.insert({ 43, Trainer("Spark", 1, 1, trainerStyleSheet, 6, 16) });
		trainers.insert({ 44, Trainer("Ghost", 1, 1, trainerStyleSheet, 9, 16) });
		trainers.insert({ 45, Trainer("Liam", 1, 1, trainerStyleSheet, 12, 16) });
		trainers.insert({ 46, Trainer("Dancer", 1, 1, trainerStyleSheet, 15, 16) });
		trainers.insert({ 47, Trainer("Ghoul", 1, 1, trainerStyleSheet, 18, 16) });
		trainers.insert({ 48, Trainer("Basic Bob", 1, 1, trainerStyleSheet, 21, 16) });
		trainers.insert({ 49, Trainer("Fancy Hat Racheal", 1, 1, trainerStyleSheet, 24, 16) });
		trainers.insert({ 50, Trainer("Laxus", 1, 1, trainerStyleSheet, 27, 16) });

		trainers.insert({ 51, Trainer("Red", 1, 1, trainerStyleSheet, 0, 20) });
		trainers.insert({ 52, Trainer("Black Operative", 1, 1, trainerStyleSheet, 3, 20) });
		trainers.insert({ 53, Trainer("Bald Fighter", 1, 1, trainerStyleSheet, 6, 20) });
		trainers.insert({ 54, Trainer("Team Fate Grunt", 1, 1, trainerStyleSheet, 9, 20) });
		trainers.insert({ 55, Trainer("Team Fate Grunt", 1, 1, trainerStyleSheet, 12, 20) });
		trainers.insert({ 56, Trainer("Team Fate Arthur", 1, 1, trainerStyleSheet, 15, 20) });
		trainers.insert({ 57, Trainer("Team Fate Cyrus", 1, 1, trainerStyleSheet, 18, 20) });
		trainers.insert({ 58, Trainer("Swimmer Owen", 1, 1, trainerStyleSheet, 21, 20) });
		trainers.insert({ 59, Trainer("Clown", 1, 1, trainerStyleSheet, 24, 20) });
		trainers.insert({ 60, Trainer("Bicycle Rider", 1, 1, trainerStyleSheet, 27, 20) });

		trainers.insert({ 61, Trainer("Kimono Girl", 1, 1, trainerStyleSheet, 0, 24) });
		trainers.insert({ 62, Trainer("Liar Crossly", 1, 1, trainerStyleSheet, 3, 24) });
		trainers.insert({ 63, Trainer("Train Driver Lee", 1, 1, trainerStyleSheet, 6, 24) });
		trainers.insert({ 64, Trainer("Walker Danni", 1, 1, trainerStyleSheet, 9, 24) });
		trainers.insert({ 65, Trainer("Runner Jude", 1, 1, trainerStyleSheet, 12, 24) });
		trainers.insert({ 66, Trainer("Sam", 1, 1, trainerStyleSheet, 15, 24) });
		trainers.insert({ 67, Trainer("Brick", 1, 1, trainerStyleSheet, 18, 24) });
		trainers.insert({ 68, Trainer("James", 1, 1, trainerStyleSheet, 21, 24) });
		trainers.insert({ 69, Trainer("Pink Floyd", 1, 1, trainerStyleSheet, 24, 24) });
		trainers.insert({ 70, Trainer("Lime", 1, 1, trainerStyleSheet, 27, 24) });

		trainers.insert({ 71, Trainer("Marionette", 1, 1, trainerStyleSheet, 0, 28) });
		trainers.insert({ 72, Trainer("Postman", 1, 1, trainerStyleSheet, 3, 28) });
		trainers.insert({ 73, Trainer("Fancy Trainer", 1, 1, trainerStyleSheet, 6, 28) });
		trainers.insert({ 74, Trainer("Carer Dave", 1, 1, trainerStyleSheet, 9, 28) });
		trainers.insert({ 75, Trainer("Investigator Hoffman", 1, 1, trainerStyleSheet, 12, 28) });
		trainers.insert({ 76, Trainer("Plain Looking Man", 1, 1, trainerStyleSheet, 15, 28) });
		trainers.insert({ 77, Trainer("Roshi", 1, 1, trainerStyleSheet, 18, 28) });
		trainers.insert({ 78, Trainer("Purple Delight", 1, 1, trainerStyleSheet, 21, 28) });
		trainers.insert({ 79, Trainer("Trevor", 1, 1, trainerStyleSheet, 28, 28) });
		trainers.insert({ 80, Trainer("Guard", 1, 1, trainerStyleSheet, 27, 28) });
	}

	// Gets a trainer from the trainer number
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