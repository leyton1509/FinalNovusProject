#include "gtest/gtest.h"
#include "../Pokemon/PokemonManager.h"
// Class for testing pokemon manager
class PokemonManagerTests : public ::testing::Test
{

protected:
	PokemonManager pokemonManager = pokemonManager.instance();
};


// Checks to see if the first pokemon is loaded correctly
TEST_F(PokemonManagerTests, CheckFirstPokemon) {
	Pokemon testP =  pokemonManager.getDefaultPokemon("Bulbasaur");
	ASSERT_EQ(testP.pokemonName, "Bulbasaur");
	ASSERT_EQ(testP.level,1);
	testP.setPokemonsLevel(5);
	ASSERT_EQ(testP.level, 5);
	ASSERT_EQ(testP.healthBase, 45);
	ASSERT_EQ(testP.physcialAttackBase, 49);
	ASSERT_EQ(testP.physicalDefenceBase, 49);
	ASSERT_EQ(testP.specialAttackBase, 65);
	ASSERT_EQ(testP.specialDefenceBase, 65);
	ASSERT_EQ(testP.speedBase, 45);
}

// Checks to see if the second to last pokemon is loaded correctly
TEST_F(PokemonManagerTests, CheckSecondToLastPokemon) {
	Pokemon testP = pokemonManager.getDefaultPokemon("Shaymin");
	ASSERT_EQ(testP.pokemonName, "Shaymin");
	ASSERT_EQ(testP.level, 1);
	testP.setPokemonsLevel(15);
	ASSERT_EQ(testP.level, 15);
	ASSERT_EQ(testP.healthBase, 100);
	ASSERT_EQ(testP.physcialAttackBase, 100);
	ASSERT_EQ(testP.physicalDefenceBase, 100);
	ASSERT_EQ(testP.specialAttackBase, 100);
	ASSERT_EQ(testP.specialDefenceBase, 100);
	ASSERT_EQ(testP.speedBase, 100);
}

// Checks to see if the last pokemon is loaded correctly
TEST_F(PokemonManagerTests, CheckToLastPokemon) {
	Pokemon testP = pokemonManager.getDefaultPokemon("Arceus");
	ASSERT_EQ(testP.pokemonName, "Arceus");
	ASSERT_EQ(testP.level, 1);
	testP.setPokemonsLevel(15);
	ASSERT_EQ(testP.level, 15);
	ASSERT_EQ(testP.healthBase, 120);
	ASSERT_EQ(testP.physcialAttackBase, 120);
	ASSERT_EQ(testP.physicalDefenceBase, 120);
	ASSERT_EQ(testP.specialAttackBase, 120);
	ASSERT_EQ(testP.specialDefenceBase, 120);
	ASSERT_EQ(testP.speedBase, 120);
}

// Checks to see if the first pokemon is loaded correctly
TEST_F(PokemonManagerTests, CheckBaseStatisticCalc) {
	Pokemon testP = pokemonManager.getDefaultPokemon("Bulbasaur");
	testP.setPokemonsLevel(5);
	
	ASSERT_GT(testP.healthActual, 19);
	ASSERT_LT(testP.healthActual, 22);

	ASSERT_GT(testP.physcialAttackActual, 9);
	ASSERT_LT(testP.physcialAttackActual, 12);

	ASSERT_GT(testP.physicalDefenceActual, 9);
	ASSERT_LT(testP.physicalDefenceActual, 12);

	ASSERT_GT(testP.specialAttackActual, 11);
	ASSERT_LT(testP.specialAttackActual, 14);

	ASSERT_GT(testP.specialDefenceActual, 11);
	ASSERT_LT(testP.specialDefenceActual, 14);

	ASSERT_GT(testP.speedActual, 9);
	ASSERT_LT(testP.speedActual, 12);
	
	
}

// Checks to see if experience is dependent on level
TEST_F(PokemonManagerTests, ExperienceGainCalc) {

	Pokemon defeatedP = pokemonManager.getDefaultPokemon("Charizard");
	defeatedP.setPokemonsLevel(10);
	int expBefore = defeatedP.experienceUponKill();
	defeatedP.setPokemonsLevel(11);
	int expAfter = defeatedP.experienceUponKill();

	ASSERT_GT(expAfter, expBefore);
}

// Checks to see if pokemon levels up
TEST_F(PokemonManagerTests, ExperienceGainedCheck) {
	Pokemon testP = pokemonManager.getDefaultPokemon("PipLup");
	Pokemon defeatedP = pokemonManager.getDefaultPokemon("Charizard");
	defeatedP.setPokemonsLevel(11);
	int exp = defeatedP.experienceUponKill();

	int levelBefore = testP.level;
	testP.gainExperience(exp);
	int levelAfter = testP.level;

	ASSERT_GT(levelAfter, levelBefore);
}