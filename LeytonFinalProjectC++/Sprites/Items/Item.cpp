#include "../../Sprites/SpriteHeader.h"

// Class which represents an item the player can have
// Extends sprite
class Item : public Sprite  {
public:
	// The id of the item
	int idOfItem;
	// The xtile of the stylesheet
	int xTileForSpriteSheet;
	// The ytile of the stylesheet
	int yTileForSpriteSheet;

	// Constructor for item, takes the id and position as well as the style sheet position
	Item(int _idOfItem, int _xStart, int _yStart, int _xTile, int _yTile) : Sprite(SpriteType::SpriteTypes::Item, _xStart, _yStart, 64, 64, "../LeytonFinalProjectC++/Sprites/Items/Items.png") {
		idOfItem = _idOfItem;
		xTileForSpriteSheet = _xTile;
		yTileForSpriteSheet = _yTile;
	}

	// Draws the item
	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, (64 * xTileForSpriteSheet), (64 * yTileForSpriteSheet), 64, 64, xPosition+20,yPosition+15, spritewidth /2, spriteHeight/2, 0);

	}

	// Method for use item to be overridden
	void useItem() {

	}

};