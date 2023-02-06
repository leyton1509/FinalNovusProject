#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../../Pokemon/Moves/MoveManager.h"
#include "../../Pokemon/PokemonType.h"
// A class to control a single move animation
class MoveAnimation{

	// The id of the move
	int moveID;
	// The current frame of the animation
	int currentFrame;
	// Duration of animation in frames
	int duration;
	// The starting X position of the animation
	int startX;
	// The starting X position of the animation
	int startY;
	// The destination X position of the animation
	int destinationX;
	// The destination Y position of the animation
	int destinationY;
	// The state of the animation
	int state;
	// The xtile for the style sheet
	int xTileForStyleSheet;
	// The ytile for the style sheet
	int yTileForSyleSheet;
	// If the animation is finished
	bool isAnimationFinished;
	// The style sheet to use
	ALLEGRO_BITMAP* stylesheet;
	// max number of x on the style sheet
	int xMaxStyleSheet;
	// max number to y on the style sheet
	int yMaxStyleSheet;
	// The length of each sprite
	int lengthOfEachSprite;
	// The difference in positions for each sprite at the start
	int differenceInX;
	// The difference in positions for each sprite at the start
	int differenceInY;

	// Some moves go from player pokemon to opponent, some just loop through at the opponent
	bool isStartDestination(int moveID) {
		return false;
	}

	void initialiseStyleSheet(int moveID) {

		// Uses the move move manager to get the details of the move
		MoveManager moveManager = moveManager.instance();
		Move move = moveManager.getMoveDetails(moveID);

		if (move.pokemonTypeOfMove == PokemonType::Normal) {
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/003-Attack01.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
		}
		else {
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/003-Attack01.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
		}
	}

	// Default creation of move animation
	MoveAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int _opponentPokemonX, int _opponentPokemonY){
	
		moveID = _moveID;
		initialiseStyleSheet(moveID);
		if (isStartDestination(moveID)) {
			startX = _opponentPokemonX;
			startY = _opponentPokemonY;
			destinationX = _opponentPokemonX;
			destinationY = _opponentPokemonY;
		}
		else {
			startX = _playerPokemonX;
			startY = _playerPokemonY;
			destinationX = _opponentPokemonX;
			destinationY = _opponentPokemonY;
		}
		state = 1;
		currentFrame = 0;
		xTileForStyleSheet = 0;
		yTileForSyleSheet = 0;
		isAnimationFinished = false;
		duration = 120;
	    lengthOfEachSprite = duration / (xMaxStyleSheet + yMaxStyleSheet);
		differenceInX = destinationX - startX;
		differenceInY = destinationY - startY;
	}

	void drawAnimation() {
		if (state != 0) {

			if (currentFrame != duration) {
				
				if (lengthOfEachSprite * (xTileForStyleSheet + yTileForSyleSheet)> currentFrame) {
					if (xTileForStyleSheet < xMaxStyleSheet) {
						xTileForStyleSheet++;
					}
					else {
						if (yTileForSyleSheet < yMaxStyleSheet) {
							xTileForStyleSheet = 0;
							yTileForSyleSheet++;
						}
						else {
							state = 0;
						}
					}
				}

			}

			else {
				state = 0;
				currentFrame = 0;
				isAnimationFinished = true;
			}
			currentFrame++;
		}

		if (startX != destinationX) {

			if (startX < destinationX) {
				startX + (differenceInX / duration);
			}
			else {
				startX - (differenceInX / duration);
			}
		}

		


		al_draw_bitmap_region(stylesheet, (192 * xTileForStyleSheet), (192 * yTileForSyleSheet), 64, 64, startX, startY, 0);

	}

};