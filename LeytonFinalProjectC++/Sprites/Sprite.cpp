#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "SpriteType.cpp";

// Class to represent a sprite 
class Sprite
{

// Public accessors
public:
	
	// Enum of the type of sprite
	enum SpriteType::SpriteTypes typeOfSprite;
	// The x position of the sprite
	float xPosition;
	// The y position of the sprite
	float yPosition;
	// The x velocity of the sprite
	float velocityX;
	// The y velocity of the sprite
	float velocityY;
	// The x direction of the sprite
	int directionX;
	// The y direction of the sprite
	int directionY;
	// Width of sprite
	int spritewidth;
	// Height of sprite
	int spriteHeight;
	// Bit map image of sprite or spritesheet
	ALLEGRO_BITMAP* spriteImage;

	// Constructor for sprite with inputs for speed and direction
	Sprite(SpriteType::SpriteTypes _typeOfSprite,float _startX, float _startY, float _velocityX, float _velocityY, int _directionX, int _directionY, int _spritewidth, int _spriteHeight, const char* filename) {
		typeOfSprite = _typeOfSprite;
		xPosition = _startX;
		yPosition = _startY;
		velocityX = _velocityX;
		velocityY = _velocityY;
		directionX = _directionX;
		directionY = _directionY;
		spritewidth = _spritewidth;
		spriteHeight = _spriteHeight;
		spriteImage = al_load_bitmap(filename);

	}

	// Constructor for sprite without inputs for speed and direction
	Sprite(SpriteType::SpriteTypes _typeOfSprite, float _startX, float _startY, int _spritewidth, int _spriteHeight, const char* filename) {
		typeOfSprite = _typeOfSprite;
		xPosition = _startX;
		yPosition = _startY;
		velocityX = 0;
		velocityY = 0;
		directionX = 0;
		directionY = 0;
		spritewidth = _spritewidth;
		spriteHeight = _spriteHeight;
		spriteImage = al_load_bitmap(filename);
	}

	void drawSprite() {
		// draw sprite
	}



};