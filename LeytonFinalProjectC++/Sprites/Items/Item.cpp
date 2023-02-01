#include "../../Sprites/SpriteHeader.h"

class Item : public Sprite  {
public:

	int idOfItem;
	int xTileForSpriteSheet;
	int yTileForSpriteSheet;


	Item(int _idOfItem, int _xStart, int _yStart, int _xTile, int _yTile) : Sprite(SpriteType::SpriteTypes::Item, _xStart, _yStart, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png") {
		idOfItem = _idOfItem;
		xTileForSpriteSheet = _xTile;
		yTileForSpriteSheet = _yTile;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, (32 * xTileForSpriteSheet), (32 * yTileForSpriteSheet), 32, 32, xPosition+20,yPosition+15, spritewidth /2, spriteHeight/2, 0);

	}

	void useItem() {

	}

};