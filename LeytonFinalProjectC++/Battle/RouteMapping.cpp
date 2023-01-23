#include "../Pokemon/Pokemon.h"
#include "../Pokemon/PokemonManager.h"

// Class which handles getting the pokemon on routes/ for trainers
class RouteMapping {

public:

	// Gets the pokemon from the manager and sets the level
	Pokemon getPokemon(string pokemonName, int level) {
		PokemonManager mm = mm.instance();
		Pokemon p = mm.getDefaultPokemon(pokemonName);
		p.setPokemonsLevel(level);
		return p;
	}

	// Generates a random number
	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	// Gets a single pokemon based on the route number
	Pokemon getSinglePokemonFromRoute(int routeNumber) {

		if (routeNumber == 1) {
			string availablePokemon[5] = {"Bulbasaur", "Pidgey", "Bidoof", "Charmander", "Squirtle"};
			int levelRange[2] = { 3,7 };
			int nameLoc = random(0, (sizeof(availablePokemon)/sizeof(availablePokemon[0]) - 1));
			string pokemonName = availablePokemon[nameLoc];
			int level = random(levelRange[0], levelRange[1]);
			return getPokemon(pokemonName, level);
		}

	}

	Pokemon *  getTeamOfPokemonFromRoute(int routeNumber, int numberInTeam) {

		const int numberOfTeam = random(1, 6);
		Pokemon team[6];

		for (int i = 0; i < numberOfTeam; i++)
		{
			team[i] = getSinglePokemonFromRoute(1);
		}
		return team;

	}

	Pokemon *  getTeamOfPokemonForTrainer(string trainerName) {
		Pokemon team[6];
		if (strcmp(trainerName.c_str(), "Test") == 0) {
			string availablePokemon[5] = { "Bulbasaur", "Charmander", "Squirtle" };
			team[0] = getPokemon(availablePokemon[0], 8);
			team[0] = getPokemon(availablePokemon[1], 9);
			team[0] = getPokemon(availablePokemon[2], 10);
		}
		return team;

	}

};

	