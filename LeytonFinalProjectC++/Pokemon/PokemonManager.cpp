
#include <map>
#include <string>
#include "../Pokemon/Pokemon.h"

using namespace std;

class PokemonManager
{

public:

    map<string, Pokemon> defaultPokemonStorage = {};

    Pokemon getDefaultPokemon(string _pokemonName) {

        auto getter = defaultPokemonStorage.find(_pokemonName);
        
        if (getter == defaultPokemonStorage.end()) {
            return Pokemon();
        }
        else {
            return getter->second;
        }
    }

    PokemonManager() {

        defaultPokemonStorage.insert({ "Bulbasaur", Pokemon("Charizard", 100, 110, 70, 140, 80, 100, 1, 0,0,PokemonType::PokemonTypes::Fire, PokemonType::PokemonTypes::Flying) });
    }

};
