
#include <list>
#include "../Sprites/Interactable.h"

// Handles the getting of the interactbales for the map
class InteractablesForMaps {

public:

	// Gets the list of interactbales from the map number
	std::list<Interactable> getInteractablesForMap(int mapNumber) {
		std::list<Interactable> interactbles;

		// Map one has items e.g potion pokeball greatball
		if (mapNumber == 1) {
			// Breifcase for choosing pokemon
			Interactable bf = Interactable(1, true, 220, 165, 15 * 32, 24 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			// Potion
			Interactable item = Interactable(2, true, 6 * 32, 5 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 15,0);
			interactbles.push_front(item);

			// Pokeball
			item = Interactable(5, true, 20 * 32, 22 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			// Super potion
			item = Interactable(3, true, 18 * 32, 28 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 24, 0);
			interactbles.push_front(item);

			// Pokeball
			item = Interactable(5, true, 14 * 32, 44 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			// Great ball
			item = Interactable(6, true, 14 * 32, 44 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);
			// Great ball
			item = Interactable(6, true, 19 * 32, 56 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

		

			return interactbles;
		}
		// Items for the second map
		else if(mapNumber == 2)
		{
			Interactable bf = Interactable(1, true, 220, 165, 44 * 32, 73 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/MapSprites/Case.png");
			interactbles.push_front(bf);

			// Potion
			Interactable item = Interactable(2, true, 27 * 32, 41 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 15, 0);
			interactbles.push_front(item);

			//Poke ball
			item = Interactable(5, true, 22 * 32, 15 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 3, 0);
			interactbles.push_front(item);

			// Super potion
			item = Interactable(3, true, 25 * 32, 27 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 24, 0);
			interactbles.push_front(item);
			// Ultra ball
			item = Interactable(7, true, 40 * 32, 58 * 32, 32, 32, "../LeytonFinalProjectC++/Sprites/Items/Items.png", 1, 0);
			interactbles.push_front(item);


		
		}
		// Map 11 is for healing and the box of pokemon
		else if (mapNumber == 11) {
			Interactable hi = Interactable(100, false, 220, 165, 6 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(hi);
			Interactable box = Interactable(101, false, 220, 165, 9 * 32, 2 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(box);
		}
		// Map 12 is the poke mart so its the buy or sell menu
		else if (mapNumber == 12) {
			Interactable buy = Interactable(102, false, 220, 165, 2 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(buy);
			Interactable sell = Interactable(103, false, 220, 165, 1 * 32, 4 * 32, 0, 0, "../LeytonFinalProjectC++/Sprites/MapSprites/Heal.png");
			interactbles.push_front(sell);

		}

		return  interactbles;

	}


};