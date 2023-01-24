#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

// Class to represent the pokemon stat box
// Inherits from sprite
class PokemonStatBox : public Sprite {

public:

	// Original X Size of image
	int originalSizeX;
	// Original Y Size of image
	int originalSizeY;
	// The font to display with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 28, NULL);
	// A smaller font to display with
	ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);
	// The white health bar
	ALLEGRO_BITMAP* whiteHealthBar = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/WhiteHealthBar.png");
	// THe red health bar that changes width
	ALLEGRO_BITMAP* redHealthBar = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/RedHealthBar.png");


	// The constructor with takes the pokemon to display info for
	// and the standard size info
	PokemonStatBox(Pokemon& _pokemonToRepresent, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;

	}

	// Empty Const
	PokemonStatBox() : Sprite(SpriteType::SpriteTypes::PokemonStatBox, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png") {
		originalSizeX = 0;
		originalSizeY = 0;
	}


	// Draw sprite overrides sprite
	// Draws the back, the health bars and text
	void drawSprite(Pokemon& representedPokemon) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), (xPosition + 15), (yPosition + 5), 0, (representedPokemon.pokemonName + "   Lvl. " + std::to_string(representedPokemon.level)).c_str());
		al_draw_scaled_bitmap(whiteHealthBar, 0, 0, 128, 32, xPosition + 15, yPosition + 35, 285, 10, 0);
		al_draw_scaled_bitmap(redHealthBar, 0, 0, 128, 32, xPosition + 15, yPosition + 35, (static_cast<float>(representedPokemon.currentHealth) / static_cast<float>(representedPokemon.healthActual) * static_cast<float>(285)), 10, 0);
		al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (xPosition + 15), (yPosition + 50), 0, ("HP: " + std::to_string(representedPokemon.currentHealth) + "/" + std::to_string(representedPokemon.healthActual)).c_str());
	}

	// Destroys all the sprites 
	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
		al_destroy_font(fontSmaller);
		al_destroy_bitmap(whiteHealthBar);
	}


};