#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
class PokemonStatBox : public Sprite {

public:

	Pokemon representedPokemon;
	int originalSizeX;
	int originalSizeY;
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 28, NULL);
	float x;
	float y;

	PokemonStatBox(Pokemon _pokemonToRepresent, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		representedPokemon = _pokemonToRepresent;
		x = _xStart;
		y = _yStart;
	}

	PokemonStatBox() : Sprite(SpriteType::SpriteTypes::PokemonStatBox, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png") {
		originalSizeX = 0;
		originalSizeY = 0;
		representedPokemon = Pokemon();
		x, y = 0;
	}

	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), (x + 15), (y + 5), 0, (representedPokemon.pokemonName + "   Lvl. " + std::to_string(representedPokemon.level)).c_str());
		
		al_draw_filled_rectangle((x + 15), (y + 35), (x + 300), (y + 45), al_map_rgba(255, 0, 0, 0.3));

	}

	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
	}


};