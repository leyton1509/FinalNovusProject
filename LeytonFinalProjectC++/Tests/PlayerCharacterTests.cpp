#include "gtest/gtest.h"
#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/PokemonManager.h"
// Class for testing pokemon move manager
class PlayerCharacterTests : public ::testing::Test
{

protected:
	PlayerCharacter playerCharacter = PlayerCharacter();
	PokemonManager pm = pm.instance();
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

// Checks to see if the players rest method resets all vals
TEST_F(PlayerCharacterTests, CheckRestMethod) {
	playerCharacter.resetPlayer(10, 22);
	ASSERT_EQ(playerCharacter.xTilePosition, 10);
	ASSERT_EQ(playerCharacter.yTilePosition, 22);
	ASSERT_EQ(playerCharacter.state, 0);
	ASSERT_EQ(playerCharacter.currentFrame, 0);
	ASSERT_EQ(playerCharacter.xPosition, 10 * 32);
	ASSERT_EQ(playerCharacter.yPosition, 22 * 32);
}

// Test sell item method
TEST_F(PlayerCharacterTests, CheckBuyItem) {
	playerCharacter.playersMoney = 0;
	playerCharacter.itemManager.setAmountOfItem(1, 1);
	playerCharacter.sellItem(1, 100);
	ASSERT_EQ(playerCharacter.itemManager.getAmountOfItem(1), 0);
	ASSERT_EQ(playerCharacter.playersMoney, 100);

	playerCharacter.sellItem(1, 100);
	ASSERT_EQ(playerCharacter.itemManager.getAmountOfItem(1), 0);
	ASSERT_EQ(playerCharacter.playersMoney, 100);
}

// Test to see if adding pokemon works
TEST_F(PlayerCharacterTests, AddPokemon) {

	ASSERT_EQ(playerCharacter.trainersParty[0].pokemonName, "");

	playerCharacter.addPokemon(pm.getDefaultPokemon("Piplup"));

	ASSERT_EQ(playerCharacter.trainersParty[0].pokemonName, "Piplup");

	playerCharacter.addPokemon(pm.getDefaultPokemon("Shaymin"));

	ASSERT_EQ(playerCharacter.trainersParty[0].pokemonName, "Piplup");
	ASSERT_EQ(playerCharacter.trainersParty[1].pokemonName, "Shaymin");

	playerCharacter.addPokemon(pm.getDefaultPokemon("Darkrai"));
	playerCharacter.addPokemon(pm.getDefaultPokemon("Palkia"));
	playerCharacter.addPokemon(pm.getDefaultPokemon("Dialga"));
	playerCharacter.addPokemon(pm.getDefaultPokemon("Chimchar"));
	ASSERT_EQ(playerCharacter.trainersParty[5].pokemonName, "Chimchar");

	playerCharacter.addPokemon(pm.getDefaultPokemon("Groudon"));
	ASSERT_EQ(playerCharacter.box[0].pokemonName, "Groudon");

	playerCharacter.addPokemon(pm.getDefaultPokemon("Kyogre"));
	ASSERT_EQ(playerCharacter.box[1].pokemonName, "Kyogre");

}

TEST_F(PlayerCharacterTests, CalculatingNumberOfPokemon) {
}