#include "../Sprites/Spriteheader.h"
#include "../Sprites/PlayerCharacter.h"


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

	bool hasBeenFought = false;

	// Main constructor for loading a character 
	Trainer(const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet, int _xTileForSpriteSheet, int _yTileForSpriteSheet) : Sprite(SpriteType::SpriteTypes::Player, _xTile * 32, _yTile * 32,0,0, 0,0, 32,32, stylesheet) {
		name = _name;
		xTile = _xTile;
		yTile = _yTile;
		xTileForSpriteSheet = _xTileForSpriteSheet;
		yTileForSpriteSheet = _yTileForSpriteSheet;
	}

	Trainer() : Sprite(SpriteType::SpriteTypes::Player, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		name = "";
		xTile = 0;
		yTile = 0;
		xTileForSpriteSheet = 0;
		yTileForSpriteSheet = 0;
	}

	void setPositions(int _xTile, int _yTile) {
		xTile = _xTile;
		yTile = _yTile;
		xPosition = xTile * 32;
		yPosition = yTile * 32;

	}

	// Draws the current sprite
	void drawSprite() {
		//al_draw_scaled_bitmap(spriteImage, (64 * state) + 16, yValueForStyleSheet + 12, 42, 48, xPosition, yPosition, 48, 48, 0);

		al_draw_scaled_bitmap(spriteImage, (32 * xTileForSpriteSheet) + 6, (32 * yTileForSpriteSheet) +6, 32, 32, xPosition, yPosition, 64, 64, 0);
	}

	void interact(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue, int screenWidth, int screenHeight) {
		cout << "hi\n";
	}

	void mapDirectonToSpriteSheet() {

	}

	bool isInLineOfSight(int xTilePlayer, int yTilePlayer) {

		// Facing left
		int tempYTile = yTilePlayer + 1;
		if (directionX == -1) {
			if ((xTile) - (xTilePlayer - 1) > 0 && (xTile)-(xTilePlayer - 1)<=3  && ((tempYTile) == (yTile)) ) {
				return 1;
			}

		}

	}

	
	// Checks the locaions to see if the character is interacting with the current object
	bool isInteracting(const char* keyPressed, int xTile, int yTile, int directionX, int directionY, int mapSizeX, int mapSizeY) {
		// std::cout << "Current X : " << xTile << " Current Y: " << yTile << " X : " << xPosition / 32 << " Y :" << yPosition / 32 << " \n";

		if (!hasBeenFought) {
			int tempYTile = yTile + 1;
			if (strcmp(keyPressed, "w") == 0) {
				if (directionY == 1) {
					if (tempYTile - 1 >= 0 || tempYTile - 2 >= 0) {
						if (xTile == (xPosition / 32) && ((tempYTile - 1) == (yPosition / 32)) || xTile == (xPosition / 32) && ((tempYTile - 2) == (yPosition / 32))  ) {
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
						if (xTile == (xPosition / 32) && ((tempYTile + 1) == (yPosition / 32))) {
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
						if ((xTile - 1) == (xPosition / 32) && ((tempYTile) == (yPosition / 32)) || (xTile - 1) == (xPosition / 32) && ((tempYTile-1) == (yPosition / 32))) {
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
						if ((xTile + 1) == (xPosition / 32) && ((tempYTile) == (yPosition / 32)) || (xTile + 1) == (xPosition / 32) && ((tempYTile-1) == (yPosition / 32))) {
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
		}

		return 0;
	}
};