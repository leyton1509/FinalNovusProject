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
	 int state = 0;
	 int currentFrame = 0;
	 float framerate = 60;
	 float moveThisTurn = (32 * 2/framerate);


	PlayerCharacter() : Sprite(SpriteType::SpriteTypes::Player, 0, 0, 0, 0, 0, 0, 64, 64, "Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png") {
		xValueForStyleSheet = 0;
		yValueForStyleSheet = 0;
	}

	void moveCharacter(const char * keyPressed) {


		if (strcmp(keyPressed, "w") == 0 ){
			if (directionY!=1 && state == 0) {
				yValueForStyleSheet = 192;
				state = 0;
				directionY = 1;
				directionX = 0;
			}
			else {
				if (state == 0) {
					state = 1;
				}
			}

		}

		else if (strcmp(keyPressed, "s") == 0 ){
			if (directionY != -1 && state == 0) {
				yValueForStyleSheet = 0;
				state = 0;
				directionY = -1;
				directionX = 0;		
			}
			else {
				if (state == 0) {
					state = 1;
				}
			}
		}

		else if (strcmp(keyPressed, "a") == 0) {
			if (directionX != -1 && state == 0) {
				yValueForStyleSheet = 64;
				state = 0;
				directionX = -1;
				directionY = 0;
			}
			else {
				if (state == 0) {
					state = 1;
				}
				
			}
		}

		else if (strcmp(keyPressed, "d") == 0) {

			if (directionX != 1 && state == 0) {
				state = 0;
				yValueForStyleSheet = 128;
				directionX = 1;
				directionY = 0;
			}
			else {
				if (state == 0) {
					state = 1;
				}
			}

		}

	}

	void updatePosition() {
		if (directionX == 1) {
			xPosition += moveThisTurn;
		}
		else if (directionX == -1) {
			xPosition -= moveThisTurn;
		}
		else if (directionY == -1) {
			yPosition += moveThisTurn;
		}
		else if (directionY == 1) {
			yPosition -= moveThisTurn;
		}
	}

	void drawSprite() {

		if (state != 0) {
			if (currentFrame <= framerate / 6 && currentFrame >= 0) {
				state = 1;
				updatePosition();
				currentFrame++;
			}
			else if (currentFrame <= (framerate / 6 * 2) && currentFrame > framerate / 6) {
				state = 2;
				updatePosition();
				currentFrame++;
			}
			else if (currentFrame <= (framerate / 6 * 3) && currentFrame > framerate / 6 * 2) {
				state = 3;
				updatePosition();
				currentFrame++;
			}
			else{
				state = 0;
				currentFrame = 0;
			}
		}

		al_draw_bitmap_region(spriteImage, (64 * state), yValueForStyleSheet, 64, 64, xPosition, yPosition, 0);
	}
	
	

	


};