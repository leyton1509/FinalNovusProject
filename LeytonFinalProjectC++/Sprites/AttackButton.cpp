#include "../Sprites/Button.h"
#include "../Pokemon/Moves/Move.h"
#include <allegro5/allegro_font.h>

class AttackButton : public Button {

public:

	ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);
	int originalSizeX;
	int originalSizeY;
	Move pokemonMove;

	AttackButton(Move _move, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Button( _originalSizeX,  _originalSizeY,  _xStart,  _yStart,  _width,  _height,  _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		pokemonMove = _move;
	}

	AttackButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
	}




};