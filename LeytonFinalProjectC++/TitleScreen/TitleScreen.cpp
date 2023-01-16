#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class TitleScreen {

public:

	std::string name;
	ALLEGRO_BITMAP * dialgaBasic;
	ALLEGRO_BITMAP * dialgaGlowing;
	ALLEGRO_BITMAP * background;

	int currentFrame = 0;
	int screenWidth;
	int screenHeight;

	TitleScreen(int _screenWidth, int _screenHeight) {
		name = "Pokemon Shattered Prism";
		dialgaBasic = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/Dialga.png");
		dialgaGlowing = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaPulse.png");
		background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/BackgroundTitle.jpg");
		screenWidth = _screenWidth;
		screenHeight = _screenHeight; 
	}

	void drawFirstScreen() {
		al_draw_scaled_bitmap(background, 0, 0, 728, 410, 0,0, screenWidth, screenHeight, 0);

		if (currentFrame >= 360) {
			al_draw_scaled_bitmap(dialgaGlowing, 0, 0, 600, 600, screenWidth * 0.5, screenHeight * 0.55, screenWidth / 1.9, screenHeight / 2, 0);
			if (currentFrame > 390) {
				currentFrame = 0;
			}
		}
		else {
			al_draw_scaled_bitmap(dialgaGlowing, 0, 0, 600, 600, screenWidth * 0.5, screenHeight * 0.55, screenWidth / 1.9, screenHeight / 2, 0);
			currentFrame++;
		}
		
	}

	void drawSecondScreen() {

	}



};