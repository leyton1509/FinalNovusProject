
// A class to control a single move animation
class MoveAnimation {

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

	// Some moves go from player pokemon to opponent, some just loop through at the opponent
	bool isStartDestination(int moveID) {

	}

	// Default creation of move animation
	MoveAnimation(int _moveID, int _playerPokemonX, int _playerPokemonY, int opponentPokemonX, int opponentPokemonY) {
		moveID = _moveID;
	}
};