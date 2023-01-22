#include "../Sprites/Spriteheader.h"
class PokemonStatBox : public Sprite {

public:

	int originalSizeX;
	int originalSizeY;

	PokemonStatBox(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
	}

	PokemonStatBox() : Sprite(SpriteType::SpriteTypes::PokemonStatBox, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png") {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
	}


};