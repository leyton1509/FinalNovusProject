#include <allegro5/allegro_font.h>
#include <list>
#include <string>
#include "../Sprites/Spriteheader.h"

class TextBox : public Sprite {

public: 

	// Original X Size of image
	int originalSizeX;
	// Original Y Size of image
	int originalSizeY;

	TextBox(std::list<std::string> textToDisplay, int _width, int _height) : Sprite (SpriteType::SpriteTypes::Button, 10, 450, _width, _height, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png"){
		originalSizeX = 256;
		originalSizeY = 96;
	}
};