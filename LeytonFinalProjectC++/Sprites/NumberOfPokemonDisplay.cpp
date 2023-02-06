#include "../Pokemon/Pokemon.h"
#include <allegro5/allegro_primitives.h>

class NumberOfPokemonDisplay {

public:


	int startX;
	int startY;
	int radius;

	NumberOfPokemonDisplay(int _startX, int _startY, int _radius) {
		startX = _startX;
		startY = _startY;
		radius = _radius;
	}

	void drawDisplay(Pokemon party[]) {
		for (int i = 0; i < 6; i++)
		{
			
			party[i];
		}
	}


};