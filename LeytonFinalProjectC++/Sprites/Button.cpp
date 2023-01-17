#include "../Sprites/Spriteheader.h"

class Button : public Sprite {

public:

	Button(float _xStart, float _yStart, float _width, float _height, const char * _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
	}


	void drawSprite() {
		
	}

	bool hasBeenClicked(float xMousePosition, float yMousePosition) {

	}



};