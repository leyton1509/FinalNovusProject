#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

// A specific attack button
// Inherits from Button which inherits from Sprite
class ItemPokeBallButton : public Button {

public:

	// The font to draw with
	ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

	// ItemPokeBallButton with the pokemon to add to the players party
	ItemPokeBallButton(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png") {

	}

	// Empty const
	ItemPokeBallButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	// Draws the button and pokemon attacthed to it
	void drawSprite(Pokemon& pokemon) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		


	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(fontSmaller);
	}






};