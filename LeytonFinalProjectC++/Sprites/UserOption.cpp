#include <allegro5/allegro_font.h>

class UserOption {

public:

	// The font to write with
	ALLEGRO_FONT* font = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

	UserOption() {

	}
};