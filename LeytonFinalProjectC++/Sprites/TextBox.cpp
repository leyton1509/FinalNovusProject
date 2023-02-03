#include <allegro5/allegro_font.h>
#include <list>
#include <string>
#include "../Sprites/Spriteheader.h"

// Class to display text to the user in the over world
class TextBox : public Sprite {

public: 

	// Original X Size of image
	int originalSizeX;
	// Original Y Size of image
	int originalSizeY;
	// The font to display with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 28, NULL);

	TextBox(std::list<std::string> textToDisplay, int _width, int _height) : Sprite (SpriteType::SpriteTypes::Button, 10, 450, _width, _height, "../LeytonFinalProjectC++/Sprites/TextBox/TextBox.png"){
		originalSizeX = 256;
		originalSizeY = 96;
	}

	// Destroys all the sprites 
	void destroySprites() {
		al_destroy_bitmap(spriteImage);
		al_destroy_font(font);
	}
};