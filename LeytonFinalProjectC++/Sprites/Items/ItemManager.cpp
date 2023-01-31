#include <map>

class ItemManager {

public:

	// Maps an item id to the amount
	std::map<int, int> itemAmounts = {};

	ItemManager(){
	}
};