#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>

// A button for displaying a button with a pokemon  and health attatched
// Inherits from Button which inherits from Sprite
class SwitchPokemonButton : public Button {

public:

	//ALLEGRO_BITMAP* otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");

	// Connstructor with the pokemon to add to the players party
	SwitchPokemonButton(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png") {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
	}

	// Empty const
	SwitchPokemonButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	// Draws the button and pokemon attacthed to it
	void drawSprite(Pokemon& pokemon, ALLEGRO_BITMAP* otherPokemonSprite) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		if (!(strcmp(pokemon.pokemonName.c_str(), "") == 0)) {
			al_draw_scaled_bitmap(otherPokemonSprite, (80 * pokemon.xPositionOnSpriteSheet), (80 * pokemon.yPositionOnSpriteSheet), 80, 80, xPosition + 4, yPosition-2, spritewidth * 0.9, spriteHeight * 0.9, 0);
			string txt = std::to_string(pokemon.currentHealth) + "/" + std::to_string(pokemon.healthActual);
			if (pokemon.currentHealth == 0) {
				al_draw_text(fontSmaller, al_map_rgb(220, 20, 60), xPosition + 28, yPosition + 64, 0, txt.c_str());
			}
			else if (pokemon.currentHealth == pokemon.healthActual){
				al_draw_text(fontSmaller, al_map_rgb(0, 100, 0), xPosition + 28, yPosition + 64, 0, txt.c_str());
			}
			else {
				al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), xPosition + 28, yPosition + 64, 0, txt.c_str());
			}
			
		}
		

	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
		//al_destroy_bitmap(otherPokemonSprite);
		al_destroy_font(fontSmaller);
	}






};