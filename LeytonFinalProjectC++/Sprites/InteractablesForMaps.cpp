
#include <list>
#include "../Sprites/Interactable.h"
class InteractablesForMaps {

public:

	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		if (mapNumber == 1) {
			Interactable bf = Interactable(1, true, 220, 165, 14 * 32, 21 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			return interactbles;
		}

		return  interactbles;

	}


};