
#include <list>
#include "../Sprites/Interactable.h"
class InteractablesForMaps {

public:

	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		if (mapNumber == 1) {
			Interactable bf = Interactable(1, true, 220, 165, 15 * 32, 24 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			Interactable item = Interactable(2, true, 6 * 32, 5 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 15,0);
			interactbles.push_front(item);

			item = Interactable(5, true, 20 * 32, 22 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			item = Interactable(3, true, 18 * 32, 28 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 24, 0);
			interactbles.push_front(item);

			item = Interactable(5, true, 14 * 32, 44 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			item = Interactable(6, true, 14 * 32, 44 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			item = Interactable(6, true, 19 * 32, 56 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

		

			return interactbles;
		}
		else if (mapNumber == 11) {
			Interactable hi = Interactable(100, false, 220, 165, 6 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(hi);
			Interactable box = Interactable(101, false, 220, 165, 9 * 32, 2 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(box);
		}
		else if (mapNumber == 12) {
			Interactable buy = Interactable(102, false, 220, 165, 2 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(buy);
			Interactable sell = Interactable(103, false, 220, 165, 1 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(sell);

		}

		return  interactbles;

	}


};