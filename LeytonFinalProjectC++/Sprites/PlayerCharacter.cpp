#include "Sprite.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>



using namespace std;


 class PlayerCharacter : public Sprite{

 public:

	 int xValueForStyleSheet;
	 int yValueForStyleSheet;
	 int moveBy = 8;
	 int state = 0;

	PlayerCharacter() : Sprite(SpriteType::SpriteTypes::Player, 0, 0, 0, 0, 0, 0, 64, 64, "Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png") {
		xValueForStyleSheet = 0;
		yValueForStyleSheet = 0;
	}

	void moveCharacter(const char * keyPressed) {


		if (strcmp(keyPressed, "w") == 0 ){
			if (directionY!=1) {
				yValueForStyleSheet = 192;
				state = 0;
				directionY = 1;
				directionX = 0;
			}
			else {
				state = 1;
			}

			yPosition -= moveBy;
		}

		else if (strcmp(keyPressed, "s") == 0 ){
			if (directionY != -1) {
				yValueForStyleSheet = 0;
				state = 0;
				directionY = -1;
				directionX = 0;		
			}
			else {
				state = 1;
			}
			yPosition += moveBy;
		}

		else if (strcmp(keyPressed, "a") == 0) {
			if (directionX != -1) {
				yValueForStyleSheet = 64;
				state = 0;
				directionX = -1;
				directionY = 0;
			}
			else {
				state = 1;
			}
			xPosition -= moveBy;
		}

		else if (strcmp(keyPressed, "d") == 0) {

			if (directionX != 1) {
				state = 0;
				yValueForStyleSheet = 128;
				directionX = 1;
				directionY = 0;
			}
			else {
				state = 1;
			}

			xPosition += moveBy;
		}

	}



	void drawSprite() {
		al_draw_bitmap_region(spriteImage, (64 * state), yValueForStyleSheet, 64, 64, xPosition, yPosition, 0);
		if (state!=0) {
			if (state == 3) {
				state = 0;
			}
			else {
				state++;
			}
		}
		
	}
	
	

	


};