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
	// The number in the party of the pokemon that used the move
	int opponentPokemonNum;
	// The number in the party of the pokemon that used the move
	int playerPokemonNum;
	// The sprite number regardless of x and y
	int totalSpritePos;

	
	// Some moves go from player pokemon to opponent, some just loop through at the opponent
	bool isStartDestination(int moveID) {
		MoveManager moveManager = moveManager.instance();
		Move move = moveManager.getMoveDetails(moveID);

		switch (move.pokemonTypeOfMove)
		{
		case PokemonType::Grass:
			return true;
		case PokemonType::Ice:
			return true;
		case PokemonType::Water:
			return true;
		case PokemonType::Rock:
			return true;
		case PokemonType::Bug:
			return true;
		case PokemonType::Dark:
			return true;
		case PokemonType::Ghost:
			return true;
		case PokemonType::Steel:
			return true;
		case PokemonType::Fighting:
			return true;
		default:
			return false;
		}
		
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
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/Fire3.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 6;
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
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/grass2.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			duration = 50;
			break;
		case PokemonType::Electric:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8FusionBolt.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Ice:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8GlacialLance.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Fighting:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASForcePalm.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Poison:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/poison4.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 2;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Ground:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8LandsWrath.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 2;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Flying:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASAeroblast.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 2;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Psychic:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASPsychoBoost.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;

			break;
		case PokemonType::Bug:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/poison3.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Rock:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8PrecipiceBlades.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 1;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Ghost:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8EerieSpell.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 6;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Dark:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/PRASBrutalSwing.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Dragon:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8AstralBarrage.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Steel:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/Sword5.png");
			xMaxStyleSheet = 5;
			yMaxStyleSheet = 5;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
			break;
		case PokemonType::Fairy:
			stylesheet = al_load_bitmap("../LeytonFinalProjectC++/Sprites/AttackAnimations/GEN8MistyExplosion.png");
			xMaxStyleSheet = 4;
			yMaxStyleSheet = 3;
			xTileForStyleSheet = 0;
			yTileForSyleSheet = 0;
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
		duration = 80;
		moveID = _moveID;
		totalSpritePos = 0;
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
	    lengthOfEachSprite = duration / (xMaxStyleSheet * yMaxStyleSheet);
		differenceInX = (destinationX - startX) / duration;
		differenceInY = (destinationY - startY) / duration;
		currentXPos = startX;
		currentYPos = startY;
	}

	// Drwas the current state of the animation
	void drawAnimation() {
		

		if (currentFrame <= duration) {

			if (currentFrame  > (lengthOfEachSprite * totalSpritePos-1)) {
				if (xTileForStyleSheet < xMaxStyleSheet) {
					xTileForStyleSheet++;
				}
				else {
					if (yTileForSyleSheet < yMaxStyleSheet) {
						xTileForStyleSheet = 0;
						yTileForSyleSheet++;
					}
				}
				totalSpritePos++;
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

		else {
			isAnimationFinished = true;
		}
		
		

		

	}

	void destroySprite() {
		al_destroy_bitmap(stylesheet);
	}

};