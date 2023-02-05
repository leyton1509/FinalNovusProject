#include <string>

// Class for representing the types of moves
class MoveCategory {

public:

    // A move is either phsycial, special or a status move
	enum Categories
	{
		Physical,
		Special,
		Status
	};

    // Returns the enum of the string version of the move
    MoveCategory::Categories getEnumFromStringCategory(std::string moveString) {
        if (moveString.compare("Physical") == 0) {
            return MoveCategory::Categories::Physical;
        }
        else if (moveString.compare("Special") == 0) {
            return MoveCategory::Categories::Special;
        }
        else if (moveString.compare("Status") == 0) {
            return MoveCategory::Categories::Status;
        }
        else {
            return MoveCategory::Categories::Status;
        }
    }

};