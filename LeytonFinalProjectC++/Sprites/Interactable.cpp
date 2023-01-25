#include "../Sprites/Spriteheader.h"


class Interactable : public Sprite {

public:

	// The original x size of image
	int originalSizeX;
	// The original y size of image
	int originalSizeY;
	// Whether or not the interactable should be on screen or not
	bool isDisplayed = true;
	// Boolean for if the object has been interacted with
	bool alreadyInteractedWith = false;
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

	bool isInteracting(const char* keyPressed, int xTile, int yTile, int directionX, int directionY, int mapSizeX, int mapSizeY) {
		int tempYTile = yTile + 1;
		if (strcmp(keyPressed, "w") == 0) {
			if (directionY == 1) {
				if (tempYTile - 1 >= 0) {
					if (xTile == xPosition && ((tempYTile - 1) == yPosition)) {
						return 1;
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		} 

		else if (strcmp(keyPressed, "s") == 0) {
			if (directionY == -1) {
				if (tempYTile + 1 < mapSizeY) {
					if (xTile == xPosition && ((tempYTile + 1) == yPosition)) {
						return 1;
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}

		else if (strcmp(keyPressed, "a") == 0) {
			if (directionX == -1) {
				if (xTile - 1 >= 0) {
					if ((xTile -1) == xPosition && ((tempYTile) == yPosition)) {
						return 1;
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}

		else if (strcmp(keyPressed, "d") == 0) {
			if (directionX == 1) {
				if (xTile + 1 < mapSizeX) {
					if ((xTile + 1) == xPosition && ((tempYTile) == yPosition)) {
						return 1;
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}





		return 0;
	}

};
