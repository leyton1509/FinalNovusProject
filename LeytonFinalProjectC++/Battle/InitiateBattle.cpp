#include "../Sprites/PlayerCharacter.h"

class InitiateBattle {

public:

	InitiateBattle(ALLEGRO_EVENT_QUEUE* queue ,PlayerCharacter player, int locationNumber, int battleType) {

		bool done = false;
		bool redraw = true;
		ALLEGRO_EVENT event;

		bool battleFinished = false;

		if (battleType == 0) {
			// Wild encounter

			while (!battleFinished) {

				al_wait_for_event(queue, &event);

				switch (event.type)
				{
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					done = true;
					break;
				}

				if (done)
					break;

				if (redraw && al_is_event_queue_empty(queue))
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));

					al_flip_display();
					redraw = false;
				}

			}
		}

		
		else if (battleType == 1) {
			// Pokemon encounter

		}

	}

};