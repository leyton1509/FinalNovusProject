#include "../Sprites/Spriteheader.h"
#include <allegro5/allegro_font.h>

// Default button class that extends sprite
// Has extra functionality for is clicked and a check for its displayed
class Button : public Sprite {

public:

	// The original x size of image
	int originalSizeX;
	// The original y size of image
	int originalSizeY;
	// Whether or not the button should be on screen or not
	bool isDisplayed = true;

	ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

	bool hasText;
	float buttonValue;

	// Constructor with the size and position parameters
	Button(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char * _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		hasText = false;
		buttonValue = 0;
	}

	// Constructor with the size and position parameters
	Button(int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath, float _value) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		hasText = true;
		buttonValue = _value;
	}



	// Empty constructor
	Button() : Sprite(SpriteType::SpriteTypes::Button, 0,0,0,0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		originalSizeX = 0;
		originalSizeY = 0;
		hasText = false;
		buttonValue = 0;
	}

	// Draws the sprite at the correct position if it is displayed
	void drawSprite() {
		if (isDisplayed) {
			al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
			if (hasText) {
				al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), xPosition + 30, yPosition + 5, 0, std::to_string(int(buttonValue)).c_str());
			}
		}
	}

	// Draws the sprite at the correct position if it is displayed with an int value
	void drawSprite(int value) {
		
		if (isDisplayed) {
			al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
			al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), xPosition + 30, yPosition + 5, 0, std::to_string(value).c_str());
			
		}
	}

	// Draws the sprite at the correct position if it is displayed with a string value
	void drawSprite(std::string value) {

		if (isDisplayed) {
			al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
			al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), xPosition + 6, yPosition+3, 0, (value).c_str());

		}
	}

	// Returns true if the mouse position is within the rectangle and its displayed
	bool hasBeenClicked(double xMousePosition, double yMousePosition){
		if (isDisplayed) {
			if (xMousePosition > xPosition && xMousePosition < xPosition + spritewidth && yMousePosition > yPosition && yMousePosition < yPosition + spriteHeight) {
				return true;
			}
		}
		return false;
	}

	void destroySprite() {
		al_destroy_bitmap(spriteImage);
	}



};