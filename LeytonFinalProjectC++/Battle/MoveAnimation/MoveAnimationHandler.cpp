#include "../../Battle/MoveAnimation/MoveAnimation.h"
#include <list>

// Class to handle all move animation creation and finishing
class MoveAnimationHandler {


	std::list<MoveAnimation> animations = {};

	void startAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int _opponentPokemonX, int _opponentPokemonY) {
		MoveAnimation ani = MoveAnimation(_moveID, _playerPokemonX, _playerPokemonY,_opponentPokemonX, _opponentPokemonY);
		animations.push_back(ani);
	}

	void drawAnimation() {
		for (MoveAnimation& moveAni : animations)
		{
			moveAni.drawAnimation();
			if (moveAni.isAnimationFinished) {
				animations.remove(moveAni);
			}
			break;
		}
	}

	MoveAnimationHandler() {



	}
};