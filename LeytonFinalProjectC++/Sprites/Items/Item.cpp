#include "../../Sprites/SpriteHeader.h"

class Item : public Sprite  {
public:

	int idOfItem;
	int xTile;
	int yTile;


	Item(int _idOfItem, int _xStart, int _yStart, int _xTile, int _yTile) : Sprite(SpriteType::SpriteTypes::Item, _xStart, _yStart, 32, 32, "../../Sprites/Items/Items.png") {
		idOfItem = _idOfItem;
		xTile = _xTile;
		yTile = _yTile;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, (32 * xTile), (32 * yTile), 32, 32, xPosition,yPosition, spritewidth, spriteHeight, 0);

	}

	void useItem() {

	}

};