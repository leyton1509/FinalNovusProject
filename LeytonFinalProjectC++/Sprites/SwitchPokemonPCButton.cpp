#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

// A button for displaying a pokemon in the pc
// Inherits from Button which inherits from Sprite
class SwitchPokemonPCButton : public Button {

public:

	// The pointer to the other pokemon sprite sheet
	ALLEGRO_BITMAP* otherPokemonSprite;
	// Loads the highlighetd pokemon image
	ALLEGRO_BITMAP* highlightedImage = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/HighlightedPokemon.png");
	// Whether or not the pokemon has been selected
	bool isHighlighted;


	// Connstructor with the pokemon to add to the players party
	SwitchPokemonPCButton(ALLEGRO_BITMAP* _otherPokemonSprite, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, "../LeytonFinalProjectC++/Sprites/PCSprites/ChoosePokemon.png") {
		otherPokemonSprite = _otherPokemonSprite;
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		isHighlighted = false;
	}

	// Empty const
	SwitchPokemonPCButton() : Button() {
		otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PCSprites/ChoosePokemon.png");
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
		
		if (!(strcmp(pokemon.pokemonName.c_str(), "") == 0)) {
			al_draw_scaled_bitmap(otherPokemonSprite, (80 * pokemon.xPositionOnSpriteSheet), (80 * pokemon.yPositionOnSpriteSheet), 80, 80, xPosition + 4, yPosition - 2, spritewidth * 0.9, spriteHeight * 0.9, 0);

		}
	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
		al_destroy_bitmap(otherPokemonSprite);
	}






};