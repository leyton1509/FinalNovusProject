
#include <map>
#include <string>
#include "../Pokemon/Pokemon.h"
#include "../Pokemon/PokemonManager.h"
#include "../File/CSVFileManager.h";


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
        
        CSVFileManager csvm = CSVFileManager();
        std::vector<std::vector<std::string> > pokemonList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/Pokemon.csv");

        std::vector<std::vector<std::string> > pokemonMoveList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonLevelUpMoveSets.csv");

        int currentPlaceInMoveListFile = 0;

        for (int i = 0; i < pokemonList.size(); i++) {

            int pokemonID = std::stoi(pokemonList.at(i)[0]);
            string pokemonName = pokemonList.at(i)[1];
        }


        map<int, int >levelUpMoveSet = { {1,1}, {2,7} };
        defaultPokemonStorage.insert({ "Bulbasaur", Pokemon("Charizard", 100, 110, 70, 140, 80, 100, 1, 0,0,PokemonType::PokemonTypes::Fire, PokemonType::PokemonTypes::Flying, levelUpMoveSet) });
    }

};
