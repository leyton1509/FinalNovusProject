#include "../Sprites/Button.h"
#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_font.h>
#include "../Sprites/Items/PokeBall.h"

// A button with the image of a pokeball and the amount of them
// Inherits from Button which inherits from Sprite
class ItemPokeBallButton : public Button {

public:
	// Name of item
	string itemName;
	// A representation of the poke ball class
	PokeBall pokeball;

	// ItemPokeBallButton with the pokemon to add to the players party
	ItemPokeBallButton(int pokeBallID, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button(_originalSizeX, _originalSizeY, _xStart, _yStart, _width, _height, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png") {
		pokeball = PokeBall(pokeBallID);
		pokeball.xPosition = _xStart;
		pokeball.yPosition = _yStart;
		pokeball.spritewidth = _width;
		pokeball.spriteHeight = _height;
	}

	// Empty const
	ItemPokeBallButton() : Button() {
		originalSizeX = 0;
		itemName = "";
		originalSizeY = 0;
	}

	// Draws the button with the pokeball and amount
	void drawSprite(int amountOfItem) {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		pokeball.drawSprite();
		if (amountOfItem == 0) {
			al_draw_text(fontSmaller, al_map_rgb(220, 20, 60), xPosition + 28, yPosition + 64, 0, ("x " + std::to_string(amountOfItem)).c_str());
		}
		else {
			al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), xPosition + 35, yPosition + 64, 0, ("x " + std::to_string(amountOfItem)).c_str());
		}


	}

	// Destroys all the sprites
	void destroySprite() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(fontSmaller);
	}






};