#include "../Sprites/Spriteheader.h"

class PokemonGrass : public Sprite {

public:

	PokemonGrass(float _startXPosition, float _startYPosition) : Sprite(SpriteType::SpriteTypes::Grass, _startXPosition, _startYPosition, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png") {
	}

	PokemonGrass() : Sprite(SpriteType::SpriteTypes::Grass, 0, 0, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png") {
	}


	void drawSprite() {
		al_draw_bitmap(spriteImage, xPosition, yPosition, 0);
	}



};