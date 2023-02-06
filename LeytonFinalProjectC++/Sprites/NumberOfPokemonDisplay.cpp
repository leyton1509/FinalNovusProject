#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_primitives.h>

// Displays the party info about what pokemon are dead
class NumberOfPokemonDisplay {

public:

	// The starting x of the pokeball display
	int startX;
	// The starting y of the pokeball display
	int startY;
	// The radius of each circle
	int radius;

	// Constructor that takes the position and size of the cricles
	NumberOfPokemonDisplay(int _startX, int _startY, int _radius) {
		startX = _startX;
		startY = _startY;
		radius = _radius;
	}

	// Draws the display based on the party
	// Draws a ligt grey circle
	// The draws a red circle if its alive, dark grey if its not and a little dot in the middle
	void drawDisplay(Pokemon party[]) {
		for (int i = 0; i < 6; i++)
		{
			int x = startX + (i * 30) + 10;
			al_draw_filled_circle(x, startY, radius, al_map_rgb(255, 255, 255));

			if (!(strcmp(party[i].pokemonName.c_str(), "") == 0)) {

				if (party[i].currentHealth > 0) {
					al_draw_filled_circle(x, startY, (radius * 0.), al_map_rgb(238, 64, 86));
				}
				else {
					al_draw_filled_circle(x, startY, (radius * 0.9), al_map_rgb(90, 90, 90));
				}
				al_draw_filled_circle(x, startY, (radius * 0.3), al_map_rgb(255, 255, 255));
			}

			
		}
	}


};