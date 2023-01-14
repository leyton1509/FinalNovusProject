#include "Sprite.cpp"


class PokemonGrass : public Sprite {

public:

	PokemonGrass(float _startXPosition, float _startYPosition) : Sprite(SpriteType::SpriteTypes::Grass, _startXPosition, _startYPosition, 32, 32, "Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png") {
	}


	void drawSprite() {
		al_draw_bitmap(spriteImage, xPosition, yPosition, 0);
	}



};