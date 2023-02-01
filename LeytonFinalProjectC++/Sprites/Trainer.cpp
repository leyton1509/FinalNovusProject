#include "../Sprites/Spriteheader.h"


class Trainer : public Sprite{
public:

	
	Trainer(int xTile, int yTile, ALLEGRO_BITMAP * stylesheet) : Sprite(SpriteType::SpriteTypes::Player, xTile * 32, yTile * 32,0,0, 0,0, 32,32, stylesheet) {

	}
};