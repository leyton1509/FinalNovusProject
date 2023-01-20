
#include <map>
#include "Move.h"
#include "../../File/CSVFileManager.h";
#include "../../Pokemon/PokemonType.h";
#include "../../Pokemon/Moves/MoveCategory.h";
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

   

    MoveManager() {

        CSVFileManager csvm = CSVFileManager();
        PokemonType pt = PokemonType();
        MoveCategory mc = MoveCategory();

        std::vector<std::vector<std::string> > cs = csvm.parseCSV("C:/Users/leyto/source/repos/LeytonFinalProjectC++/LeytonFinalProjectC++/CSVs/PokemonMoves.csv");
        
        for (int i = 0; i < cs.size(); i++) {

            

            int moveID = std::stoi(cs.at(i)[0]);
            string moveName = cs.at(i)[1];
            PokemonType::PokemonTypes type = pt.getEnumFromStringMove(cs.at(i)[2]);
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

};
