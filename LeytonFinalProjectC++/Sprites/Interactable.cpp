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
	
	// If using a style sheet, x pos
	int xTileStyleSheet;
	// If using a style sheet, y pos
	int yTileStyleSheet;

	// Constructor with the size and position parameters
	Interactable(int _idOfInteractable, bool _dissapeaarWhenInteractedWith, int _originalSizeX, int _originalSizeY, float _xStart, float _yStart, float _width, float _height, const char* _filepath) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = _originalSizeX;
		originalSizeY = _originalSizeY;
		idOfInteractable = _idOfInteractable;
		dissapeaarWhenInteractedWith = _dissapeaarWhenInteractedWith;
		xTileStyleSheet = -1;
		yTileStyleSheet = -1;
	}

	// Constructor with the size and position parameters and x tile y tile params
	Interactable(int _idOfInteractable, bool _dissapeaarWhenInteractedWith, float _xStart, float _yStart, float _width, float _height, const char* _filepath, int _xTileStyleSheet, int _yTileStyleSheet) : Sprite(SpriteType::SpriteTypes::Button, _xStart, _yStart, _width, _height, _filepath) {
		originalSizeX = -1;
		originalSizeY = -1;
		idOfInteractable = _idOfInteractable;
		dissapeaarWhenInteractedWith = _dissapeaarWhenInteractedWith;
		xTileStyleSheet = _xTileStyleSheet;
		yTileStyleSheet = _yTileStyleSheet;
	}

	Interactable() : Sprite(SpriteType::SpriteTypes::Button, 0, 0, 0, 0, "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg") {
		originalSizeX = 0;
		originalSizeY = 0;
		dissapeaarWhenInteractedWith = false;
		idOfInteractable = 0;
		xTileStyleSheet = -1;
		yTileStyleSheet = -1;
	}

	// Draws the sprite at the correct position if it is displayed
	void drawSprite() {
		if (isDisplayed) {
			if (xTileStyleSheet == -1) {
				if (dissapeaarWhenInteractedWith) {
					if (!alreadyInteractedWith) {
						al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);
					}
				}
				else {
					al_draw_scaled_bitmap(spriteImage, 0, 0, originalSizeX, originalSizeY, xPosition, yPosition, spritewidth, spriteHeight, 0);

				}
			}
			else {
				if (dissapeaarWhenInteractedWith) {
					if (!alreadyInteractedWith) {
						al_draw_scaled_bitmap(spriteImage, (64 * xTileStyleSheet), (64 * yTileStyleSheet), 64, 64, xPosition, yPosition, spritewidth, spriteHeight, 0);

					}
				}
				else {
					al_draw_scaled_bitmap(spriteImage, (64 * xTileStyleSheet), (64 * yTileStyleSheet), 64, 64, xPosition, yPosition, spritewidth, spriteHeight, 0);

				}

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
	 void interact(PlayerCharacter &player, ALLEGRO_EVENT_QUEUE* queue, int screenWidth, int screenHeight) {
		 // Breifcase
		 
		if (idOfInteractable == 1) {
			choosePokemon(player, queue, screenWidth, screenHeight);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}
		// Normal Potion
		else if (idOfInteractable == 2) {
			int amount = player.itemManager.getAmountOfItem(4) +1;
			player.itemManager.setAmountOfItem(4, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}

		// Super Potion
		else if (idOfInteractable == 3) {
			int amount = player.itemManager.getAmountOfItem(5) + 1;
			player.itemManager.setAmountOfItem(5, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}

		// Hyper Potion
		else if (idOfInteractable == 4) {
			int amount = player.itemManager.getAmountOfItem(6) + 1;
			player.itemManager.setAmountOfItem(6, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}

		// Poke ball
		else if (idOfInteractable == 5) {
			int amount = player.itemManager.getAmountOfItem(1) + 1;
			player.itemManager.setAmountOfItem(1, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}

		// Great ball
		else if (idOfInteractable == 6) {
			int amount = player.itemManager.getAmountOfItem(2) + 1;
			player.itemManager.setAmountOfItem(2, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}

		// Ultra ball
		else if (idOfInteractable == 7) {
			int amount = player.itemManager.getAmountOfItem(3) + 1;
			player.itemManager.setAmountOfItem(3, amount);
			isDisplayed = false;
			alreadyInteractedWith = true;
		}


		else if (idOfInteractable == 100) {
			
		}



		
	}

	 void healAllPokemon(PlayerCharacter& player) {
		 player.trainersParty[0].healPokemonToFull();
		 player.trainersParty[1].healPokemonToFull();
		 player.trainersParty[2].healPokemonToFull();
		 player.trainersParty[3].healPokemonToFull();
		 player.trainersParty[4].healPokemonToFull();
		 player.trainersParty[5].healPokemonToFull();
	 }



	 void choosePokemon(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue, int screenWidth, int screenHeight) {
		 double xMousePosition = 0;
		 double yMousePosition = 0;

		 // GUI info
		 bool done = false;
		 bool redraw = true;
		 ALLEGRO_EVENT event;

		 // BG sprite
		 ALLEGRO_BITMAP* background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/StarterBG.jpg");

		  //Reset the camera
		 ALLEGRO_TRANSFORM trans;
		 al_identity_transform(&trans);
		 al_use_transform(&trans);
		 //al_draw_bitmap(background, 0, 0, 0);

		 PokemonManager pm = pm.instance();

		 Pokemon pokemon1 = pm.getDefaultPokemon("Gible");
		 pokemon1.setPokemonsLevel(5);
		 Pokemon pokemon2 = pm.getDefaultPokemon("Dratini");
		 pokemon2.setPokemonsLevel(5);
		 Pokemon pokemon3 = pm.getDefaultPokemon("Bagon");
		 pokemon3.setPokemonsLevel(5);


		 ChoosePokemonButton pokemonOneButton = ChoosePokemonButton(pokemon1, 128, 128, 200, 30, 128, 128, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
		 ChoosePokemonButton pokemonTwoButton = ChoosePokemonButton(pokemon2, 128, 128, 385, 100, 128, 128, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
		 ChoosePokemonButton pokemonThreeButton = ChoosePokemonButton(pokemon3, 128, 128, 565, 30, 128, 128, "../LeytonFinalProjectC++/Sprites/MapSprites/ChoosePokemon.png");
			 
		

		 bool chosenPokemon = false;

		 while (!chosenPokemon) {

			 al_wait_for_event(queue, &event);

			 switch (event.type)
			 {
			 case ALLEGRO_EVENT_MOUSE_AXES:
				 xMousePosition = event.mouse.x;
				 yMousePosition = event.mouse.y;
				 break;
			 case ALLEGRO_EVENT_TIMER:


				 redraw = true;
				 break;

			 case ALLEGRO_EVENT_DISPLAY_CLOSE:
				 done = true;
				 chosenPokemon = true;
				 break;
			 case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

				 if (pokemonOneButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					 done = true;
					 player.addPokemon(pokemon1);
					 chosenPokemon = true;
				 }
				 else if (pokemonTwoButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					 done = true;
					 player.addPokemon(pokemon2);
					 chosenPokemon = true;
				 } else if (pokemonThreeButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					 done = true;
					 player.addPokemon(pokemon3);
					 chosenPokemon = true;
				 }
			  }
	
			 if (done)
				 break;

			 if (redraw && al_is_event_queue_empty(queue))
			 {
				 al_clear_to_color(al_map_rgb(0, 0, 0));
				 al_draw_scaled_bitmap(background, 0, 0, 321, 240, 0, 0, screenWidth, screenHeight, 0);
				 pokemonOneButton.drawSprite();
				 pokemonTwoButton.drawSprite();
				 pokemonThreeButton.drawSprite();
				 al_flip_display();
			 }
			 

		 }

		 pokemonOneButton.destroySprite();
		 pokemonTwoButton.destroySprite();
		 pokemonThreeButton.destroySprite();
		 
		 
			
	 }




};
