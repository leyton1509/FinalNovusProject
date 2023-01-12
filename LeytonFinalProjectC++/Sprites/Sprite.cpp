#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Sprite
{

public:

	enum SpriteType
	{
		Player, Pokemon, Building, Grass, Entrance
	};

	enum SpriteType typeOfSprite;
	float xPosition;
	float yPosition;
	float velocityX;
	float velocityY;
	int directionX;
	int directionY;

	int spritewidth;
	int spriteHeight;

	ALLEGRO_BITMAP* spriteImage;

	Sprite(SpriteType _typeOfSprite,float _startX, float _startY, float _velocityX, float _velocityY, int _directionX, int _directionY, int _spritewidth, int _spriteHeight, const char* filename) {
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

	Sprite(SpriteType _typeOfSprite, float _startX, float _startY, int _spritewidth, int _spriteHeight, const char* filename) {
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


};