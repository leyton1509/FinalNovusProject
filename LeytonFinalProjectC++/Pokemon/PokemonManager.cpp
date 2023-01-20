
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

private:
    PokemonManager() {
        CSVFileManager csvm = CSVFileManager();
        std::vector<std::vector<std::string> > pokemonList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/Pokemon.csv");

        std::vector<std::vector<std::string> > pokemonMoveList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonLevelUpMoveSetsOut.csv");
        PokemonType pt = PokemonType();
        MoveCategory mc = MoveCategory();

        int currentPlaceInMoveListFile = 0;
        int numberOfPokemon = pokemonList.size();
        int numberOfMoves = pokemonMoveList.size();
        int loopPokemon = 0;

        for (int i = 0; i < pokemonList.size(); i++) {

            int pokemonID = std::stoi(pokemonList.at(i)[0]);
            string pokemonName = pokemonList.at(i)[1];
            PokemonType::PokemonTypes typeOne = pt.getEnumFromStringMove(pokemonList.at(i)[2]);
            PokemonType::PokemonTypes typeTwo = pt.getEnumFromStringMove(pokemonList.at(i)[3]);
            int healthStat = std::stoi(pokemonList.at(i)[4]);
            int attackStat = std::stoi(pokemonList.at(i)[5]);
            int defenceStat = std::stoi(pokemonList.at(i)[6]);
            int specialAttackStat = std::stoi(pokemonList.at(i)[7]);
            int specialDefenceStat = std::stoi(pokemonList.at(i)[8]);
            int speedStat = std::stoi(pokemonList.at(i)[9]);
            int xTilePosition = std::stoi(pokemonList.at(i)[11]);
            int yTilePosition = std::stoi(pokemonList.at(i)[12]);
            // cout << pokemonName << " "  << healthStat << " "  << attackStat << " " << defenceStat <<  " "  << specialAttackStat << " " << specialDefenceStat << " " << speedStat << " " << xTilePosition << " " << yTilePosition << " \n";

            map<int, int >levelUpMoveSet = {};

            bool moveNextIsForThisPokemon = true;

            while (moveNextIsForThisPokemon) {
                if (loopPokemon != numberOfPokemon) {
                    if (currentPlaceInMoveListFile < numberOfMoves) {
                        int pokemonIDForMove = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[0]);
                        if (pokemonIDForMove == pokemonID) {
                            int levelOfMove = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[3]);
                            int moveID = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[1]);
                            levelUpMoveSet.insert({ moveID, levelOfMove });
                            currentPlaceInMoveListFile++;
                        }
                        else {
                            moveNextIsForThisPokemon = false;
                        }
                    }
                    else {
                        moveNextIsForThisPokemon = false;
                    }

                }
                else {
                    moveNextIsForThisPokemon = false;
                }

            }
            loopPokemon++;

            /*
            cout << "Beinning move set for : " << pokemonName << " \n";

            for (const pair<int, int>& p : levelUpMoveSet) {
                std::cout << p.first << " " << p.second << std::endl << "\n";
           }

           cout << "Finished move set for : " << pokemonName << " \n";
            */
            

            defaultPokemonStorage.insert({ pokemonName, Pokemon(pokemonName, healthStat, attackStat, defenceStat, specialAttackStat, specialDefenceStat, speedStat, 1, xTilePosition,yTilePosition,typeOne, typeTwo, levelUpMoveSet) });
        }
    }


public:
    
    static PokemonManager& instance()
    {
        static PokemonManager INSTANCE;
        return INSTANCE;
    }

    map<string, Pokemon> defaultPokemonStorage = {};

    Pokemon getDefaultPokemon(string _pokemonName) {

        auto getter = defaultPokemonStorage.find(_pokemonName);
        
        if (getter == defaultPokemonStorage.end()) {
            return Pokemon();
        }
        else {
            Pokemon returnedPokemon = getter->second;

            // The reason for doing this is that each pokemon returned needs to be a unique object
            // This storage is just for holding all pokemon in the game ready to be returned

            Pokemon newPokemon = Pokemon(returnedPokemon.pokemonName, returnedPokemon.healthBase, 
                returnedPokemon.physcialAttackBase, returnedPokemon.physicalDefenceBase, 
                returnedPokemon.specialAttackBase, returnedPokemon.specialDefenceBase, 
                returnedPokemon.speedBase,1, returnedPokemon.xPositionOnSpriteSheet, 
                returnedPokemon.yPositionOnSpriteSheet, returnedPokemon.pokemonTypeOne, 
                returnedPokemon.pokemonTypeTwo, returnedPokemon.levelUpMoveSet);

            return newPokemon;
        }
    }
};
