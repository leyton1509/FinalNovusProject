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

// Checks to see if the players tile location is changed when moved
TEST_F(PlayerCharacterTests, CheckMoveD) {
	int beforeXLoc = playerCharacter.xTilePosition;
	int beforeYLoc = playerCharacter.yTilePosition;
	playerCharacter.directionX = 1;
	playerCharacter.directionY = 0;
	playerCharacter.moveCharacter("d");
	playerCharacter.updateTile();
	int afterXLoc = playerCharacter.xTilePosition;
	int afterYLoc = playerCharacter.yTilePosition;
	ASSERT_EQ((beforeXLoc + 1), afterXLoc);
	ASSERT_EQ(beforeYLoc, afterYLoc);
}

// Checks to see if the players tile location is changed when moved
TEST_F(PlayerCharacterTests, CheckMoveA) {
	int beforeXLoc = playerCharacter.xTilePosition;
	int beforeYLoc = playerCharacter.yTilePosition;
	playerCharacter.directionX = -1;
	playerCharacter.directionY = 0;
	playerCharacter.moveCharacter("a");
	playerCharacter.updateTile();
	int afterXLoc = playerCharacter.xTilePosition;
	int afterYLoc = playerCharacter.yTilePosition;
	ASSERT_EQ((beforeXLoc -1), afterXLoc);
	ASSERT_EQ(beforeYLoc, afterYLoc);
}