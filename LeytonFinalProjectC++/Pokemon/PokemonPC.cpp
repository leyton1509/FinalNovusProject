#include "../Sprites/PlayerCharacter.h"

#include "../Sprites/SwitchPokemonButton.h"

class PokemonPC {

	SwitchPokemonButton boxButtons[6][5];

public:

	PokemonPC(PlayerCharacter & player, int screenWidth, int screenHeight) {

		int startXPositon = 10;
		int startYPosition = 10;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{

				boxButtons[i][j] = SwitchPokemonButton(64, 64, startXPositon + (i * 90), startYPosition + (j * 90), 80, 804);

			}

		}

	}
};