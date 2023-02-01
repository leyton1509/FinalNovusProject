#include "../Sprites/Spriteheader.h"


class Trainer : public Sprite{
public:

	const char* name;
	int xTile;
	int yTile;

	
	Trainer(const char * _name, int _xTile, int _yTile, ALLEGRO_BITMAP * stylesheet) : Sprite(SpriteType::SpriteTypes::Player, _xTile * 32, _yTile * 32,0,0, 0,0, 32,32, stylesheet) {
		name = _name;
		xTile = _xTile;
		yTile = _yTile;
	}
};