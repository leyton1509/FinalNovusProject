#include "../Sprites/Spriteheader.h"

// Class to represent pokemon grass
// May not be needed yet
// Inherits sprite info
class PokemonGrass : public Sprite {

public:

	// Constructor to place the sprite at
	PokemonGrass(float _startXPosition, float _startYPosition) : Sprite(SpriteType::SpriteTypes::Grass, _startXPosition, _startYPosition, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png") {
	}

	// Empty Const
	PokemonGrass() : Sprite(SpriteType::SpriteTypes::Grass, 0, 0, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png") {
	}

	// Draws the sprite at x and y
	void drawSprite() {
		al_draw_bitmap(spriteImage, xPosition, yPosition, 0);
	}

};