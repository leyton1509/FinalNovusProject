
#include <list>
#include "../Sprites/Interactable.h"
#include "../Sprites/Breifcase.h"
class InteractablesForMaps {

public:

	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		if (mapNumber == 1) {
			Breifcase bf = Breifcase(220, 165, 14 * 32, 21 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			return interactbles;
		}

		return  interactbles;

	}


};