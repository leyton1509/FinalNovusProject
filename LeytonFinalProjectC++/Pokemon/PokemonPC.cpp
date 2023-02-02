#include "../Sprites/PlayerCharacter.h"

#include "../Sprites/SwitchPokemonButton.h"

class PokemonPC {

	SwitchPokemonButton boxButtons[30];

public:

	void destroySprites() {


		for (int i = 0; i < 30; i++)
		{			
			boxButtons[i].destroySprite();
		}
	}

	PokemonPC(PlayerCharacter & player, int screenWidth, int screenHeight) {

		int startXPositon = 10;
		int startYPosition = 10;
		int counter = 0;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				boxButtons[counter] = SwitchPokemonButton(64, 64, startXPositon + (i * 90), startYPosition + (j * 90), 80, 80);
				counter++;
			}

		}

	}
};