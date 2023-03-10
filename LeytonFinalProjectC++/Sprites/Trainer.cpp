#include "../Sprites/Spriteheader.h"
#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/Pokemon.h"
#include <list>
#include "TextBox.h"


class Trainer : public Sprite{
public:

	// Name of the trainer
	const char* name;
	// X tile for on the map
	int xTile;
	// Y tile for on the map
	int yTile;
	// X tile for the style sheet position
	int xTileForSpriteSheet;
	// Y tile for the style sheet position
	int yTileForSpriteSheet;
	// original x for tile
	int xTileOriginal;
	// original y for tile
	int yTileForOriginal;
	// Bool for if the trainer has been fought or mot
	bool hasBeenFought = false;
	// The trainers team
	Pokemon trainersTeam[6];
	// The number of pokemon in the party
	int numberOfPokemonInParty = 0;
	// The location number of the trainer
	int locationNumber;
	// The list of strings to disply in textbox
	std::list<string> strings = {};
	// Bool for if the trainer should fight via line of sight
	bool shouldFightWithSight;
	// If the trainer is a fighting trainer
	bool isBattlingTrainer;

	

	// Main constructor for loading a trainer, with name, pos, stylesheet and styelsheet position 
	Trainer(const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet, int _xTileForSpriteSheet, int _yTileForSpriteSheet) : Sprite(SpriteType::SpriteTypes::Player, _xTile * 32, _yTile * 32,0,0, 0,0, 32,32, stylesheet) {
		name = _name;
		xTileOriginal = _xTileForSpriteSheet;
		yTileForOriginal = _yTileForSpriteSheet;
		xTile = _xTile;
		yTile = _yTile;
		xTileForSpriteSheet = _xTileForSpriteSheet;
		yTileForSpriteSheet = _yTileForSpriteSheet;
		locationNumber = 0;
		shouldFightWithSight = true;
		isBattlingTrainer = true;
	}

	// Empty const
	Trainer() : Sprite(SpriteType::SpriteTypes::Player, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		name = "";
		xTile = 0;
		yTile = 0;
		xTileOriginal = 0;
		yTileForOriginal = 0;
		xTileForSpriteSheet = 0;
		yTileForSpriteSheet = 0;
		locationNumber = 0;
		shouldFightWithSight = true;
		isBattlingTrainer = true;
	}

	// Method for displaying a text box
	void displayTextBox(int xPos, int yPos, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE *  queue) {
		TextBox tb = TextBox(xPos , yPos, strings, screenWidth / 2, screenHeight / 8, queue);
	}

	// Adds a pokemon to the trainers party
	// If the player has 6 pokemon it gets stored in the box
	void addPokemon(Pokemon pokemonToAdd) {
		if (numberOfPokemonInParty < 6) {
			trainersTeam[numberOfPokemonInParty] = pokemonToAdd;
			numberOfPokemonInParty++;
		}
	}

	// method for checking if all pokemon in the party are dead
	// returns true if all dead
	bool isAllPokemonInPartyDead() {

		for (int i = 0; i < numberOfPokemonInParty; i++)
		{
			if (strcmp(trainersTeam[i].pokemonName.c_str(), "") != 0) {
				if (trainersTeam[i].currentHealth > 0) {
					return false;;
				}
			}
		}
		return true;
	}

	// Sets the position of the trainer, as well as the direction and location number
	void setPositions(int _xTile, int _yTile, int _directonX, int _directonY, int _locationNumber) {
		xTile = _xTile;
		yTile = _yTile;
		xPosition = xTile * 32;
		yPosition = yTile * 32;
		directionX = _directonX;
		directionY = _directonY;
		locationNumber = _locationNumber;
		mapDirectonToSpriteSheet();
	}

	// Turns the trainer sprite based on the direction
	void mapDirectonToSpriteSheet() {

		if (directionX == -1) {
			xTileForSpriteSheet = xTileOriginal;
			yTileForSpriteSheet = yTileForOriginal + 2;
		}
		
		else if (directionX == 1) {
			xTileForSpriteSheet = xTileOriginal+ 1;
			yTileForSpriteSheet = yTileForOriginal;
		}

		else if (directionY == 1) {
			xTileForSpriteSheet = xTileOriginal;
			yTileForSpriteSheet = yTileForOriginal;
		}
		else if (directionY == -1) {
			xTileForSpriteSheet = xTileOriginal+2;
			yTileForSpriteSheet = yTileForOriginal+1;
		}

	}

