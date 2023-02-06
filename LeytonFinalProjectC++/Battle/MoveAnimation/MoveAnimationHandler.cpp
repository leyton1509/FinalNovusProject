#include "../../Battle/MoveAnimation/MoveAnimation.h"
#include <list>

// Class to handle all move animation creation and finishing
class MoveAnimationHandler {

public :
	// A list of all move animations in order
	std::list<MoveAnimation> animations = {};


	// Adds an animation to the list
	void startAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int _opponentPokemonX, int _opponentPokemonY, int _opponentPokemonNum, int _playerPokemonNum) {
		MoveAnimation ani = MoveAnimation(_moveID, _playerPokemonX, _playerPokemonY,_opponentPokemonX, _opponentPokemonY, _opponentPokemonNum, _playerPokemonNum);
		animations.push_back(ani);
	}

	// Returns true if the list is empty
	bool finishedAllAnimations() {
		for (MoveAnimation& moveAni : animations)
		{
			return false;
		}
		return true;
	}

	// Draws the first animation in the list
	void drawAnimation() {

		bool isFinished = false;
		for (MoveAnimation& moveAni : animations)
		{
			moveAni.drawAnimation();
			isFinished = moveAni.isAnimationFinished;
			break;
		}
		
		if (isFinished) {
			animations.pop_front();
		}
	}

	// Constructor
	MoveAnimationHandler() {



	}
};