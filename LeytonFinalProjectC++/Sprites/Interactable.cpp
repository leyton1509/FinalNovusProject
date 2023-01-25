#include "../Sprites/Spriteheader.h"


class Interactable : public Sprite {

public:

	// The original x size of image
	int originalSizeX;
	// The original y size of image
	int originalSizeY;
	// Whether or not the interactable should be on screen or not
	bool isDisplayed = true;

	// Constructor with the size and position parameters
	Interactable(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
	}

	// Draws the sprite at the correct position if it is displayed
	void drawSprite() {
		if (isDisplayed) {
			al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		}
	}

	bool hasBeenInteractedWith(const char* keyPressed, int xTilePosition, int yTilePosition, int xDirection, int yDirection) {

	}

};
