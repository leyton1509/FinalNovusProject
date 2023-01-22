#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

class PokemonStatBox : public Sprite {

public:

	Pokemon representedPokemon;
	int originalSizeX;
	int originalSizeY;
	ALLEGRO_FONT* font = al_create_builtin_font();

	PokemonStatBox(Pokemon _pokemonToRepresent, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		representedPokemon = _pokemonToRepresent;
	}

	PokemonStatBox() : Sprite(SpriteType::SpriteTypes::PokemonStatBox, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png") {
		originalSizeX = 0;
		originalSizeY = 0;
		representedPokemon = Pokemon();
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, representedPokemon.pokemonName.c_str());
	}


};