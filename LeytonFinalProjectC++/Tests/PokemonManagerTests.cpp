#include "gtest/gtest.h"
#include "../Pokemon/PokemonManager.h"
class PokemonManagerTests : public ::testing::Test
{

protected:
	PokemonManager pokemonManager = pokemonManager.instance();


};



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