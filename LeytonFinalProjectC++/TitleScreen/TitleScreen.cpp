#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class TitleScreen {

public:

	std::string name;

	ALLEGRO_BITMAP * dialgaBasic;
	ALLEGRO_BITMAP * dialgaGlowing;

	TitleScreen(int _screenWidth, int _screenHeight) {
		name = "Pokemon Shattered Prism";
		dialgaBasic = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/Dialga.png");
		dialgaGlowing = al_load_bitmap("../LeytonFinalProjectC++/Sprites/TitleScreenSprites/DialgaPulse.png");


	}



};