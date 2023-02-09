#include "gtest/gtest.h"
#include "../Pokemon/Moves/MoveManager.h"
// Class for testing pokemon move manager
class MoveManagerTests : public ::testing::Test
{

protected:
	MoveManager moveManager = moveManager.instance();
};

// Checks to see if the first move is loaded correctly
TEST_F(MoveManagerTests, CheckFirstMove) {
	Move testM = moveManager.getMoveDetails(1);
	ASSERT_EQ(testM.moveName, "Pound");
	ASSERT_EQ(testM.power, 40);
	ASSERT_EQ(testM.accuracy, 100);
	ASSERT_EQ(testM.powerpoints, 35);
	ASSERT_EQ(testM.typeOfMove,MoveCategory::Physical);
	ASSERT_EQ(testM.pokemonTypeOfMove, PokemonType::Normal);
}

// Checks to see if the first move is loaded correctly
TEST_F(MoveManagerTests, CheckSecondToLastMove) {
	Move testM = moveManager.getMoveDetails(466);
	ASSERT_EQ(testM.moveName, "Ominous Wind");
	ASSERT_EQ(testM.power, 60);
	ASSERT_EQ(testM.accuracy, 100);
	ASSERT_EQ(testM.powerpoints, 5);
	ASSERT_EQ(testM.typeOfMove, MoveCategory::Special);
	ASSERT_EQ(testM.pokemonTypeOfMove, PokemonType::Ghost);
}

// Checks to see if the last move is loaded correctly
TEST_F(MoveManagerTests, CheckoLastMove) {
	Move testM = moveManager.getMoveDetails(467);
	ASSERT_EQ(testM.moveName, "Shadow Force");
	ASSERT_EQ(testM.power, 120);
	ASSERT_EQ(testM.accuracy, 100);
	ASSERT_EQ(testM.powerpoints, 5);
	ASSERT_EQ(testM.typeOfMove, MoveCategory::Physical);
	ASSERT_EQ(testM.pokemonTypeOfMove, PokemonType::Ghost);
}