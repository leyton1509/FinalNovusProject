#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
class PokemonStatBox : public Sprite {

public:

	int originalSizeX;
	int originalSizeY;
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 28, NULL);
	ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);
	ALLEGRO_BITMAP* whiteHealthBar = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/WhiteHealthBar.png");
	ALLEGRO_BITMAP* redHealthBar = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/RedHealthBar.png");
	float x;
	float y;

	PokemonStatBox(Pokemon& _pokemonToRepresent, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		x = _xStart;
		y = _yStart;
	}

	PokemonStatBox() : Sprite(SpriteType::SpriteTypes::PokemonStatBox, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png") {
		originalSizeX = 0;
		originalSizeY = 0;
		x, y = 0;
	}

	void drawSprite(Pokemon& representedPokemon) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), (x + 15), (y + 5), 0, (representedPokemon.pokemonName + "   Lvl. " + std::to_string(representedPokemon.level)).c_str());
		al_draw_scaled_bitmap(whiteHealthBar, 0, 0, 128, 32, x + 15, y + 35, 285, 10, 0);
		//al_draw_filled_rectangle((x + 15), (y + 35), (x + 15 + (static_cast<float>(representedPokemon.currentHealth) / static_cast<float>(representedPokemon.healthActual) * static_cast<float>(285))), (y + 45), al_map_rgba(255, 0, 0, 0.3));
		al_draw_scaled_bitmap(redHealthBar, 0, 0, 128, 32, x + 15, y + 35, (static_cast<float>(representedPokemon.currentHealth) / static_cast<float>(representedPokemon.healthActual) * static_cast<float>(285)), 10, 0);

		// al_draw_scaled_bitmap(spriteImage, 0,0 ,(x + 15), (y + 35), (x + 15 + 285), (y + 45));
		al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (x + 15), (y + 50), 0, ("HP: " + std::to_string(representedPokemon.currentHealth) + "/" + std::to_string(representedPokemon.healthActual)).c_str());

	}

	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
		al_destroy_font(fontSmaller);
		al_destroy_bitmap(whiteHealthBar);
	}


};