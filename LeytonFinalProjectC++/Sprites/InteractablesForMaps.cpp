
#include <list>
#include "../Sprites/Interactable.h"
class InteractablesForMaps {

public:

	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		if (mapNumber == 1) {
			Interactable bf = Interactable(1, true, 220, 165, 15 * 32, 24 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			//Interactable potion = Interactable(2, true, 15 * 32, 22 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 15,0);
			//interactbles.push_front(potion);

			//Interactable superPotion = Interactable(3, true, 15 * 32, 20 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 24, 0);
			//interactbles.push_front(superPotion);

			//Interactable pokeball = Interactable(5, true, 15 * 32, 20 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			//interactbles.push_front(pokeball);

			return interactbles;
		}
		else if (mapNumber == 11) {
			Interactable hi = Interactable(100, false, 220, 165, 5 * 32, 4 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(hi);
		}

		return  interactbles;

	}


};