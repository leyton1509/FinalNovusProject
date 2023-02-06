
// A class to control a single move animation
class MoveAnimation{

	// The id of the move
	int moveID;
	// The current frame of the animation
	int currentFrame;
	// The starting X position of the animation
	int startX;
	// The starting X position of the animation
	int startY;
	// The destination X position of the animation
	int destinationX;
	// The destination Y position of the animation
	int destinationY;
	// The state of the animation
	int state;
	// The xtile for the style sheet
	int xTileForStyleSheet;
	// The ytile for the style sheet
	int yStileForSyleSheet;
	// If the animation is finished
	bool isAnimationFinished;

	// Some moves go from player pokemon to opponent, some just loop through at the opponent
	bool isStartDestination(int moveID) {
		return false;
	}

	// Default creation of move animation
	MoveAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int _opponentPokemonX, int _opponentPokemonY){
	
		moveID = _moveID;
		if (isStartDestination(moveID)) {
			startX = _opponentPokemonX;
			startY = _opponentPokemonY;
			destinationX = _opponentPokemonX;
			destinationY = _opponentPokemonY;
		}
		else {
			startX = _playerPokemonX;
			startY = _playerPokemonY;
			destinationX = _opponentPokemonX;
			destinationY = _opponentPokemonY;
		}
		state = 0;
		currentFrame = 0;
		xTileForStyleSheet = 0;
		yStileForSyleSheet = 0;
		isAnimationFinished = false;
	}
};