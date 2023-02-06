#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../../Pokemon/Moves/MoveManager.h"
#include "../../Pokemon/PokemonType.h"
#include <math.h>   
// A class to control a single move animation
class MoveAnimation{

public :
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
	// Current x pos
	int currentXPos;
	// Current y pos
	int currentYPos;

	int opponentPokemonNum;
	int playerPokemonNum;

	
	// Some moves go from player pokemon to opponent, some just loop through at the opponent
	bool isStartDestination(int moveID) {
		return false;
	}

	// Initialises the style sheet for the move used
	// Currently based off move type
	void initialiseStyleSheet(int moveID) {

		// Uses the move move manager to get the details of the move
		MoveManager moveManager = moveManager.instance();
		Move move = moveManager.getMoveDetails(moveID);

		// Switches the style sheet and images based on the move type
		switch (move.pokemonTypeOfMove)
		{
		case PokemonType::Normal:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/003-Attack01.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Fire:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASFusionFlare.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 4;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Water:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/water3.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 2;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Grass:
			
			break;
		case PokemonType::Electric:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8FusionBolt.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Ice:
			
			break;
		case PokemonType::Fighting:
			
			break;
		case PokemonType::Poison:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/poison4.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 2;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Ground:
			
			break;
		case PokemonType::Flying:
			
			break;
		case PokemonType::Psychic:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASPsychoBoost.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;

			break;
		case PokemonType::Bug:
			
			break;
		case PokemonType::Rock:
			
			break;
		case PokemonType::Ghost:
			
			break;
		case PokemonType::Dark:

			break;
		case PokemonType::Dragon:
			
			break;
		case PokemonType::Steel:
		
			break;
		case PokemonType::Fairy:
			
			break;
		case PokemonType::None:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/003-Attack01.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		default:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/003-Attack01.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		}


	}

	// Default creation of move animation
	MoveAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int _opponentPokemonX, int _opponentPokemonY, int _opponentPokemonNum, int _playerPokemonNum){
		opponentPokemonNum = _opponentPokemonNum;
		playerPokemonNum = _playerPokemonNum;

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
		currentFrame = 0;
		
		isAnimationFinished = false;
		duration = 90;
	    lengthOfEachSprite = duration / (xMaxStyleSheet * yMaxStyleSheet);
		differenceInX = (destinationX - startX) / duration;
		differenceInY = (destinationY - startY) / duration;
		currentXPos = startX;
		currentYPos = startY;
	}

	void drawAnimation() {
		

		if (currentFrame != duration) {

			// cout << "Left : " << currentFrame  << " Right : " << lengthOfEachSprite * xTileForStyleSheet  << "\n";
			if (currentFrame  > lengthOfEachSprite * xTileForStyleSheet+1) {
				if (xTileForStyleSheet < xMaxStyleSheet) {
					xTileForStyleSheet++;
				}
				else {
					if (yTileForSyleSheet < yMaxStyleSheet) {
						xTileForStyleSheet = 0;
						yTileForSyleSheet++;
					}
				}
			}

		}

		else {

			currentFrame = 0;
			isAnimationFinished = true;
		}

		
		if (currentXPos != destinationX) {
			currentXPos = currentXPos + differenceInX;
		}

		if (currentYPos != destinationY) {
			currentYPos = currentYPos + differenceInY;
		}
		
		

		currentFrame++;
		al_draw_bitmap_region(stylesheet, (192 * xTileForStyleSheet), (192 * yTileForSyleSheet), 192, 192, currentXPos, currentYPos, 0);

	}

};