
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
using namespace std;

// Player Character class which represents the players overworld character
// Inherits sprite so it has access to its methods
class PlayerCharacter : public Sprite{

// Public accessors
 public:

	// The x value of which sprite to load on style sheet
	int xValueForStyleSheet;
	// The y value of which sprite to load on style sheet
	int yValueForStyleSheet;
	// The current state of the sprite
	int state;
	// The current frame used to animemate the sprite
	int currentFrame;
	// The framerate used
	float framerate;
	// How much to move each frame
	float moveThisTurn;
	// The x tile the player is on based on the text map
	int xTilePosition;
	// The y tile the player is on based on the text map
	int yTilePosition;
	// An array of the tile of the last encounter stops the repeated encounter in a square
	int locationfOfLastEnounter[2] = {0,0};

	int numberOfPokemonInParty = 0;
	Pokemon trainersParty[6];
	int numberOfPokemonInBox = 0;
	Pokemon box[30];


	// The player character constructor
	// Sets up the values for the variables in the class
	// Passes the variables up to sprite, including the type of sprite, pos, vel, width height and image loc
	PlayerCharacter() : Sprite(SpriteType::SpriteTypes::Player, 8, 0, 0, 0, 0, 0, 64, 64, "../LeytonFinalProjectC++/Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png") {
		xValueForStyleSheet = 0;
		yValueForStyleSheet = 0;
		xTilePosition = 0;
		yTilePosition = 0;
		state = 0;
		currentFrame = 0;
		framerate = 60;
		moveThisTurn = (32 * 2 / framerate);
	}


	void addPokemon(Pokemon pokemonToAdd) {
		if (numberOfPokemonInParty < 6) {
			trainersParty[numberOfPokemonInParty] = pokemonToAdd;
			numberOfPokemonInParty++;
		}
		else {
			if (numberOfPokemonInBox < 30) {
				box[numberOfPokemonInBox] = pokemonToAdd;
				numberOfPokemonInBox++;
			}
		}
	}

	// method for checking if all pokemon in the party are dead
	// returns true if all dead
	bool isAllPokemonInPartyDead() {
		if (numberOfPokemonInParty - 1 < 0){
			return true;
		}
		for (int i = 0; i < numberOfPokemonInParty-1; i++)
		{
			if (trainersParty[i].currentHealth > 0) {
				return false;;
			}
		}
		return true;
	}

	// Sets all the positions for the player
	void setAllPositions(int x, int y) {
		xTilePosition = x;
		yTilePosition = y;
		xPosition = x * 32;
		yPosition = y * 32;

	}

	// Sets the location of the previous encounter in the array
	void setNewEncounterLocation() {
		locationfOfLastEnounter[0] = xTilePosition;
		locationfOfLastEnounter[1] = yTilePosition;
	}

	// Returns true if the players square is the same as the one theyre standing on
	bool isTheSameSquareAsLastEncounter() {
		if (xTilePosition == locationfOfLastEnounter[0] && yTilePosition == locationfOfLastEnounter[1]) {
			return true;
		}
		return false;
	}

	// Moves the character based on the keypressed
	void moveCharacter(const char * keyPressed) {

		// Checks the state to see if its not zero and not already going in that direction
		// Sets the y value n the style sheet to the right facing direction
		// Sets the direction for x and y
		if (strcmp(keyPressed, "w") == 0 ){
			if (directionY!=1 && state == 0) {
				yValueForStyleSheet = 192;
				state = 0;
				directionY = 1;
				directionX = 0;
			}
			// If the state is 0, then set the state to 1
			else {
				if (state == 0) {
					state = 1;
					
				}
			}

		}

		else if (strcmp(keyPressed, "s") == 0 ){
			if (directionY != -1 && state == 0) {
				yValueForStyleSheet = 0;
				state = 0;
				directionY = -1;
				directionX = 0;		
			}
			else {
				if (state == 0) {
					state = 1;
					
				}
			}
		}

		else if (strcmp(keyPressed, "a") == 0) {
			if (directionX != -1 && state == 0) {
				yValueForStyleSheet = 64;
				state = 0;
				directionX = -1;
				directionY = 0;
			}
			else {
				if (state == 0) {
					state = 1;
					
				}
				
			}
		}

		else if (strcmp(keyPressed, "d") == 0) {

			if (directionX != 1 && state == 0) {
				state = 0;
				yValueForStyleSheet = 128;
				directionX = 1;
				directionY = 0;
			}
			else {
				if (state == 0) {
					state = 1;
				}
			}

		}

	}

	void updateTile() {
		if (currentFrame == 0) {
			if (directionX == 1) {
				xTilePosition++;
			}
			else if (directionX == -1) {
				xTilePosition--;
			}
			else if (directionY == -1) {
				yTilePosition++;
			}
			else if (directionY == 1) {
				yTilePosition--;
			}
		}
	}



	// Updates the correct position based on the direction of the character
	void updatePosition() {
		
		if (directionX == 1) {
			xPosition += moveThisTurn;
		}
		else if (directionX == -1) {
			xPosition -= moveThisTurn;
		}
		else if (directionY == -1) {
			yPosition += moveThisTurn;
		}
		else if (directionY == 1) {
			yPosition -= moveThisTurn;
		}
	
	}



	// Draws the sprite based on the state of the sprite
	void drawSprite() {

		if (state != 0) {

			if (state == 1) {
				updateTile();
			}

			if (currentFrame <= framerate / 6 && currentFrame >= 0) {
				state = 1;
				updatePosition();
				currentFrame++;
			}
			else if (currentFrame <= (framerate / 6 * 2) && currentFrame > framerate / 6) {
				state = 2;
				updatePosition();
				currentFrame++;
			}
			else if (currentFrame < (framerate / 6 * 3) && currentFrame > framerate / 6 * 2) {
				state = 3;
				updatePosition();
				currentFrame++;
			}
			else{
				state = 0;
				currentFrame = 0;
			}
		}
		

		//al_draw_bitmap_region(spriteImage, (64 * state) + 16, yValueForStyleSheet +12, 42, 48, xPosition, yPosition, 0);
		al_draw_scaled_bitmap(spriteImage, (64 * state) + 16, yValueForStyleSheet + 12, 42, 48, xPosition, yPosition, 48,48, 0);
	}

};