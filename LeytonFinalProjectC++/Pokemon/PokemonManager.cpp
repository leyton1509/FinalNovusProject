#include <map>
#include <string>
#include "../Pokemon/Pokemon.h"
#include "../Pokemon/PokemonManager.h"
#include "../Pokemon/PokemonType.h"
#include "../Pokemon/Moves/MoveCategory.h"
#include "../File/CSVFileManager.h"
using namespace std;

// Handles the loading in of pokemon from the file
// Used to get pokemon
// A singleton as it needs to load the pokemon in once
class PokemonManager
{

private:
    // Private Constructor
    PokemonManager() {
        // Reads the csv file info for pokemon and moves
        CSVFileManager csvm = CSVFileManager();
        //std::vector<std::vector<std::string> > pokemonList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/Pokemon.csv");
        //std::vector<std::vector<std::string> > pokemonMoveList = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonLevelUpMoveSetsOut.csv");
        std::vector<std::vector<std::string> > pokemonList = csvm.parseCSV("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/CSVs/Pokemon.csv");
        std::vector<std::vector<std::string> > pokemonMoveList = csvm.parseCSV("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/CSVs/PokemonLevelUpMoveSetsOut.csv");
        // Declares the pokemon type and move category for conversions between string and enum
        PokemonType pt = PokemonType();
        MoveCategory mc = MoveCategory();

        // The current index in the move file
        int currentPlaceInMoveListFile = 0;
        // The max number of pokemon in the file
        int numberOfPokemon = pokemonList.size();
        // The max number of moves in the file
        int numberOfMoves = pokemonMoveList.size();
        // The loop number
        int loopPokemon = 0;

        for (int i = 0; i < pokemonList.size(); i++) {

            // The id of the pokemon from file
            int pokemonID = std::stoi(pokemonList.at(i)[0]);
            // The name of the pokemon from file
            string pokemonName = pokemonList.at(i)[1];
            // The type of the pokemon from file
            PokemonType::PokemonTypes typeOne = pt.getEnumFromStringMove(pokemonList.at(i)[2]);
            // The type 2 of the pokemon from file
            PokemonType::PokemonTypes typeTwo = pt.getEnumFromStringMove(pokemonList.at(i)[3]);
            // The health stat of the pokemon from file
            int healthStat = std::stoi(pokemonList.at(i)[4]);
            // The attack stat of the pokemon from file
            int attackStat = std::stoi(pokemonList.at(i)[5]);
            // The defence stat of the pokemon from file
            int defenceStat = std::stoi(pokemonList.at(i)[6]);
            // The special attack stat of the pokemon from file
            int specialAttackStat = std::stoi(pokemonList.at(i)[7]);
            // The special defence stat of the pokemon from file
            int specialDefenceStat = std::stoi(pokemonList.at(i)[8]);
            // The speed stat of the pokemon from file
            int speedStat = std::stoi(pokemonList.at(i)[9]);
            // The x position of the sprite of the pokemon from file
            int xTilePosition = std::stoi(pokemonList.at(i)[11]);
            // The y position of the sprite of the pokemon from file
            int yTilePosition = std::stoi(pokemonList.at(i)[12]);
            // The level the pokemon evolves at
            int evolutionLevel = std::stoi(pokemonList.at(i)[13]);
            // The string of the name it evolves into
            string evolutionName = pokemonList.at(i)[14];

            // Creates a mapping between a move and its level learned
            map<int, int >levelUpMoveSet = {};

            // Creates a boolean for if the move is for this pokemon
            bool moveNextIsForThisPokemon = true;

            MoveManager mm = mm.instance();

            // Creates a loop for if the moves are for this pokemon
            while (moveNextIsForThisPokemon) {
                // If its not the last pokemon+1
                if (loopPokemon != numberOfPokemon) {
                    // If the current place in file is less then the file length of moves
                    if (currentPlaceInMoveListFile < numberOfMoves) {
                        // Gets the id of the pokemon belonging to that move
                        int pokemonIDForMove = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[0]);
                        // If the id matches this pokemon
                        if (pokemonIDForMove == pokemonID) {
                            // Get the level and move and insert it into the map
                            int levelOfMove = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[3]);
                            int moveID = std::stoi(pokemonMoveList.at(currentPlaceInMoveListFile)[1]);

                            // Removes status moves, remove if to insert them again
                            if (mm.getMoveDetails(moveID).typeOfMove != mc.Status) {
                                // Checks to see if the move is already in the list
                                bool addMove = true;
                                for (const pair<int, int>& p : levelUpMoveSet) {
                                    if (p.first == moveID) {
                                        addMove = false;
                                    }
                                    
                                }
                                if (addMove) { levelUpMoveSet.insert({ moveID, levelOfMove }); }
                                
                            }
                            
                            // Update the current place in file
                            currentPlaceInMoveListFile++;
                        }
                        // otherwise exit loop
                        else {
                            moveNextIsForThisPokemon = false;
                        }
                    }
                    // otherwise exit loop
                    else {
                        moveNextIsForThisPokemon = false;
                    }

                }
                // otherwise exit loop
                else {
                    moveNextIsForThisPokemon = false;
                }

            }
            // Increase loop count
            loopPokemon++;

            // Insert the pokemon into storage
            defaultPokemonStorage.insert({ pokemonName, Pokemon(pokemonName, healthStat, attackStat, defenceStat, specialAttackStat, specialDefenceStat, speedStat, 1, xTilePosition,yTilePosition,typeOne, typeTwo, levelUpMoveSet, evolutionLevel, evolutionName) });
        }
    }


public:
    
    // Gets the instance of the class
    static PokemonManager& instance()
    {
        static PokemonManager INSTANCE;
        return INSTANCE;
    }

    // A mapping between the name of pokemon and the pokemon
    map<string, Pokemon> defaultPokemonStorage = {};

    // Returns the pokemon from the pokemon name
    Pokemon getDefaultPokemon(string _pokemonName) {

        auto getter = defaultPokemonStorage.find(_pokemonName);
        
        if (getter == defaultPokemonStorage.end()) {
            return Pokemon();
        }
        else {
            Pokemon returnedPokemon = getter->second;


            // SEE IF THIS IS NECCASRY
            // The reason for doing this is that each pokemon returned needs to be a unique object
            // This storage is just for holding all pokemon in the game ready to be returned

            Pokemon newPokemon = Pokemon(returnedPokemon.pokemonName, returnedPokemon.healthBase, 
                returnedPokemon.physcialAttackBase, returnedPokemon.physicalDefenceBase, 
                returnedPokemon.specialAttackBase, returnedPokemon.specialDefenceBase, 
                returnedPokemon.speedBase,1, returnedPokemon.xPositionOnSpriteSheet, 
                returnedPokemon.yPositionOnSpriteSheet, returnedPokemon.pokemonTypeOne, 
                returnedPokemon.pokemonTypeTwo, returnedPokemon.levelUpMoveSet, returnedPokemon.evolutionLevel, returnedPokemon.evolutionName);

            return newPokemon;
        }
    }
};
