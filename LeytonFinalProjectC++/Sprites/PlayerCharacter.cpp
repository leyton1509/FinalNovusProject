#include "Sprite.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


#include <direct.h>
#include<limits.h>
#include<iostream>

using namespace std;




 class PlayerCharacter : public Sprite{

 public:



	PlayerCharacter() : Sprite(SpriteType::SpriteTypes::Player, 0, 0, 0, 0, 0, -1, 64, 64, "Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png") {
	}

	void moveCharacter(const char * keyPressed) {

		if (strcmp(keyPressed, "w") || strcmp(keyPressed, "up") == 0) {
			if (directionY!=1) {
				al_draw_bitmap_region(spriteImage, 0, 0, 256, 64, xPosition, yPosition, 0);
				directionY = 1;
				directionX = 0;
			}
		}

		if (strcmp(keyPressed, "s") || strcmp(keyPressed, "down") == 0) {
			if (directionY != -1) {
				al_draw_bitmap_region(spriteImage, 0, 0, 64, 64, xPosition, yPosition, 0);
				directionY = -1;
				directionX = 0;
			}
		}

		if (strcmp(keyPressed, "a") || strcmp(keyPressed, "left") == 0) {
			if (directionY != -1) {
				al_draw_bitmap_region(spriteImage, 0, 0, 128, 64, xPosition, yPosition, 0);
				directionX = -1;
				directionY = 0;
			}
		}

		if (strcmp(keyPressed, "d") || strcmp(keyPressed, "right") == 0) {
			if (directionY != -1) {
				al_draw_bitmap_region(spriteImage, 0, 0, 192, 64, xPosition, yPosition, 0);
				directionX = -1;
				directionY = 0;
			}
		}

	}





	void drawSprite() {
		al_draw_bitmap_region(spriteImage, 0, 0, 64, 64, xPosition, yPosition, 0);
	}
	
	

	


};