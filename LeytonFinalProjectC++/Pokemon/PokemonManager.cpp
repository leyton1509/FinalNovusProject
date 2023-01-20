
#include <map>
#include <string>
#include "../Pokemon/Pokemon.h"
#include "../Pokemon/PokemonManager.h"
#include "../Pokemon/PokemonType.h";
#include "../Pokemon/Moves/MoveCategory.h";
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

        //std::vector<std::vector<std::string> > pokemonMoveList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonLevelUpMoveSets.csv");
        PokemonType pt = PokemonType();
        MoveCategory mc = MoveCategory();

        int currentPlaceInMoveListFile = 0;

        for (int i = 0; i < pokemonList.size(); i++) {

            int pokemonID = std::stoi(pokemonList.at(i)[0]);
            string pokemonName = pokemonList.at(i)[1];
            PokemonType::PokemonTypes typeOne = pt.getEnumFromStringMove(pokemonList.at(i)[2]);
            PokemonType::PokemonTypes type = pt.getEnumFromStringMove(pokemonList.at(i)[3]);
            int healthStat = std::stoi(pokemonList.at(i)[4]);
            int attackStat = std::stoi(pokemonList.at(i)[5]);
            int defenceStat = std::stoi(pokemonList.at(i)[6]);
            int specialAttackStat = std::stoi(pokemonList.at(i)[7]);
            int specialDefenceStat = std::stoi(pokemonList.at(i)[8]);
            int speedStat = std::stoi(pokemonList.at(i)[9]);
            int xTilePosition = std::stoi(pokemonList.at(i)[11]);
            int yTilePosition = std::stoi(pokemonList.at(i)[12]);
            cout << pokemonName << " "  << healthStat << " "  << attackStat << " " << defenceStat <<  " "  << specialAttackStat << " " << specialDefenceStat << " " << speedStat << " " << xTilePosition << " " << yTilePosition << " \n";
        }


        //map<int, int >levelUpMoveSet = { {1,1}, {2,7} };
       // defaultPokemonStorage.insert({ "Bulbasaur", Pokemon("Charizard", 100, 110, 70, 140, 80, 100, 1, 0,0,PokemonType::PokemonTypes::Fire, PokemonType::PokemonTypes::Flying, levelUpMoveSet) });
    }

};
