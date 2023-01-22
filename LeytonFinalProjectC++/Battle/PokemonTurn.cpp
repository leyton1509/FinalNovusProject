#include "../Pokemon/Pokemon.h"
class PokemonTurn {
	
public:

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon, Move& playerMoveUsed) 
	{
		cout << "Decreasing " << otherPokemon.pokemonName << " health from " << otherPokemon.currentHealth << " to " << (otherPokemon.currentHealth - 5)<< "\n";
		otherPokemon.decreasePokemonHealth(5); 
	}

	PokemonTurn(Pokemon& playersPokemon, Pokemon& otherPokemon) {

	}

};

	

