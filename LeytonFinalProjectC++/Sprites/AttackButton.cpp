#include "../Sprites/Button.h"
#include "../Pokemon/Moves/Move.h"
#include <allegro5/allegro_font.h>

// A specific attack button
// Inherits from Button which inherits from Sprite
class AttackButton : public Button {

public:

	// The move attatched to this button
	Move pokemonMove;

	// Connstructor with the move to be used and the positioning parameters
	AttackButton(Move& _move, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height) : Button( _originalSizeX,  _originalSizeY,  _xStart,  _yStart,  _width,  _height, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png") {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		pokemonMove = _move;
	}

	// Empty const
	AttackButton() : Button() {
		originalSizeX = 0;
		originalSizeY = 0;
	}

	// Draws all the info related to the move
	// Draws the red rectangle and if the move is vald
	// Will draw the move details
	void drawSprite() {
		al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
		// Can use powerpoints as check as its never altered from the default, currentPP is edited so this is fine
		if (pokemonMove.powerpoints != 0) {
			drawRectangleForColourOfMove();
			al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (xPosition + 5), (yPosition + 5), 0, (pokemonMove.moveName).c_str());
			al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (xPosition + 5), (yPosition + 25), 0, ("PP: " + std::to_string(pokemonMove.currentPowerPoints) + "/" + std::to_string(pokemonMove.powerpoints)).c_str());
			if (pokemonMove.power != 0) {
				al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (xPosition + 5), (yPosition + 45), 0, ("POW: " + std::to_string(pokemonMove.power) + " ACC: " + std::to_string(pokemonMove.accuracy)).c_str());
			}
			else {
				al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (xPosition + 5), (yPosition + 45), 0, ("ACC: " + std::to_string(pokemonMove.accuracy)).c_str());

			}
		}
		

	}

	void drawRectangleForColourOfMove() {

	}




};