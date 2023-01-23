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

	Pokemon getSinglePokemonFromRoute(int routeNumber) {

	}

	Pokemon *  getTeanmOfPokemonFromRoute(int routeNumber) {

	}

	Pokemon *  getTeamOfPokemonForTrainer(string trainerName) {

	}

};

	