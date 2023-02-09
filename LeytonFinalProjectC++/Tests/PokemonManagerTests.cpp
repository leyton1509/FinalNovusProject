#include "gtest/gtest.h"
#include "../Pokemon/PokemonManager.h"
class PokemonManagerTests : public ::testing::Test
{

protected:
	PokemonManager pokemonManager = pokemonManager.instance();


};


TEST_F(PokemonManagerTests, CheckPokemonManagerInstance) {
	ASSERT_NE(pokemonManager, NULL);
}
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