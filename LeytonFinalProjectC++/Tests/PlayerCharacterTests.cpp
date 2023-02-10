#include "gtest/gtest.h"
#include "../Sprites/PlayerCharacter.h"
// Class for testing pokemon move manager
class PlayerCharacterTests : public ::testing::Test
{

protected:
	PlayerCharacter playerCharacter = PlayerCharacter();
};

// Checks to see if the players tile location is changed when moved
TEST_F(PlayerCharacterTests, CheckMoveW) {
	int beforeXLoc = playerCharacter.xTilePosition;
	int beforeYLoc = playerCharacter.yTilePosition;
	playerCharacter.directionX = 0;
	playerCharacter.directionY = 1;
	playerCharacter.moveCharacter("w");
	playerCharacter.updateTile();
	int afterXLoc = playerCharacter.xTilePosition;
	int afterYLoc = playerCharacter.yTilePosition;
	ASSERT_EQ(beforeXLoc, afterXLoc);
	ASSERT_EQ((beforeYLoc-1), afterYLoc);
}

// Checks to see if the players tile location is changed when moved
TEST_F(PlayerCharacterTests, CheckMoveS) {
	int beforeXLoc = playerCharacter.xTilePosition;
	int beforeYLoc = playerCharacter.yTilePosition;
	playerCharacter.directionX = 0;
	playerCharacter.directionY = -1;
	playerCharacter.moveCharacter("s");
	playerCharacter.updateTile();
	int afterXLoc = playerCharacter.xTilePosition;
	int afterYLoc = playerCharacter.yTilePosition;
	ASSERT_EQ(beforeXLoc, afterXLoc);
	ASSERT_EQ((beforeYLoc +1), afterYLoc);
}