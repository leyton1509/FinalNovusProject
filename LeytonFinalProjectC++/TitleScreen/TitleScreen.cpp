
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class TitleScreen {

public:

	ALLEGRO_BITMAP * pokemonText;
	ALLEGRO_BITMAP * dialgaBasic;
	ALLEGRO_BITMAP * dialgaGlowing;
	ALLEGRO_BITMAP * background;

	int currentFrame;
	int screenWidth;
	int screenHeight;
	bool hasClicked;

	TitleScreen(int _screenWidth, int _screenHeight) {
		currentFrame = 0;
		pokemonText = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/PokemonTitle.png");
		dialgaBasic = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaNone.png");
		dialgaGlowing = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaPulse.png");
		background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/BackgroundTitle.jpg");
		screenWidth = _screenWidth;
		screenHeight = _screenHeight; 
		hasClicked = false;
	}

	

	void drawScreen() {
		if (hasClicked == false) {
			al_draw_scaled_bitmap(background, 0, 0, 728, 410, 0, 0, screenWidth, screenHeight, 0);
			al_draw_scaled_bitmap(pokemonText, 0, 0, 493, 225, 0, 0, screenWidth * 0.8, screenHeight * 0.4, 0);

			if (currentFrame >= 200) {
				al_draw_scaled_bitmap(dialgaGlowing, 0, 0, 600, 600, screenWidth * 0.3, screenHeight * 0.55, screenWidth / 1.9, screenHeight / 2, 0);
				currentFrame++;
				if (currentFrame > 210) {
					currentFrame = 0;
				}
			}
			else {
				al_draw_scaled_bitmap(dialgaBasic, 0, 0, 600, 600, screenWidth * 0.3, screenHeight * 0.55, screenWidth / 1.9, screenHeight / 2, 0);
				currentFrame++;
			}
		}
		else {



		}
		
	}




};