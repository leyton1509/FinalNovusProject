
#include <map>
#include "Move.h"
#include "../../File/CSVFileManager.h";

using namespace std;


class MoveManager
{

public:

    map<int, Move> moveStorage = {};

    Move getMoveDetails(int moveID) {

        auto getter = moveStorage.find(moveID);

        if (getter == moveStorage.end()) {
            return Move();
        }
        else {
            return getter->second;
        }
    }

    PokemonType::PokemonTypes getEnumFromStringMove(string typeString) {
        if (typeString.compare("Normal") == 0) {

        }
        else if (typeString.compare("Fire") == 0) {
            return PokemonType::PokemonTypes::Fire;
        }
        else if (typeString.compare("Water") == 0) {
            return PokemonType::PokemonTypes::Water;
        }
        else if (typeString.compare("Grass") == 0) {
            return PokemonType::PokemonTypes::Grass;
        }
        else if (typeString.compare("Electric") == 0) {
            return PokemonType::PokemonTypes::Electric;
        }
        else if (typeString.compare("Ice") == 0) {
            return PokemonType::PokemonTypes::Ice;
        }
        else if (typeString.compare("Poison") == 0) {
            return PokemonType::PokemonTypes::Poison;
        }
        else if (typeString.compare("Ground") == 0) {
            return PokemonType::PokemonTypes::Ground;
        }
        else if (typeString.compare("Flying") == 0) {
            return PokemonType::PokemonTypes::Flying;
        }
        else if (typeString.compare("Psychic") == 0) {
            return PokemonType::PokemonTypes::Psychic;
        }
        else if (typeString.compare("Bug") == 0) {
            return PokemonType::PokemonTypes::Bug;
        }
        else if (typeString.compare("Rock") == 0) {
            return PokemonType::PokemonTypes::Rock;
        }
        else if (typeString.compare("Ghost") == 0) {
            return PokemonType::PokemonTypes::Ghost;
        }
        else if (typeString.compare("Dark") == 0) {
            return PokemonType::PokemonTypes::Dark;
        }
        else if (typeString.compare("Dragon") == 0) {
            return PokemonType::PokemonTypes::Dragon;
        }
        else if (typeString.compare("Steel") == 0) {
            return PokemonType::PokemonTypes::Steel;
        }
        else if (typeString.compare("Fairy") == 0) {
            return PokemonType::PokemonTypes::Fairy;
        }
        else {
            return PokemonType::PokemonTypes::None;
        }
    }

    MoveCategory::Categories getEnumFromStringCategory(string moveString) {
        if (moveString.compare("Physical") == 0) {
            return MoveCategory::Categories::Physical;
        }
        else if (moveString.compare("Special") == 0) {
            return MoveCategory::Categories::Special;
        }
        else if (moveString.compare("Status") == 0) {
            return MoveCategory::Categories::Status;
        }
    }

    MoveManager() {

        CSVFileManager csvm = CSVFileManager();

        std::vector<std::vector<std::string> > cs = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonMoves.csv");
        
        for (int i = 0; i < cs.size(); i++) {

            int moveID = std::stoi(cs.at(i)[0]);
            const char* moveName = cs.at(i)[1].c_str();
            PokemonType::PokemonTypes type = getEnumFromStringMove(cs.at(i)[2]);
            MoveCategory::Categories moveC = getEnumFromStringCategory(cs.at(i)[3]);
            int powerpoints = std::stoi(cs.at(i)[4]);
            int power = std::stoi(cs.at(i)[5]);
            int accuracy = std::stoi(cs.at(i)[6]);
            int hasSpecialEffect = std::stoi(cs.at(i)[7]);
           // cout << moveID << " | " << moveName << " | " << type << " | " << moveC << " | " << powerpoints << " | " << power << " | " << accuracy << " | " <<  "\n";
            moveStorage.insert({ moveID, Move(moveID,	moveName, type ,moveC,	powerpoints,	power, accuracy, hasSpecialEffect) });
        }

        //cout << "\n----";
    }

};
