
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../Sprites/Spriteheader.h"
#include "../Pokemon/Pokemon.h"
#include "../Sprites/Items/ItemManager.h"

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
	// Tracks the number of pokemon in the party
	int numberOfPokemonInParty = 0;
	// The pokemon in the party
	Pokemon trainersParty[6];
	// The number of pokemon in the box
	int numberOfPokemonInBox = 0;
	// The box of pokemon
	Pokemon box[30];
	// Handles all the items
	ItemManager itemManager = ItemManager();

	// Money
	int playersMoney;


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
		moveThisTurn = 1;
		playersMoney = 10000;
	}

	void recalcNumberOfPokemon() {
		int nParty = 0;
		int nBox = 0;

		for (int i = 0; i < 6; i++)
		{
			if (strcmp(trainersParty[i].pokemonName.c_str(), "") != 0) {
				nParty++;
			}
		}
		for (int i = 0; i < 30; i++)
		{
			if (strcmp(box[i].pokemonName.c_str(), "") != 0) {
				nBox++;
			}
		}


		numberOfPokemonInParty = nParty;
		numberOfPokemonInBox = nBox;
	}


	// Adds a pokemon to the players party
	// If the player has 6 pokemon it gets stored in the box
	void addPokemon(Pokemon pokemonToAdd) {

		int nextSpace = -1;
		for (int i = 0; i < 6; i++)
		{
			if (strcmp(trainersParty[i].pokemonName.c_str(), "") == 0) {
				nextSpace = i;
				break;
			}
		}

		if (nextSpace != -1) {
			trainersParty[nextSpace] = pokemonToAdd;
			numberOfPokemonInParty++;
		}
		else {
			int nextSpaceInBox = -1;
			for (int i = 0; i < 30; i++)
			{
				if (strcmp(box[i].pokemonName.c_str(), "") == 0) {
					nextSpaceInBox = i;
					break;
				}
			}

			if (nextSpaceInBox != -1) {
				box[nextSpaceInBox] = pokemonToAdd;
				numberOfPokemonInBox++;
			}
		}

	}

	// Returns the integer of the first pokemon alive
	// Returns -1 if none are alive
	int getFirstAlivePokemon() {

		for (int i = 0; i < 6; i++)
		{
			if (strcmp(trainersParty[i].pokemonName.c_str(), "") != 0) {
				if (trainersParty[i].currentHealth > 0) {
					return i;
				}
			}

		}
		return -1;
	}

	// method for checking if all pokemon in the party are dead
	// returns true if all dead
	bool isAllPokemonInPartyDead() {
		
		for (int i = 0; i < 6; i++)
		{
			if (strcmp(trainersParty[i].pokemonName.c_str(), "")!=0) {
				if (trainersParty[i].currentHealth > 0) {
					return false;;
				}
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

	// Updates the tile based on the players moving direction
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

	void resetPlayer(int x, int y) {
		state = 0;
		currentFrame = 0;
		setAllPositions(x, y);
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
			else if (currentFrame < (framerate / 6 * 3)+2 && currentFrame > framerate / 6 * 2) {
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