#include "../Sprites/Interactable.h"

class Breifcase : public Interactable {

public:

	Breifcase(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Interactable(true, _originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
	}

	void interact() {

	}
};