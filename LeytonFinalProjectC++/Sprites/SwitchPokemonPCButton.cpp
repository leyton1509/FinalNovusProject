#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

// A specific attack button
// Inherits from Button which inherits from Sprite
class SwitchPokemonPCButton : public Button {

public:

	ALLEGRO_BITMAP* otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
	ALLEGRO_BITMAP* highlightedImage = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/HighlightedPokemon.png");

	// The original x size of button image
	int originalSizeX;
	// The original y size of button image
	int originalSizeY;

	bool isHighlighted;


	// Connstructor with the pokemon to add to the players party
	SwitchPokemonPCButton(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, "../LeytonFinalProjectC++/Sprites/PCSprites/ChoosePokemon.png") {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		isHighlighted = false;
	}

	// Empty const
	SwitchPokemonPCButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
		isHighlighted = false;
	}

	// Draws the button and pokemon attacthed to it
	void drawSprite(Pokemon& pokemon) {
		if (isHighlighted) {
			al_draw_scaled_bitmap(highlightedImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		}
		else {
			al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		}
		
		al_draw_scaled_bitmap(otherPokemonSprite, (80 * pokemon.xPositionOnSpriteSheet), (80 * pokemon.yPositionOnSpriteSheet), 80, 80, xPosition + 4, yPosition - 2, spritewidth * 0.9, spriteHeight * 0.9, 0);
	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
		al_destroy_bitmap(otherPokemonSprite);
	}






};