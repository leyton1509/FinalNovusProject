
#include <map>
#include "Move.h"
#include "../../File/CSVFileManager.h"
#include "../../Pokemon/PokemonType.h"
#include "../../Pokemon/Moves/MoveCategory.h"
using namespace std;

// Class to handle all the moves in the game
// Is a singleton as once created it holds all moves
class MoveManager
{

private:
    MoveManager() {
        // Uses the csv reader to read a csv file of all moves in the game
        CSVFileManager csvm = CSVFileManager();
        // Uses type and pokemon type for the move
        PokemonType pt = PokemonType();
        MoveCategory mc = MoveCategory();

        // Filepath
         std::vector<std::vector<std::string> > cs = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonMoves.csv");
        //std::vector<std::vector<std::string> > cs = csvm.parseCSV("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/CSVs/PokemonMoves.csv");

         // Loops through the file
         // Gets all the move info and inserts it into the map
        for (int i = 0; i < cs.size(); i++) {
            int moveID = std::stoi(cs.at(i)[0]);
            string moveName = cs.at(i)[1];
            PokemonType::PokemonTypes type = pt.getEnumFromStringType(cs.at(i)[2]);
            MoveCategory::Categories moveC = mc.getEnumFromStringCategory(cs.at(i)[3]);
            int powerpoints = std::stoi(cs.at(i)[4]);
            int power = std::stoi(cs.at(i)[5]);
            int accuracy = std::stoi(cs.at(i)[6]);
            int hasSpecialEffect = std::stoi(cs.at(i)[7]);
            // cout << moveID << " | " << moveName << " | " << type << " | " << moveC << " | " << powerpoints << " | " << power << " | " << accuracy << " | " <<  "\n";
            moveStorage.insert({ moveID, Move(moveID,	moveName, type ,moveC,	powerpoints,	power, accuracy, hasSpecialEffect) });
        }

        //cout << "\n----";
    }

public:

    // The instance of the class
    static MoveManager& instance()
    {
        static MoveManager INSTANCE;
        return INSTANCE;
    }

    // The storage for the moves
    map<int, Move> moveStorage = {};

    // Gets a move from its ID
    Move getMoveDetails(int moveID) {

        auto getter = moveStorage.find(moveID);

        if (getter == moveStorage.end()) {
            return Move();
        }
        else {
            return getter->second;
        }
    }


};
