
#include <list>
#include "../Sprites/Interactable.h"
class InteractablesForMaps {

public:

	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		if (mapNumber == 1) {
			Interactable bf = Interactable(1, true, 220, 165, 15 * 32, 24 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			Interactable bf = Interactable(2, true, 15 * 32, 22 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 0,0);
			interactbles.push_front(bf);

			return interactbles;
		}

		return  interactbles;

	}


};