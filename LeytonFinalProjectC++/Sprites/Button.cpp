#include "../Sprites/Spriteheader.h"

class Button : public Sprite {

public:

	int originalSizeX;
	int originalSizeY;

	Button(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char * _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
	}

	Button() : Sprite(SpriteType::SpriteTypes::Button, 0,0,0,0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
	}

	bool hasBeenClicked(double xMousePosition, double yMousePosition){
		
		if (xMousePosition > xPosition && xMousePosition < xPosition + spritewidth && yMousePosition > yPosition && yMousePosition <  yPosition + spriteHeight) {
			return true;
		}
		return false;
	}



};