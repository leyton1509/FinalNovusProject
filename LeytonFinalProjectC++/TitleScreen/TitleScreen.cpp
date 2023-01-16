#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class TitleScreen {

public:

	std::string name;


	ALLEGRO_BITMAP * dialgaBasic;
	ALLEGRO_BITMAP * dialgaGlowing;
	ALLEGRO_BITMAP * background;



	TitleScreen(int _screenWidth, int _screenHeight) {
		name = "Pokemon Shattered Prism";
		dialgaBasic = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/Dialga.png");
		dialgaGlowing = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaPulse.png");
		background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/BackgrondTitle.jpg");
	}

	void drawFirstScreen() {
		al_draw_bitmap(background, 0, 0, 0);
		al_draw_bitmap(dialgaBasic, 0, 0, 0);
		al_draw_bitmap(dialgaGlowing, 0, 0, 0);

	}

	void drawSecondScreen() {

	}



};