#include "../Sprites/Spriteheader.h"
#include <iostream>
#include "../Sprites/PlayerCharacter.h"
#include "../Sprites/ChoosePokemonButton.h"
#include "../Pokemon/PokemonManager.h"

class Interactable : public Sprite {

public:

	int idOfInteractable;

	// The original x size of image
	int originalSizeX;
	// The original y size of image
	int originalSizeY;
	// Whether or not the interactable should be on screen or not
	bool isDisplayed = true;
	// Boolean for if the object has been interacted with
	bool alreadyInteractedWith = false;
	// Boolean if the object should disappear when interacted with
	bool dissapeaarWhenInteractedWith;
	// Constructor with the size and position parameters
	Interactable(int _idOfInteractable, bool _dissapeaarWhenInteractedWith, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		idOfInteractable = _idOfInteractable;
		dissapeaarWhenInteractedWith = _dissapeaarWhenInteractedWith;
	}

	Interactable() : Sprite(SpriteType::SpriteTypes::Button, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		originalSizeX = 0;
		originalSizeY = 0;
		dissapeaarWhenInteractedWith = false;
		idOfInteractable = 0;
	}

	// Draws the sprite at the correct position if it is displayed
	void drawSprite() {
		if (isDisplayed) {
			if (dissapeaarWhenInteractedWith) {
				if (!alreadyInteractedWith) {
					al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
				}
			}
			else {
				al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);

			}
		}
	}

	// Checks the locaions to see if the character is interacting with the current object
	bool isInteracting(const char* keyPressed, int xTile, int yTile, int directionX, int directionY, int mapSizeX, int mapSizeY) {
		// std::cout << "Current X : " << xTile << " Current Y: " << yTile << " X : " << xPosition / 32 << " Y :" << yPosition / 32 << " \n";
	
		if (isDisplayed) {
			int tempYTile = yTile + 1;
			if (strcmp(keyPressed, "w") == 0) {
				if (directionY == 1) {
					if (tempYTile - 1 >= 0) {
						if (xTile == (xPosition / 32) && ((tempYTile - 1) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0; 
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			} 

			else if (strcmp(keyPressed, "s") == 0) {
				if (directionY == -1) {
					if (tempYTile + 1 < mapSizeY) {
						if (xTile == (xPosition / 32) && ((tempYTile + 1) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}

			else if (strcmp(keyPressed, "a") == 0) {
				if (directionX == -1) {
					if (xTile - 1 >= 0) {
						if ((xTile -1) == (xPosition / 32) && ((tempYTile) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}

			else if (strcmp(keyPressed, "d") == 0) {
				if (directionX == 1) {
					if (xTile + 1 < mapSizeX) {
						if ((xTile + 1) == (xPosition / 32) && ((tempYTile) == (yPosition / 32))) {
							return 1;
						}
						else {
							return 0;
						}
					}
					else {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
		}

		return 0;
	}

	// Method to be overidden for what the object does when interated
	 void interact(PlayerCharacter &player, ALLEGRO_EVENT_QUEUE* queue) {
		if (idOfInteractable == 1) {
			choosePokemon(player);
			isDisplayed = false;
		}

		alreadyInteractedWith = true;
	}



	 void choosePokemon(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue) {
		 double xMousePosition = 0;
		 double yMousePosition = 0;

		 // GUI info
		 bool done = false;
		 bool redraw = true;
		 ALLEGRO_EVENT event;

		 // BG sprite
		 ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/StarterBG.jpg");

		 // Reset the camera
		 ALLEGRO_TRANSFORM trans;
		 al_identity_transform(&trans);
		 al_use_transform(&trans);
		 al_draw_bitmap(background, 0, 0, 0);

		 PokemonManager pm = pm.instance();

		 Pokemon pokemon1 = pm.getDefaultPokemon("Gible");
		 pokemon1.setPokemonsLevel(5);
		 Pokemon pokemon2 = pm.getDefaultPokemon("Dratini");
		 pokemon2.setPokemonsLevel(5);
		 Pokemon pokemon3 = pm.getDefaultPokemon("Bagon");
		 pokemon3.setPokemonsLevel(5);


		 ChoosePokemonButton pokemonOneButton = ChoosePokemonButton(pokemon1, 128, 128, 8, 8, 64, 64, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
		 ChoosePokemonButton pokemonTwoButton = ChoosePokemonButton(pokemon2, 128, 128, 100, 8, 64, 64, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
		 ChoosePokemonButton pokemonThreeButton = ChoosePokemonButton(pokemon3, 128, 128, 100, 8, 64, 64, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
			 

		 bool chosenPokemon = false;

		 while (!chosenPokemon) {

			 al_wait_for_event(queue, &event);

			 switch (event.type)
			 {
			 case ALLEGRO_EVENT_TIMER:


				 redraw = true;
				 break;

			 case ALLEGRO_EVENT_MOUSE_AXES:
				 xMousePosition = event.mouse.x;
				 yMousePosition = event.mouse.y;
				 break;
			 case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

				 break;

			 }

		 }
			
	 }




};
