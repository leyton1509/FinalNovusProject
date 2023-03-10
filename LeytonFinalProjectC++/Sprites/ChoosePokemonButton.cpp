#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

// A specific attack button
// Inherits from Button which inherits from Sprite
class ChoosePokemonButton : public Button {

public:

	// The pokemon attatched to this button
	Pokemon pokemon;

	// Connstructor with the pokemon to add to the players party
	ChoosePokemonButton(Pokemon& _pokemon, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		pokemon = _pokemon;
	}

	// Empty const
	ChoosePokemonButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	// Draws the button and pokemon attacthed to it
	void drawSprite(ALLEGRO_BITMAP* otherPokemonSprite) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_scaled_bitmap(otherPokemonSprite, (80 * pokemon.xPositionOnSpriteSheet), (80 * pokemon.yPositionOnSpriteSheet), 80, 80, xPosition + 7, yPosition + 5, spritewidth * 0.9, spriteHeight * 0.9, 0);
	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
	}

};