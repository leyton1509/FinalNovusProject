#include <string>
class MoveCategory {

public:

	enum Categories
	{
		Physical,
		Special,
		Status
	};

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
    }

};