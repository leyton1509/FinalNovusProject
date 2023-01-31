#include "../../Sprites/SpriteHeader.h"

class Item : Sprite  {
public:

	int idOfItem;



	Item(int _idOfItem, int _xStart, int _yStart) : Sprite(SpriteType::SpriteTypes::Item, _xStart, _yStart, 32, 32, "../../Sprites/Items/Items.png") {
		idOfItem = _idOfItem;
	}

	void useItem() {

	}

};