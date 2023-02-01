#include "../Sprites/Spriteheader.h"


class Trainer : public Sprite{
public:

	// Name of the trainer
	const char* name;
	// X tile for on the map
	int xTile;
	// Y tile for on the map
	int yTile;
	// X tile for the style sheet position
	int xTileForSpriteSheet;
	// Y tile for the style sheet position
	int yTileForSpriteSheet;

	// Main constructor for loading a character 
	Trainer(const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet, int _xTileForSpriteSheet, int _yTileForSpriteSheet) : Sprite(SpriteType::SpriteTypes::Player, _xTile * 32, _yTile * 32,0,0, 0,0, 32,32, stylesheet) {
		name = _name;
		xTile = _xTile;
		yTile = _yTile;
		xTileForSpriteSheet = _xTileForSpriteSheet;
		yTileForSpriteSheet = _yTileForSpriteSheet;

	}

	// Draws the current sprite
	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, (32 * xTileForSpriteSheet), (32 * yTileForSpriteSheet), 32, 32, xPosition, yPosition, spritewidth, spriteHeight, 0);
	}

	
};