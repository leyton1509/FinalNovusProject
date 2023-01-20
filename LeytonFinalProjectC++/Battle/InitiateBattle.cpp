#include "../Sprites/PlayerCharacter.h"

class InitiateBattle {

public:

	InitiateBattle(ALLEGRO_EVENT_QUEUE* queue ,PlayerCharacter player, int locationNumber, int battleType) {

		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		bool batteFinished = false;

		if (battleType == 0) {
			// Wild encounter

			while (!batteFinished) {

				al_wait_for_event(queue, &event);

				switch (event.type)
				{

				}

			}

			

			



		}
		else if (battleType == 1) {
			// Pokemon encounter

		}

	}

};