	// Draws the current sprite
	// returns true if it should battle
	void drawSprite() {
		//al_draw_scaled_bitmap(spriteImage, (64 * state) + 16, yValueForStyleSheet + 12, 42, 48, xPosition, yPosition, 48, 48, 0);

		al_draw_scaled_bitmap(spriteImage, (32 * xTileForSpriteSheet), (32 * yTileForSpriteSheet), 32, 32, xPosition-14, yPosition, 64, 64, 0);
	}

	// If the trainer has been interacted
	void interact(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue, int screenWidth, int screenHeight) {


		// Makes sure the sprite faces the player when interacting
		if (player.directionX == 1) {
			directionX = -1;
			directionY = 0;
			mapDirectonToSpriteSheet();
		}else if (player.directionX == -1) {
			directionX = 1;
			directionY = 0;
			mapDirectonToSpriteSheet();
		}
		else if (player.directionY == 1) {
			directionY = -1;
			directionX = 0;
			mapDirectonToSpriteSheet();
		}
		else if (player.directionY == -1) {
			directionY = 1;
			directionX = 0;
			mapDirectonToSpriteSheet();
		}

		// Makes the player fight on interact
		
		if (!shouldFightWithSight) {
			shouldFightWithSight = true;
		}
		
		
	}

	// Code for detecting if the player is in the line of sight of the trainer
	// Works for up to 5 tiles 
	// Gets the direction
	// Then compares the tile of the trainer to the player
	bool isInLineOfSight(int xTilePlayer, int yTilePlayer) {

		if (shouldFightWithSight) {
			if (!hasBeenFought) {
				// Facing left
				int tempYTile = yTilePlayer + 1;
				if (directionX == -1) {
					if ((xTile)-(xTilePlayer - 1) >= 0 && (xTile)-(xTilePlayer - 1) <= 5 && ((yTile) == (yTilePlayer))) {
						return 1;
					}
				}
				else if (directionX == 1) {
					if ((xTilePlayer + 1) - (xTile) >= 0 && (xTilePlayer + 1) - xTile <= 5 && ((yTile) == (yTilePlayer))) {
						return 1;
					}
				}
				else if (directionY == -1) {
					if ((yTilePlayer + 1) - yTile >= 0 && (yTilePlayer + 1) - yTile <= 5 && ((xTile) == (xTilePlayer))) {
						return 1;
					}
				}
				else if (directionY == 1) {
					if (yTile - (yTilePlayer + 1) >= 0 && yTile - (yTilePlayer + 1) <= 5 && ((xTile) == (xTilePlayer))) {
						return 1;
					}
				}
			}
			
		}
		return 0;
	}

	
	// Checks the locaions to see if the character is interacting with the current object
	// Returns true if interacting, false if not
	bool isInteracting(const char* keyPressed, int xTile, int yTile, int directionX, int directionY, int mapSizeX, int mapSizeY) {
			int tempYTile = yTile + 1;
			if (strcmp(keyPressed, "w") == 0) {
				if (directionY == 1) {
					if (tempYTile - 1 >= 0 || tempYTile - 2 >= 0) {
						if ( xTile == (xPosition / 32) && ((tempYTile - 2) == (yPosition / 32))  ) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}

			else if (strcmp(keyPressed, "s") == 0) {
				if (directionY == -1) {
					if (tempYTile + 1 < mapSizeY) {
						if (xTile == (xPosition / 32) && ((tempYTile ) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}

			else if (strcmp(keyPressed, "a") == 0) {
				if (directionX == -1) {
					if (xTile - 1 >= 0) {
						if ((xTile - 1) == (xPosition / 32) && ((tempYTile-1) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}

			else if (strcmp(keyPressed, "d") == 0) {
				if (directionX == 1) {
					if (xTile + 1 < mapSizeX) {
						if ( (xTile + 1) == (xPosition / 32) && ((tempYTile-1) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
		

		return 0;
	}
};