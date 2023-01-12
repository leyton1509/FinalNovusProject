
#include <map>
#include <string>
#include "Pokemon/Pokemon.cpp"

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
        defaultPokemonStorage.insert({ "Charizard", Pokemon("Charizard", 100, 110, 70, 140, 80, 100, 1)});
        defaultPokemonStorage.insert({ "Blastoise", Pokemon("Blastoise", 120, 70, 100, 120, 120, 70, 1)});
        defaultPokemonStorage.insert({ "Venasaur", Pokemon("Venasaur", 140, 50, 90, 100, 110, 60, 1) });
    }

};
