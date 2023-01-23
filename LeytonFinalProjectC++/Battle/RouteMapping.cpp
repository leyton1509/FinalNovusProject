#include "../Pokemon/Pokemon.h"
#include "../Pokemon/PokemonManager.h"
class RouteMapping {

public:

	Pokemon getPokemon(string pokemonName, int level) {
		PokemonManager mm = mm.instance();
		Pokemon p = mm.getDefaultPokemon(pokemonName);
		p.setPokemonsLevel(level);
		return p;
	}

	int random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	Pokemon getSinglePokemonFromRoute(int routeNumber) {

		if (routeNumber == 1) {
			string availablePokemon[5] = {"Bulbasaur", "Pidgey", "Bidoof", "Charmander", "Squirtle"};
			int levelRange[2] = { 3,7 };

		}

	}

	Pokemon *  getTeamOfPokemonFromRoute(int routeNumber) {

	}

	Pokemon *  getTeamOfPokemonForTrainer(string trainerName) {

	}

};

	