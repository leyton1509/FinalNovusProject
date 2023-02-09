
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/Button.h"

// Class to handle the title screen
class TitleScreen {

public:

	// Bitmap for the name of game
	ALLEGRO_BITMAP * pokemonText;
	// Bitmap for pokemon
	ALLEGRO_BITMAP * dialgaBasic;
	// Bitmap for pokemon glowing
	ALLEGRO_BITMAP * dialgaGlowing;
	// Bitmap for background
	ALLEGRO_BITMAP * background;
	// Button for creating new game
	Button newGameButton;
	// Button for loading game
	Button loadGameButton;
	// The current frame
	int currentFrame;
	// Width of screen
	int screenWidth;
	// Height of screen
	int screenHeight;
	// whether the screen has been clicked
	bool hasClicked;
	// Bool for if the screen has loaded the buttons
	bool hasLoadedButtons;

	TitleScreen(int _screenWidth, int _screenHeight){
		currentFrame = 0;
		pokemonText = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/PokemonTitle.png");
		dialgaBasic = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaNone.png");
		dialgaGlowing = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaPulse.png");
		background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/BackgroundTitle.jpg");
		screenWidth = _screenWidth;
		screenHeight = _screenHeight; 
		hasClicked = false;
		hasLoadedButtons = false;
	}

	

	void drawScreen() {
		if (hasClicked == false) {
			al_draw_scaled_bitmap(background, 0, 0, 728, 410, 0, 0, screenWidth, screenHeight, 0);
			al_draw_scaled_bitmap(pokemonText, 0, 0, 493, 225, screenWidth / 2 - screenWidth * 0.4, screenHeight * 0.1, screenWidth * 0.8, screenHeight * 0.4, 0);

			if (currentFrame >= 200) {
				al_draw_scaled_bitmap(dialgaGlowing, 0, 0, 600, 600, screenWidth * 0.3, screenHeight * 0.5, screenWidth / 1.9, screenHeight / 2, 0);
				currentFrame++;
				if (currentFrame > 210) {
					currentFrame = 0;
				}
			}
			else {
				al_draw_scaled_bitmap(dialgaBasic, 0, 0, 600, 600, screenWidth * 0.3, screenHeight * 0.5, screenWidth / 1.9, screenHeight / 2, 0);
				currentFrame++;
			}
		}
		else {
			if (hasLoadedButtons == false) {

				newGameButton = Button(281, 60, (screenWidth * 0.5 - screenWidth * 0.35), (screenHeight * 0.3), (screenWidth * 0.7), (screenHeight * 0.2), "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/NewGameButton.jpg");
				loadGameButton = Button(281, 60, (screenWidth * 0.5 - screenWidth * 0.35), (screenHeight * 0.6), (screenWidth * 0.7), (screenHeight * 0.2), "../LeytonFinalProjectC++/Sprites/TitleScreenSprites/LoadGameButton.jpg");
				background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/BackgroundTitle.jpg");
				hasLoadedButtons = true;

				al_destroy_bitmap(dialgaBasic);
				al_destroy_bitmap(dialgaGlowing);
				
			}

			al_draw_scaled_bitmap(background, 0, 0, 728, 410, 0, 0, screenWidth, screenHeight, 0);
			newGameButton.drawSprite();
			loadGameButton.drawSprite();
			//al_draw_scaled_bitmap(newGameButton.spriteImage, 0, 0, 281, 60, screenWidth * 0.5 - screenWidth * 0.35, screenHeight * 0.3, screenWidth * 0.7,  screenHeight * 0.2, 0);
			//al_draw_scaled_bitmap(loadGameButton.spriteImage, 0, 0, 281, 60, screenWidth * 0.5 - screenWidth * 0.35, screenHeight * 0.6, screenWidth * 0.7, screenHeight * 0.2, 0);
		}
		
	}

	int handleButtonClick(float mousePositionX, float mousePositionY) {
		if (hasLoadedButtons == true) {
			if (newGameButton.hasBeenClicked(mousePositionX, mousePositionY)){
				return 1;
			}
			if (loadGameButton.hasBeenClicked(mousePositionX, mousePositionY)) {
				return 2;
			}
		}
		return 0;
	}

	void destroyAllSprites() {
		 al_destroy_bitmap(pokemonText);
		 al_destroy_bitmap(background);
		 al_destroy_bitmap(newGameButton.spriteImage);
		 al_destroy_bitmap(loadGameButton.spriteImage);
	}



};